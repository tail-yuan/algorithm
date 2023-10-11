//给你一个整数 n ，求恰由 n 个节点组成且节点值从 1 到 n 互不相同的 二叉搜索树 有多少种？
//返回满足题意的二叉搜索树的种数。
//可以不是二插搜索树,可以是任何满足条件的数字.
//卡特兰树的特点就是一共有n个节点,当某一节点被确定为头结点时,左右子树的节点个数就确定了
//此时左右子树的分析也就变成了相同的子问题:
//dp[i]表示当节点数量为i时,一共有多少颗满足条件的树
// 
//在1~i中选择一个j作为根节点,那么左子树有1~j-1 j-1个,右子树j+1~i,i-j个
//左右乘起来就是所有二叉搜索树的种数,dp[j-1]*dp[i-j]
//dp[i] +=dp[j-1]*dp[i-j]
//初始化: dp[0]没有节点时,空树也认为是一种,dp[0]=1,因为都用到前一个数,为了保证结果不为0,只能保证dp[0]=1
#include<iostream>
#include<vector>
using namespace std;
class Solution
{
public:
	int minTree(int n)
	{
		vector<int>dp(n + 1);
		dp[0] = 1;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= i; j++)
			{
				dp[i] += dp[j - 1] * dp[i - j];
			}
		}
		return dp[n];
	}
};