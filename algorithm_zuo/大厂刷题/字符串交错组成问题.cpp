//https://leetcode.cn/problems/interleaving-string/description/
//���:
// ���鷽ʽ
//�������ַ����Ľ�βλ��i,j�������һ�β���,dp[i][j]����ľ���s1[1,i]����,s2[1,j]����
//���s3[1,i+j]������true����false.ѡ��1������0,��Ϊ����s3���±������Ϊi+j
// Ϊ�˷������s1s2s3,������1,i����,���Բ�����ÿ���ַ���ǰ��ӿմ��ķ�ʽ
//if s3[i+j]==s1[i]-> dp[i][j]=dp[i-1][j]
//if s3[i+j]==s2[j]-> dp[i][j]=dp[i][j-1]
//��ʼ��:�϶��Ƕ࿪һ��,�࿪һ��
//dp[0][0]����s1s2��Ϊ�մ�ʱs3ҲΪ�մ�,true
//dp[0][j]����s1Ϊ�մ�ʱ,ֻҪs2[j]==s3[i+j],dp[0][j]=true
//dp[i][0]����s2Ϊ�մ�ʱ,ֻҪs1[i]==s3[i+j],dp[i][0]=true
//���˳��:��������,��������,����ǰһ��λ����һ��λ��
//����ֵ: ����dp[n][m]
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