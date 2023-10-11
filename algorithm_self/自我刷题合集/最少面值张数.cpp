//给定数组arr，arr中所有的值都为正整数且不重复。
//每个值代表一种面值的货币，每种面值的货币可以使用任意张，
//再给定一个aim，代表要找的钱数，求组成aim的最少货币数。
//如果无解，请返回 - 1.
//
//数据范围：数组大小满足  ， 数组中每个数字都满足 ，
//
//要求：时间复杂度  ，空间复杂度 。
//https://www.nowcoder.com/practice/3911a20b3f8743058214ceaa099eeb45
//设计到遍历,不是简单的zuo模型
#include<iostream>
#include <climits>
#include<vector>
using namespace std;
class Solution {
public:
      int minmoney1(vector<int>& arr, int aim) {
          // write code here
          return process(arr,aim);
      }
      int process(vector<int>&arr,int rest)
      {
          if(rest==0) return 0;
          if(rest<0) return -1;
          int mincount=INT_MAX;
          for(int i=0;i<arr.size();i++)
          {
              int count=process(arr, rest-arr[i]);
              if(count!=-1)
                  mincount=min(mincount,count+1);
          }
          return mincount == INT_MAX ?-1:mincount;
      }
    int minMoney(vector<int>& arr, int aim) {
        // write code here
        vector<int>dp(aim + 1, INT_MAX);
        dp[0] = 0;
        for (int i = 1; i <= aim; i++)
        {
            for (int j = 0; j < arr.size(); j++)
            {
                if (i >= arr[j] && dp[i - arr[j]] != INT_MAX)
                    dp[i] = min(dp[i], dp[i - arr[j]] + 1);
            }
        }
        return dp[aim] == INT_MAX ? -1 : dp[aim];
    }
};
