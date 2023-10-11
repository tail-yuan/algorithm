#include<iostream>
#include<vector>
using namespace std;
//https://leetcode.cn/problems/uncrossed-lines/
class Solution
{
public:
    //其实就是找两个数组中的最长公共子序列数字,序列不能放回找就是这里的直线不想交.
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2)
    {
        int m = nums1.size(), n = nums2.size();
        vector<vector<int>>dp(m + 1, vector<int>(n + 1));
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (nums1[i - 1] == nums2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return dp[m][n];
    }
};