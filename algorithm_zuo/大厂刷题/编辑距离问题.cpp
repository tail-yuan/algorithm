//https://leetcode.cn/problems/edit-distance/description/
//可以用来描述str1和str2的相似程度,在搜索引擎时具有很高的应用.
//题解:
//dp[i][j]代表s1[0,i]变化为s2[0,j]最少消耗次数
//1. s1[i]==s2[j],只需要让s1[0,i-1]变化为s2[0,j-1]次数,dp[i][j]=dp[i-1][j-1]
//2. s1[i]!=s2[j],可以有三种方式
// 1. 在s1后面新增一个和s2[j]相等的,让s1[0,i]去匹配s2[0,j-1],dp[i][j]=dp[i][j-1]+1
// 2. 将s1[i]删除 ,dp[i][j]=dp[i-1][j]+1	
// 3. 替换,dp[i][j]=dp[i-1][j-1]+1
//初始化: 采用多开一行多开一列的方式,1. 初始化多开的空间 2. 访问原数组时注意下标访问变化
//第一行,代表s1为空串时转化为s2[0,j]的最少操作次数,肯定就是新增j个嘛,dp[0][j]=j
//第一列,代表s2为空串,s1[0,i]转化为空串的最少操作次数就是删除i个嘛,dp[0][i]=i
//dp[0][0]=0
//填表顺序: 从上往下,从左往右
//返回值dp[m][n]

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
                    dp[i][j] = dp[i - 1][j - 1];//相等就不需要操作
                else
                {
                    int p1 = dp[i - 1][j] + 1;//删除s1[i]
                    int p2 = dp[i][j - 1] + 1;//新增,让s1[0,i]匹配s2[0,j-1]
                    int p3 = dp[i - 1][j - 1] + 1;//替换s1[i]=s2[j]
                    dp[i][j] = min(p1, min(p2, p3));
                }
            }
        }
        return dp[m][n];
    }
};
//如果计算的不是上述操作次数,而是最小消耗代价,d,a,r三个代价
//1. s1[i]==s2[j],只需要让s1[0,i-1]变化为s2[0,j-1]次数,dp[i][j]=dp[i-1][j-1]
//2. s1[i]!=s2[j],可以有三种方式
// 1. 在s1后面新增一个和s2[j]相等的,让s1[0,i]去匹配s2[0,j-1],dp[i][j]=dp[i][j-1]+add
// 2. 将s1[i]删除 ,dp[i][j]=dp[i-1][j]+delete
// 3. 替换,dp[i][j]=dp[i-1][j-1]+replace
//初始化: 采用多开一行多开一列的方式,1. 初始化多开的空间 2. 访问原数组时注意下标访问变化
//第一行,代表s1为空串时转化为s2[0,j]的最少操作次数,肯定就是新增j个嘛,dp[0][j]=j*add
//第一列,代表s2为空串,s1[0,i]转化为空串的最少操作次数就是删除i个嘛,dp[0][i]=i*delete
//dp[0][0]=0
//填表顺序: 从上往下,从左往右
//返回值dp[m][n]
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
                    dp[i][j] = dp[i - 1][j - 1];//相等就不需要操作
                else
                {
                    int p1 = dp[i - 1][j] + d;//删除s1[i]
                    int p2 = dp[i][j - 1] + a;//新增,让s1[0,i]匹配s2[0,j-1]
                    int p3 = dp[i - 1][j - 1] + r;//替换s1[i]=s2[j]
                    dp[i][j] = min(p1, min(p2, p3));
                }
            }
        }
        return dp[m][n];
    }
    //空间压缩: 因为只依赖于上一个前一个,左上角,填表顺序从左往右,并将左上角用变量存储即可
    int minDistance2(string s1, string s2, int a, int d, int r)
    {
        int m = s1.size(), n = s2.size();
        vector<int>dp(n+1);
        for (int i = 1; i <= n; i++)
            dp[i] = i * a;
        for (int i = 1; i <= m; i++)
        {
            int prev = dp[0];
            dp[0] = d * i;//别忘了每多来一行,add次数+1
            for (int j = 1; j <= n; j++)
            {
                int tmp = dp[j];//原本上一行的dp[i-1][j]
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