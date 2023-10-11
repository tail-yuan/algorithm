//https://leetcode.cn/problems/interleaving-string/description/
//题解:
// 动归方式
//以两个字符串的结尾位置i,j考虑最近一次操作,dp[i][j]代表的就是s1[1,i]区间,s2[1,j]区间
//组成s3[1,i+j]区间是true还是false.选中1而不是0,是为了在s3中下标好索引为i+j
// 为了方便访问s1s2s3,并且是1,i区间,所以采用在每个字符串前添加空串的方式
//if s3[i+j]==s1[i]-> dp[i][j]=dp[i-1][j]
//if s3[i+j]==s2[j]-> dp[i][j]=dp[i][j-1]
//初始化:肯定是多开一行,多开一列
//dp[0][0]代表s1s2都为空串时s3也为空串,true
//dp[0][j]代表s1为空串时,只要s2[j]==s3[i+j],dp[0][j]=true
//dp[i][0]代表s2为空串时,只要s1[i]==s3[i+j],dp[i][0]=true
//填表顺序:从左往右,从上往下,依赖前一个位置上一个位置
//返回值: 返回dp[n][m]
#include<iostream>
#include<vector>
using namespace std;
class Solution
{
public:
	bool isInterleave(string s1, string s2, string s3)
	{
		int m = s1.size(), n = s2.size();
		if (m + n != s3.size())return false;
		s1 = " " + s1;
		s2 = " " + s2;
		s3 = " " + s3;
		vector<vector<bool>>dp(m + 1, vector<bool>(n + 1,false));
		dp[0][0] = true;
		for (int i = 1; i <= m; i++)
			if (s1[i] == s3[i])
				dp[i][0] = true;
			else break;
		for (int j = 1; j <= n; j++)
			if (s2[j] == s3[j])
				dp[0][j] = true;
			else break;
		for (int i = 1; i <= m; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				dp[i][j] = (s1[i] == s3[i + j] && dp[i - 1][j]) 
						|| (s2[j] == s3[i + j] && dp[i][j - 1]);
			}
		}
		return dp[m][n];
	}
};