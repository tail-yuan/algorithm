//https://leetcode-cn.com/problems/21dk04/
//������Ӧģ��-�����Ը��ݽ�β���⻮��
//dp[i][j]��ʾstr1[0,i]�����γɵ���������������ֵ����str2[0,j]����ĸ���
//1. ��������,[i]λ�ò���,dp[i-1][j]
//2. ��������,[i]λ��һ��Ҫ��,if str1[i]==str2[j],dp[i-1][j-1]
//dp[i][j]���������ֿ����Խ�����
//��ʼ��: �࿪һ�ж࿪һ��,��һ�д���str1Ϊ��ʱ,ƥ��str2�ĸ����϶�Ϊ0.��һ�д���str2Ϊ��ʱ,str1[0,i]
//���ڵ�������ƥ��յĸ���,���ҾͲ�ѡ��,��������1.��Ϊ�࿪һ�ж࿪һ��,�����ڷ���ԭ�ַ���ʱҪע���±�
// ��Ҫ����Ϊ���ú���������ֵ,���Կ��ַ���λ�ó�ʼ��Ϊ1
//����ֵ: dp[m][n]
//�˳��:  ��->�� ��->��
#include<iostream>
#include<vector>
using namespace std;
class Solution
{
public:
    //dp[i][j]��ʾt[0,i]�����Ӵ���s[0,j]�����������г��ֵĸ���
    int numDistinct(string s, string t)
    {
        int n = s.size(), m = t.size();
        vector<vector<double>> dp(n+1,vector<double>(m+1));
        for (int i = 0; i <= n; i++)
            dp[i][0] = 1;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                dp[i][j] += dp[i - 1][j];
                if (s[i - 1] == t[j - 1])
                    dp[i][j] += dp[i - 1][j - 1];
            }
        }
        return dp[n][m];
    }
};