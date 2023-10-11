//https://leetcode-cn.com/problems/21dk04/
//样本对应模型-可能性根据结尾问题划分
//dp[i][j]表示str1[0,i]区间形成的任意子序列字面值等于str2[0,j]区间的个数
//1. 子序列中,[i]位置不用,dp[i-1][j]
//2. 子序列中,[i]位置一定要用,if str1[i]==str2[j],dp[i-1][j-1]
//dp[i][j]是以上两种可能性结果相加
//初始化: 多开一行多开一列,第一行代表str1为空时,匹配str2的个数肯定为0.第一列代表当str2为空时,str1[0,i]
//存在的子序列匹配空的个数,那我就不选呗,个数就是1.因为多开一行多开一列,所以在访问原字符串时要注意下标
// 主要还是为了让后续计算有值,所以空字符串位置初始化为1
//返回值: dp[m][n]
//填报顺序:  左->右 上->下
#include<iostream>
#include<vector>
using namespace std;
class Solution
{
public:
    //dp[i][j]表示t[0,i]区间子串在s[0,j]区间子序列中出现的个数
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