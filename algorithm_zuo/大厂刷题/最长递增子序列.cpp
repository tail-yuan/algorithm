//https://leetcode.cn/problems/longest-increasing-subsequence/submissions/
//dp思想
//以i位置为结尾,dp[i]代表以i位置为结尾的所有子序列中长度最长的那个的长度
//[0,i-1]区间中找到一个j位置,[j]<[i],此时将[i]位置连接在[j]的后面即可
//dp[i]=dp[j]+1,由于j的值可能存在多个,而我们想要的是最长的那个记录下来,
//dp[i]=max(dp[i],dp[j]+1)
//返回值: dp[i]记录的是以i为结尾的,但是最大值可能是以任意为结尾的,所以要dp表中最大值
//初始化: 开n个空间,每个值代表每个子序列的长度至少是1
//填表顺序,任意
//dfs思想+memo优化
// 以index位置为开头
//子问题: 每到达index位置,都需要在index之后的数组中选择比自己大的组成path字符串,继续下去
//因为只需要计算长度,不用拼接path,直接+1即可
//每个以index为开头都会有很多的子序列产生,我们要的是最大值.
//出口: index到达n返回,说明枚举完了,返回path的大小
//回溯: 恢复现场,path需要恢复,传值参数函数栈帧会自动搞定
//发现以index为开头找子序列存在大量重复计算,所以可以优化为记忆化搜索memo
//在进入的时候判断是否计算过,在返回值的时候先记录一下再返回
#include<iostream>
#include<vector>
#include<string>
using namespace std; 
class Solution
{
public:
	int lengthOfLIS(vector<int>& nums)
	{
		int n = nums.size();
		vector<int>dp(n, 1);
		int ret = 1;//长度问题老实初始化为1
		for (int i = 1; i < n; i++)
		{
			for (int j = 0; j < i; j++)
			{
				if (nums[j] < nums[i])
					dp[i] = max(dp[i], dp[j] + 1);
			}
			ret = max(ret, dp[i]);
		}
		return ret;
	}
private:
	vector<int>memo;
	int n;
public:
	//dfs思想
	int lengthOfLIS2(vector<int>& nums)
	{
		n = nums.size();
		int ret = 1;
		memo = vector<int>(n, 0);
		for (int i = 0; i < n; i++)
		{
			ret = max(ret, dfs(nums, i));
		}
		return ret;
	}
	int dfs(vector<int>& nums, int index)
	{
		if (memo[index] != 0) return memo[index];
		int ret = 1;
		for (int i = index+1; i < n; i++)
		{
			if (nums[i] > nums[index])
				ret=max(ret,dfs(nums, i)+1);
		}
		memo[index] = ret;
		return memo[index];
	}
public:
	//由dfs-memo改动来的dp
	//发现j的更新,依赖于i,而i在j后面的,所以应该从后往前填写表
	int lengthOfLIS3(vector<int>& nums)
	{
		int m = nums.size();
		vector<int>dp(m, 1);
		int ret = 1;
		for (int j = m-1; j>=0; j--)
		{
			for (int i = j + 1; i < m; i++)
			{
				if (nums[i] > nums[j])
					dp[j] = max(dp[j], dp[i] + 1);
			}
			ret = max(ret, dp[j]);
		}
		return ret;
	}
};
int main()
{
	return 0;
}