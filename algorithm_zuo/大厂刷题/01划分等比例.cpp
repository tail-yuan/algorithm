//https://www.bilibili.com/video/BV1NV4y1B7ZZ?p=59&vd_source=cc945ef88574fe2db5e814c0c265a4c7
//等比例划分,如果大区间[0,x]上01的比例是a:b
//如果存在一种划分让每个小区间都等比例,那么每个小区间内的比例也是a:b
//所以题目所求以[0,i]为前缀的区间最多能够划分出多少个等比例的区间数目,
//关键: 大区间的比例为a:b,那么如果之前的小区间中比例有为a:b的,大区间的个数就是,
//就是前缀划分的区间中和自己此时比例相同的区间数目+自己本身
// 
//加入已知[0,99]比例式3:7,并且已知[0,66]是3:7,那么至少[67,99]中的比例也是3:7
//dp[99]=2+1
//如果又知道了[0,56]也是3:7,那么[57,66]必然也是3:7,dp[99]=3+1
// 
//所以做法就是,到达i位置时,使用哈希表记录之前区间划分得到的比例,以及各自出现的次数
//小区间比例推导现在较大区间比例,比例不能用key记录,会存在精度损失,
//所以使用两张表: map<分子,map<分母,分子/分母比例出现次数>>
//记录的是比例出现次数,所以需要求解分子分母的最大公约数,记录比例
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
class Solution
{
public:
	vector<int> Ratio01Split(vector<int>&arr)
	{
		unordered_map<int, unordered_map<int, int>>hashMap;
		int n = arr.size();
		vector<int>ans(n);
		int zero = 0;
		int one = 0;
		for (int i = 0; i < n; i++)
		{
			if (arr[i] == 0)
				zero++;
			if (arr[i] == 1)
				one++;
			//如果发现一段区间都是0或者1,最大划分使得区间等比例就是一个一个一组,个数就是i+1
			if (zero == 0 || one == 0)
				ans[i] = i + 1;
			else
			{
				int gcd_ret = gcd(zero, one);
				int a = zero / gcd_ret;
				int b = one / gcd_ret;
				if (hashMap.count(a) == 0)
					hashMap.insert({a,unordered_map<int,int>()});
				if (hashMap[a].count(b) == 0)
					hashMap[a].insert({b,1});
				else
				{
					hashMap[a][b]++;
				}
				ans[i] = hashMap[a][b];
			}
		}
		return ans;
	}
	//欧几里得算法的基本思想是: 给定两个正整数 a 和6，其中 a > b，
	// gcd(a,b) (最大公约数) 等于gcd(b,a mod b)
	//这里的 a mod b是a 除以6的余数
	//函数的工作原理如下
	//1. 如果6 = 0，那么a 就是最大公约数。这是递归的基本情况
	//2.否则，递归调用 gcd(b, a mod 6)。
	int gcd(int a, int b)
	{
		return b == 0 ? a : gcd(b, a % b);      
	}
};