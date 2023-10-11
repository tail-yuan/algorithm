//��������,arr[i]��ʾi����Ŀ���Ѷ���arr[i],�Ѷ�һ�����Ǳ�Ų�һ��
//������ʱ�κ����ڵ�������
// ǰ������ѶȲ��ܳ���������Ŀ���Ѷ�+M,���Ǻ���ľ��ӵ��Ѷȿ��Դ���ǰ����Ŀ���Ѷ�
//�ʿ��Գ������źϷ��ľ���
// 
//indexTree�ṩ��������,log(N)����
//add(index,val) sum(index)
//
//��(0,i)������,��ǰi����Ŀ��ʹ����һ���ж����ֺϷ��ľ���,����֮��,
//����,����iλ��ʱ,�³��ֵ���Ŀ������,û�а취��֮ǰ����֮���Ѿ����Ϸ��ľ��ӱ�Ϸ�
// ���������Ϳ��ܳ���,�����һ��������֮ǰ�������Ϸ������,����һ��ֵ������ĳһλ��֮���Ϸ���.
//���Ծ�ֻ��Ҫ��עǰi����Ŀ�����Ѿ��Ϸ������,
//����[0,i]��a�׺Ϸ��ľ���,����iλ����������Ŀ֮������
//1. �������,������Ȼ�Ϸ�,��ô�����γ�a�׾���
//2. ������󲻺Ϸ�,���Ҿ͵�[0,i]������Ѱ��>=[i]-M������һ����x��,�������λ��֮ǰ�Ϳ����γ�һ���µľ���
//һ�������γ�x*a�׾���
//���������ǰ���Ҵ��ڵ���y�ĸ����ж��ٸ��ܸ�Ч�ͺ�ˬ,
//indexTree�ṩ����С�ڵ���ĳ�����ĸ�����z��,��i-z�õ��ľ���y

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution
{
	class IndexTree
	{
	private:
		vector<int>tree;
		int n;
	public:
		IndexTree(int sz)
		{
			n = sz;
			tree = vector<int>(sz);
		}
		int sum(int index)
		{
			int ret = 0;
			while (index > 0)
			{
				ret += tree[index];
				index -= index & -index;
			}
			return ret;
		}
		void add(int index, int d)
		{
			while (index <= n)
			{
				tree[index] += d;
				index += index & -index;
			}
		}
	};
public:
	int ways(vector<int>& arr, int m)
	{
		if (arr.size() == 0)
			return 0;
		int maxv = INT_MAX;
		int minv = INT_MIN;
		for (auto e : arr)
		{
			maxv = max(maxv, e);
			minv = min(minv, e);
		}
		IndexTree it(maxv-minv+2);
		sort(arr.begin(), arr.end());
		int a = 0;
		int b = 0;
		int all = 1;
		it.add(arr[0]-minv+1,1);
		for (int i = 1; i < arr.size(); i++)
		{
			a = arr[i] - minv + 1;
			b = i - (a - m - 1 >= 1 ? it.sum(a - m - 1) : 0);
			all = all * (b+1);
			it.add(a, 1);
		}
		return all;
	}
};
//����һ,������е�ȫ������֤�Ƿ���ȷ
class Solution
{
	int n, m;
public:
	int ways(vector<int>& arr,int _m)
	{
		if (arr.size() == 0)
			return 0;
		m = _m;
		n = arr.size();
		return dfs(arr, 0);
	}
	int dfs(vector<int>& arr, int index)
	{
		if (index == n )
		{
			for (int i = 1; i < index; i++)
			{
				if (arr[i - 1] > arr[i] + m)
					return 0;
			}
			return 1;
		}
		//ȫ����
		int ans = 0;
		for (int i = index; i < n; i++)
		{
			swap(arr[i], arr[index]);
			ans += dfs(arr, i + 1);
			swap(arr[i], arr[index]);
		}
		return ans;
	}
};
int main()
{
	int i = 10;
	cout << (i & -i) << endl;//ʵ��ȥ�������������һ��1��Ч��
	vector<int>arr(12, 1);
	int ret = 0;
	while (i > 0)
	{
		ret+=arr[i];
		i -= i & -i;
	}
	cout << ret << endl;
	return 0;
}