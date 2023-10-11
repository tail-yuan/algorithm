#include<iostream>
#include<vector>
using namespace std;
//在一个数组中,有多少个子数组中包含的数字种数-------正好是K种
//暴力做法就是两层for循环,统计满足条件的子数组个数O(n^2)
//优化为滑动窗口的方式,因为是统计子数组的个数,如果在第k种时有重复数字的出现
//为了方便统计词频,需要使用两个窗口来维护
//需要两张表,一张记录k-1种数字的窗口中<数字种数,对应次数>以及leftIndex1位置,另一张表是K种的
//1. 同时右扩,将r位置数字放到两张表中,
//2. 当k-1窗口出现k种数字时,弹左窗口一直弹到k-1种,此时记录leftIndex1,
//	 同理当K窗口出现k+1中数字时,弹左窗口一直到K种,记录leftIndex2,
//	此时满足条件的子数组个数就是l1-l2
//
//题目给定: 数组中出现的数字不会超过数组的长度,所以可以直接开辟数组进行词频统计,不用哈希表了
// https://www.bilibili.com/video/BV1NV4y1B7ZZ?p=68&vd_source=cc945ef88574fe2db5e814c0c265a4c7
class Solution
{
public:
	int subArrWithKKindsNum(vector<int>& arr,int k)
	{
		int n = arr.size();
		vector<int>lessMap(n,0);
		vector<int>KMap(n,0);
		int kind1 = 0, kind2 = 0;
		int l1 = 0, l2 = 0;
		int ans = 0;
		for (int r = 0; r < n; r++)
		{
			//发现r位置数字是新出现的字符
			if (lessMap[arr[r]] == 0)
				kind1++;
			if (KMap[arr[r]] == 0)
				kind2++;

			lessMap[arr[r]]++;
			KMap[arr[r]]++;

			while (kind1 == k)
			{
				if (lessMap[arr[l1]] == 1)
					kind1--;
				lessMap[arr[l1++]]--;
			}
			while (kind2 > k)
			{
				if (KMap[arr[l2]] == 1)
					kind2--;
				KMap[arr[l2++]]--;
			}
			ans += l1 - l2;
		}
		return ans;
	}
};
//在数组中有多少种子数组的数字种树<=K种,有多少种小于等于k-1种,二者相减就是
//有多少个子数组的数字种数恰好为k种.
//Func函数提供这种功能,就是很简单的窗口问题了
//以r位置为结尾的子数组个数有[0,0][0,1][0,2][0,3]...[0,k],一共是k-0+1
//l++后就是r-l+1种
#include<unordered_map>
class Solution2
{
public:
	int subArrWithKKindsNum(vector<int>& arr, int k)
	{
		return func(arr, k) - func(arr, k - 1);
	}
	int func(vector<int>& arr, int k)
	{
		int ans = 0;
		int l = 0;
		int n = arr.size();
		unordered_map<int, int>hashMap;
		for (int r = 0; r < n; r++)
		{
			//如果是新来的数字,k--代表进来了
			if (hashMap.count(arr[r]) == 0 || hashMap[arr[r]] == 0)
				k--;
			hashMap[arr[r]]++;
			while (k < 0)//说明此时窗口中有k+1种数字
			{
				hashMap[arr[l]]--;
				if (hashMap[arr[l]] == 0)
					k++;
				l++;
			}
			ans += r-l + 1;
		}
		return ans;
	}
};