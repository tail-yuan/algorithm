
//子数组问题: dp[i]代表的是以i位置为结尾,形成的最大累加和
//考虑最近一次操作,
//两种选择,一种是自己单独,一种是和i-1位置累加在一起,
//dp[i]=max(nums[i],dp[i-1]+nums[i])
//i-1涉及到越界,多开一个空间,1. 访问原数组时下标变换,2. 入和初始化多开的空间使得不影响后续计算
//考虑dp[0],dp[0]=0时不影响dp[1]=nums[0]
//填表顺序:  从左到右

//空间优化:因为i位置填dp表时只需要考虑前一个位置,那么可以不用开dp数组空间,可以只用一个变量存储即可
#include<iostream>
#include<vector>
using namespace std;
class Solution
{
public:
	int maxmaxSubArray(vector<int >& arr)
	{
		int n = arr.size();
		vector<int>dp(n + 1);
		int ret = INT_MIN;
		for (int i = 1; i <= n; i++)
		{
			dp[i] = max(arr[i - 1], dp[i - 1] + arr[i - 1]);
			ret = max(ret, dp[i]);
		}
		return ret;
	}
	int maxmaxSubArray2(vector<int >& arr)
	{
		int n = arr.size();
		int prev = 0;
		int ret = INT_MIN;
		for (int i = 0; i < n; i++)
		{
			int num = max(arr[i], arr[i] + prev);
			ret = max(ret, num);
			prev = num;
		}
		return ret;
	}
};