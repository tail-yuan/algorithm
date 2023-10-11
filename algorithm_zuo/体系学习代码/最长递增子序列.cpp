#include<iostream>
#include<vector>
using namespace std;

//dp[i]:以i位置结尾能形成的最长递增子序列的值
//更新方式:arr[i]时,前面的[0...i-1]的所有比arr[i]小的值都可以作为以arr[i]为结尾的子序列的倒数第二个值,我们找到其中最大的dp[x],需要最大dp[]值+1.保证递增+最长
//1. 找寻方式经典是遍历,O(N)->总时间复杂度是O(N^2)
//2. 构建ends数组,存在有效区和无效区两部分,end[i]代表的是以i+1为长度递增子序列的最小结尾是ends[i]这个数
//  2.1 更新方式:遍历到arr[i],在有效区中二分查找到>=arr[i]最左的位置,找到了,将他更新,找不到就放到有效区下一个位置,并拓展有效区
//  2.2 dp[i]=end数组中有效区中连同自己在内有几个值
// 构建出来的ends数组一定是递增的
//构建ends数组中的单调性,优化之前枚举的方式.O(N*logN)
//单独一个也能作为一个子序列,所以初始化为1

class Solution
{
public:
    //遍历的方式
    int lengthOfLIS1(vector<int>& nums)
    {
        int n = nums.size();
        vector<int> dp(n, 1);
        int ret = 1;
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (nums[j] < nums[i])
                {
                    dp[i] = max(dp[i], dp[j] + 1);//选择最大的一个dp[j]+1构成dp[i]
                }
                ret = max(ret, dp[i]);//每填充完一个就更新最大值
            }
        }
        return ret;
    }
    //O(N*logN)
    int lengthOfLIS2(vector<int>& nums)
    {
        int n = nums.size();
        vector<int>dp(n,1);
        vector<int>ends(n);
        ends[0] = nums[0];//以ends[0]为结尾的前1个递增子序列的结尾是ends[0]
        dp[0] = 1;
        int l = 0;
        int r = 0;
        int right = 0;
        int m = 0;
        for (int i = 1; i < n; i++)
        {
            l = 0; 
            r = right;
            ////二分找到大于等于x的最左位置 < >=模型,>=那个位置就是ends中可以更新的,特殊在区间没有目标,就需要在结尾新添加
            //while (l < r)
            //{
            //    m = l + (r - l) / 2;
            //    if (ends[m] < nums[i])
            //        l = m + 1;
            //    else
            //        r = m;
            //}//经过二分,l和r共同指向结果位置可能=,可能>
            while (l <= r)
            {
                m = l + (r - l) / 2;
                if (ends[m] < nums[i])
                    l = m + 1;
                else r = m-1;
            }//结尾跳出,l=r+1,也就是1. 没有目标时在r+1位置新添,2. 在>nums[i]的第一个ends[j]更新为nums[i],朴素二分做到了
            right = max(right, l);
            ends[l] = nums[i];
            dp[i] = l + 1;
        }

        int ret = 1;
        for (int i = 0; i < dp.size(); i++)
            ret = max(ret, dp[i]);
        return ret;
    }
};