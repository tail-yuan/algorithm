//��������arr��arr�����е�ֵ��Ϊ�������Ҳ��ظ���
//ÿ��ֵ����һ����ֵ�Ļ��ң�ÿ����ֵ�Ļ��ҿ���ʹ�������ţ�
//�ٸ���һ��aim������Ҫ�ҵ�Ǯ���������aim�����ٻ�������
//����޽⣬�뷵�� - 1.
//
//���ݷ�Χ�������С����  �� ������ÿ�����ֶ����� ��
//
//Ҫ��ʱ�临�Ӷ�  ���ռ临�Ӷ� ��
//https://www.nowcoder.com/practice/3911a20b3f8743058214ceaa099eeb45
//��Ƶ�����,���Ǽ򵥵�zuoģ��
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
