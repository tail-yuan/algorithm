#include <iostream>
#include <vector>
using namespace std;
// 无数张钞票,面值组合问题,最小张数,涉及到遍历
class AimMoney
{
public:
    // 暴力方式
    int getMin1(vector<int> &arr, int aim)
    {
        return process(arr, aim);
    }
    // 返回[index,n-1]上使用的最少钞票数
    int process(vector<int> &arr, int rest)
    {
        if (rest == 0)
            return 0;
        if (rest < 0)
            return -1;
        int minCount = INT_MAX;
        for (int i = 0; i < arr.size(); i++)
        {
            int count = process(arr,rest-arr[i]);
            if (count != -1)
                minCount = min(minCount,count+1);
        }
        return minCount == INT_MAX ? -1 : minCount;
    }
    //rest dp[aim+1]
    //return dp[aim]
    //dp[0]=0
    int getMin2(vector<int>& arr, int aim)
    {
        vector<int>dp(aim + 1,INT_MAX);
        dp[0] = 0;
        for (int index = 1; index <= aim; index++)
        {
            for (int i = 0; i < arr.size(); i++)
            {
                if (index > arr[i] && dp[index-arr[i]]!=INT_MAX)
                    dp[index] = min(dp[index], dp[index - arr[i]]+1);
            }
        }
        return dp[aim]==INT_MAX?-1:dp[aim];
    }
};