
//һ������,�������ظ������ֶ���һ����n*(n-1)/2��
//�����������ֶ�֮��,�����ֵ����ֵ,����֮���ҵ���K����С������
//O(n^2)��û������,Ӧ������ΪO(n*logn)
//���ֱ�����ɲ�ֵ����,��ô���Ѿ���o(n^2)��
//��ԭ��������֮��,�������ֶԲ�ֵ���ľ���maxVal-minVal,��ô���е���ֵ�Բ�ֵ��Сһ����
//1~maxVal-minVal֮��,Ѱ�ҵ�����,<=5�ĸ�����a��,<=50�ĸ�����b��,��ôa<=b��Ȼ����
//��ô����Ѱ��keyֵ,�鿴С��key�����ֶԸ���һ���ж��ٸ�,������x��,
//if x> k,˵��keyֵ������,��Ҫ��minVal,key-1������Ѱ���µ�keyֵ,��������
//else if x<k,˵����Ҫ��key+1,maxVal�����м�������
//https://www.bilibili.com/video/BV1NV4y1B7ZZ?t=444.8&p=71
//��ʵ���ֵ����ֶԲ�ֵ��Ȼ��1~maxVal-minVal֮��,���ǿ���û������,Ҳ������ͬ��ֵ�ظ�����
//����ͨ���������ּ�¼����С�ڵ���key����ֵ�Դ����۲�õ�
//count[x] < k,count[x+1]>k ,��ô�����ֵ����x+1
//���ֵĹ����в���count[x]<=k��������ͬx����ҵ��Ǹ�x,�𰸾���x+1��ֵ
//������Ҫʵ��func()�õ�С�ڵ���keyֵ�ĸ����ж��ٸ�,
//ʹ��˫ָ�벻���˵ķ�ʽ����õ����ֶԸ���,ʵ��ʱ�临�Ӷ�Ϊo(N)
//֮ǰ���ֵ�ʱ�临�Ӷ�ΪO(log(maxVal-minVal))
//�����ܵ�ʱ�临�Ӷ�ΪO(log(maxVal-minVal) * N)
//�������,���ֵ����ͬ,��ֵ����0,��kС����֮��������,��n��,����Ӧ���Ƿ���0,���Գ�ʼ��Ϊ-1

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class MinKthPairMinusABS
{
public:
	//�����ķ�ʽ�������ɲ�ֵ����,����,�ó���k��,ȡֵʱע���±�Ӧ����k-1
	int kthAbsSub1(vector<int>& arr, int k)
	{
		int n = arr.size();
		int m = (n * (n - 1)) >> 1;
		if (m == 0 || k<1 || k>m)
			return -1;
		vector<int>count(m);
		int size = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = i + 1; j < n; j++)
			{
				count[size++] = abs(arr[i] - arr[j]);
			}
		}
		sort(count.begin(), count.end());
		return count[k - 1];
	}
public:
	int kthAbsSub2(vector<int>& arr, int k)
	{
		int n = arr.size();
		if (n < 2 || k<1 || k>((n * (n - 1)) >> 1))
			return -1;
		sort(arr.begin(), arr.end());
		// int left = 0, right = arr[n - 1] - arr[0];
		long long left = 0, right = arr[n - 1] - arr[0];
		int mid = 0;
		int rightest = -1;
		while (left <= right)
		{
			// mid = left + (right - left)/2;
			mid = (left + right) / 2;
			//func()�������ֶԲ�ֵС�ڵ���mid�����ֶԵĸ����Ƿ�<k��
			if (func(arr, mid, k))
			{
				rightest = mid;
				left = mid + 1;
			}
			else
			{
				right = mid - 1;
			}
		}
		return rightest + 1;
	}
	bool func(vector<int>& arr, int limit, int k)
	{
		int x = 0;
		for (int l = 0, r = 1; l < arr.size(); r = max(r, ++l))
		{
			while (r < arr.size() && arr[r] - arr[l] <= limit)
				r++;
			x += r - l - 1;
		}
		return x < k;
	}
};
vector<int> randArr(int n, int val)
{
	vector<int>ans(n);
	for (int i = 0; i < n; i++)
	{
		ans[i] = rand() % val;
	}
	return ans;
}
void test()
{
	int size = 100;//��������Ĵ�С�����100������
	int value = 100;//���ɵ�������ֵ��Χ��1~value֮��
	int testTime = 10000;
	//���Դ���,����ֻ�������40��,�������ͻ���ֹ,����.
	//����gdb���Է�������113�����kֵʱ����%0����,������Ҫ��������m��ֵ
	MinKthPairMinusABS s;
	cout << "���Կ�ʼ" << endl;
	for (int i = 0; i < testTime; i++)
	{
		int n = rand() % size + 1;
		int m = ((n * (n - 1)) / 2);
		if (m == 0)
			continue;

		int k = (rand() % m) + 1;
		vector<int>arr = randArr(n, value);
		vector<int>tmp(arr);
		int ans1 = s.kthAbsSub1(arr, k);
		int ans2 = s.kthAbsSub2(tmp, k);
		if (ans1 != ans2)
		{
			cout << "������" << endl;
			cout << "k:" << k << endl;
			cout << "ans1:" << ans1 << endl;
			cout << "ans2:" << ans2 << endl;
			break;
		}
	}
	cout << "���Խ���" << endl;
}
//int main()
//{
//	test();
//	// system("pause");
//	return 0;
//}