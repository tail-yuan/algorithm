//��һ������������,������ۼӺ�<=0����С�����Ƕ���
//opt1: ʲô������,������0
//opt2: ������ֱ�ӱ�Ϊ0,������x
//opt3: �����ֱ���෴��,������y

//�����ҵĳ���ģ��,arr[i....]֮����ۼӺ�Ϊrestʱ����С�����Ƕ���
//���sum�ܴ�,�����ʽ�ͷ���

//̰��:
//1. Ŀ�������ۼӺ�<=0,��ĳһ������=0��x����,��ɸ���������y,���x>y,��ȫû��Ҫʹ��x����,ֱ��y����
//Ŀ������<=0,��������,x��sum��С�̶�С,���Ǵ��۸�,������ȫû��Ҫ.
//2. �϶�������ʹ��y,��ʹ��x,��ʲô������ 
// ���x<y,������indexλ��ʱ�;�������y������,��ô֮������в�������Ӧ����ʹ��y��,
//	��֤: ��Ȼ֮����Ȼ����ʹ��y����,��Ϊʲô�����ۼӺ͸����ʱ��ʹ����?
// ͬ��,������ĳ��λ�ò���ʹ��x����ʱ,����Ķ���Ӧ����ʹ��x������
//���ھ͵��˲�������index�Ķϵ�? ������
//�������ϵ���ʵ������Ϊ0,��Ϊ���Դ���ֻʹ��x��������ֻʹ��y����
//���,[1]ʹ��y������Ϊ����,[2]ʹ��x��������Ϊ0,[3]ʲô������,���[1]�ĸ�����>[3],���۾���[1]*y+[2]*x
//��������ѭ��,�������жϵ㳢�����,һ�����ҵ�[1]>[3]�������ϵ�����С�Ĵ���

//�Ż�:��Ҫ���㽵������,̰��
//��ʼ��������[1]>[3]ʱ,[3]������ڵ�������,Ϊ�ľ�����[1]�����ĸ���ƽ��[3]ʣ�µ�����,
//����ֻ��Ҫһ�α���,����[1]�������С,Ȼ�����[3]�ĺ�׺�͵�����ڵ�,С�ڵ���sum1��[3]����
//������[1]�ϵ�������,�ҵ���С�Ĵ��ۼ���.
//����ʹ�ú�׺�ͽ����Ż�,���ֲ���
//[9,6,3,2,2,2,1,1,1]
//case 1: 9����y����->-9,2 2 2 1 1 1 �ۼӺ�Ϊ9,��ô6 3 ֱ��x������Ϊ0����
//case 2: 9 6ʹ��y����,����ʲô�����ø���,
//...
//min_case()
//�����ͺ����ݴ�Сû��ϵ��
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution2
{
public:
	int getMin(vector<int>& arr, int x, int y)
	{
		sort(arr.begin(), arr.end(), greater<int>());//�Ӵ�С����
		int n = arr.size();
		if (x >= y)
		{
			int sum = 0;
			for (auto e : arr)
				sum += e;
			int ret = 0;
			for (int i = 0; i < n && sum>0; i++)
			{
				sum -= 2 * arr[i];
				ret += y;
			}
			return ret;
		}
		else
		{
			//��arrֱ�Ӹ�ֵΪ��׺������
			for (int i = n - 2; i >= 0; i--)
			{
				arr[i] += arr[i + 1];
			}
			int benefit = 0;
			int left = mostLeft(arr,0,benefit);//ִ��Y����������Ϊ0��ʱ
			int cost = left * x;
			for (int i = 0; i < n - 1; i++)
			{
				benefit += arr[i] - arr[i + 1];//��Ϊ���ڵ�arr����ʱ��׺��,��ȡiλ��ԭֵ�������
				left = mostLeft(arr, i + 1, benefit);
				cost = min(cost, (i + 1) * y + (left - i - 1) * x);//��¼�����������Сֵ		
			}
			return cost;
		}
	}
	//��[l,n-1]�������ҵ�<=val��λ��,���з���
	int mostLeft(vector<int>& arr, int l, int val)
	{
		int n = arr.size();
		int r = n - 1;
		int ans = n;//��������������,Ҳ�Ͳ��ᱻ����,�ͷ���n
		while (l <= r)
		{
			int mid = l + (r - l) / 2;
			if (arr[mid] > val)
				l = mid + 1;
			else
			{
				ans = mid;
				r = mid - 1;
			}
		}
		return ans;
	}
	int mostLeft1(vector<int>& arr, int l, int val)
	{
		int n = arr.size();
		int r = arr.size() - 1;
		while (l < r)
		{
			int mid = l + (r - l) / 2;
			if (arr[mid] > val)
				l = mid + 1;
			else
				r = mid;
		}
		//���������Χ���ǲ�����,����n
		if (l == n - 1)
			l = n;
		return l;
	}
};
class Solution
{
	int x, y;
	int n;
public:
	int getMin(vector<int>& arr, int _x, int _y)
	{
		x = _x;
		y = _y;
		n = arr.size();
		int sum = 0;
		for (auto e : arr)
		{
			sum += e;
		}
		return zuo(arr, 0, sum);
	}
	int zuo(vector<int>&arr,int index,int rest)
	{
		if (rest <= 0)
			return 0;
		if (index == n)
			return INT_MAX;
		int p1 = zuo(arr, index + 1, rest);
		int p2 = INT_MAX;
		int ret2 = zuo(arr, index + 1, rest - arr[index]);
		if (ret2 != INT_MAX)
			p2 = ret2+x;
		int p3 = INT_MAX;
		int ret3 = zuo(arr, index + 1, rest - 2 * arr[index]);
		if (ret3 != INT_MAX)
			p3 = ret3 + y;
		return min(p1, min(p2, p3));
	}
};
/*
int main()
{
	vector<int>arr{1,4,5,6,0,7,3,2};
	sort(arr.begin(), arr.end(), greater<int>());

	return 0;
}
*/