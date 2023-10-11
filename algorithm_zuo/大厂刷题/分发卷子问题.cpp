//给定数字,arr[i]表示i号题目的难度是arr[i],难度一样但是标号不一样
//出卷子时任何相邻的两道题
// 前面题的难度不能超过后面题目的难度+M,但是后面的卷子的难度可以大于前面题目的难度
//问可以出多少张合法的卷子
// 
//indexTree提供两个方法,log(N)级别
//add(index,val) sum(index)
//
//在(0,i)区间上,把前i种题目都使用完一共有多少种合法的卷子,排序之后,
//首先,到达i位置时,新出现的题目添加与否,没有办法让之前排序之后已经不合法的卷子变合法
// 如果不排序就可能出现,新添加一个数导致之前本来不合法的情况,插入一个值在区间某一位置之后变合法了.
//所以就只需要关注前i种题目排列已经合法的情况,
//假设[0,i]有a套合法的卷子,考虑i位置添加这个题目之后的情况
//1. 放在最后,发现仍然合法,那么可以形成a套卷子
//2. 放在最后不合法,那我就到[0,i]区间中寻找>=[i]-M的数字一共有x个,放在这个位置之前就可以形成一套新的卷子
//一共可以形成x*a套卷子
//所以如果向前查找大于等于y的个数有多少个很高效就很爽,
//indexTree提供的是小于等于某个数的个数有z个,用i-z得到的就是y

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
//方法一,搞出所有的全排列验证是否正确
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
		//全排列
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
	cout << (i & -i) << endl;//实现去掉二进制中最后一个1的效果
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