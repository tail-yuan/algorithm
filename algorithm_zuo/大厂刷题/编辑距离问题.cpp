//https://leetcode.cn/problems/edit-distance/description/
//������������str1��str2�����Ƴ̶�,����������ʱ���кܸߵ�Ӧ��.
//���:
//dp[i][j]����s1[0,i]�仯Ϊs2[0,j]�������Ĵ���
//1. s1[i]==s2[j],ֻ��Ҫ��s1[0,i-1]�仯Ϊs2[0,j-1]����,dp[i][j]=dp[i-1][j-1]
//2. s1[i]!=s2[j],���������ַ�ʽ
// 1. ��s1��������һ����s2[j]��ȵ�,��s1[0,i]ȥƥ��s2[0,j-1],dp[i][j]=dp[i][j-1]+1
// 2. ��s1[i]ɾ�� ,dp[i][j]=dp[i-1][j]+1	
// 3. �滻,dp[i][j]=dp[i-1][j-1]+1
//��ʼ��: ���ö࿪һ�ж࿪һ�еķ�ʽ,1. ��ʼ���࿪�Ŀռ� 2. ����ԭ����ʱע���±���ʱ仯
//��һ��,����s1Ϊ�մ�ʱת��Ϊs2[0,j]�����ٲ�������,�϶���������j����,dp[0][j]=j
//��һ��,����s2Ϊ�մ�,s1[0,i]ת��Ϊ�մ������ٲ�����������ɾ��i����,dp[0][i]=i
//dp[0][0]=0
//���˳��: ��������,��������
//����ֵdp[m][n]

#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int minDistance(string s1, string s2) 
    {
        int m = s1.size(), n = s2.size();
        vector<vector<int>>dp(m+1,vector<int>(n+1));
        for (int j = 1; j <= n; j++)
            dp[0][j] = j;
        for (int i = 1; i <= m; i++)
            dp[i][0] = i;
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (s1[i - 1] == s2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1];//��ȾͲ���Ҫ����
                else
                {
                    int p1 = dp[i - 1][j] + 1;//ɾ��s1[i]
                    int p2 = dp[i][j - 1] + 1;//����,��s1[0,i]ƥ��s2[0,j-1]
                    int p3 = dp[i - 1][j - 1] + 1;//�滻s1[i]=s2[j]
                    dp[i][j] = min(p1, min(p2, p3));
                }
            }
        }
        return dp[m][n];
    }
};
//�������Ĳ���������������,������С���Ĵ���,d,a,r��������
//1. s1[i]==s2[j],ֻ��Ҫ��s1[0,i-1]�仯Ϊs2[0,j-1]����,dp[i][j]=dp[i-1][j-1]
//2. s1[i]!=s2[j],���������ַ�ʽ
// 1. ��s1��������һ����s2[j]��ȵ�,��s1[0,i]ȥƥ��s2[0,j-1],dp[i][j]=dp[i][j-1]+add
// 2. ��s1[i]ɾ�� ,dp[i][j]=dp[i-1][j]+delete
// 3. �滻,dp[i][j]=dp[i-1][j-1]+replace
//��ʼ��: ���ö࿪һ�ж࿪һ�еķ�ʽ,1. ��ʼ���࿪�Ŀռ� 2. ����ԭ����ʱע���±���ʱ仯
//��һ��,����s1Ϊ�մ�ʱת��Ϊs2[0,j]�����ٲ�������,�϶���������j����,dp[0][j]=j*add
//��һ��,����s2Ϊ�մ�,s1[0,i]ת��Ϊ�մ������ٲ�����������ɾ��i����,dp[0][i]=i*delete
//dp[0][0]=0
//���˳��: ��������,��������
//����ֵdp[m][n]
class Solution2 
{
public:
    int minDistance(string s1, string s2,int a,int d,int r)
    {
        int m = s1.size(), n = s2.size();
        vector<vector<int>>dp(m + 1, vector<int>(n + 1));
        for (int j = 1; j <= n; j++)
            dp[0][j] = j*a;
        for (int i = 1; i <= m; i++)
            dp[i][0] = i*d;
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (s1[i - 1] == s2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1];//��ȾͲ���Ҫ����
                else
                {
                    int p1 = dp[i - 1][j] + d;//ɾ��s1[i]
                    int p2 = dp[i][j - 1] + a;//����,��s1[0,i]ƥ��s2[0,j-1]
                    int p3 = dp[i - 1][j - 1] + r;//�滻s1[i]=s2[j]
                    dp[i][j] = min(p1, min(p2, p3));
                }
            }
        }
        return dp[m][n];
    }
    //�ռ�ѹ��: ��Ϊֻ��������һ��ǰһ��,���Ͻ�,���˳���������,�������Ͻ��ñ����洢����
    int minDistance2(string s1, string s2, int a, int d, int r)
    {
        int m = s1.size(), n = s2.size();
        vector<int>dp(n+1);
        for (int i = 1; i <= n; i++)
            dp[i] = i * a;
        for (int i = 1; i <= m; i++)
        {
            int prev = dp[0];
            dp[0] = d * i;//������ÿ����һ��,add����+1
            for (int j = 1; j <= n; j++)
            {
                int tmp = dp[j];//ԭ����һ�е�dp[i-1][j]
                if (s1[i - 1] == s2[j - 1])
                    dp[j] = prev;
                else
                {

                    int p1 = dp[j - 1] + a;
                    int p2 = dp[j] + d;
                    int p3 = prev + r;
                    dp[j] = min(p1, min(p2, p3));
                }
                prev = tmp;
            }
        }
        return dp[n];
    }
};