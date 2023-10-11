//能够成为等差数列的子序列的个数
//等差数列的元素个数必须大于2
//https://www.bilibili.com/video/BV1NV4y1B7ZZ?p=73&vd_source=cc945ef88574fe2db5e814c0c265a4c7
//vector<index,hashMap<sub,count>>dp
// 记录以arr[index]=key为结尾的,差值为sub的子序列,
// 并且长度都>=2的个数
//到达i位置时,依次遍历[1,i-1]中的每一个数字作为i位置子序列的前一个位置,来更新sub和count
//
//1. 整数范围优先,如果两个数相减之后已经逼近整数溢出,所以肯定不能有3个数作为子序列
//2. 数组中可能存在重复值,那么在index往前找差值为相同sub的子序列个数时是累加关系,而不是覆盖
#include<iostream>
#include <vector>
#include <algorithm>
#include<unordered_map>
using namespace std;
class Solution1
{
public:
    int numberOfArithmeticSlices(vector<int>& nums)
    {
        int n = nums.size();
        int ans = 0;
        vector<unordered_map<long long, int>> dp(n);
        for (int i = 0; i < n; i++)
        {
            for (int j = i - 1; j >= 0; j--)
            {
                long long diff = (long long)nums[i] - (long long)nums[j];
                if (diff <= INT_MIN || diff >= INT_MAX)
                    continue;
                int dif = (int)diff;
                int count = dp[j][dif];
                ans += count;
                dp[i][dif] = dp[i][dif] + count + 1;
            }
        }
        return ans;
    }
};
class Solution
{
public:
    //在所有子序列中挑选出等差子序列的个数
    //以i位置为结尾,dp[i]代表以i为结尾的所有子序列中,等差子序列的个数.我们寻求在[0,i-1]中找到以j为结尾的子序列,跟在他的后面,dp[i]=d[j]
    //但是i不一定能跟在j的后面,因为dp[i],dp[j]只是记录了个数,无法确定形成j的序列的等差和ij之间相差的是一个数.所以一个状态表示是不够的
    //确定最后两个数之后,就可以找到倒数第三个数是什么.但是可能存在很多个,我们求得是个数,所以多个值都需要考虑统计.
    // 
    //dp[i][j]表示以ij位置为结尾的子序列中等差子序列的个数,必须要和前面的结合在一起,当k值存在并且k<i时,
    //j跟在以ki为结尾的子序列后面,此时ki可以选择独自两个和j,也可以选择和之前的好多个组合和j放在一起,所以dp[i][j]=dp[k][i]+1
    //因为k 有多个,所以dp[i][j]+=dp[k][i]+1
    //查找k下标,1. 遍历数组[0,i-1]中寻找O(N) 2. 将所有元素和下标绑定,放在哈希表中.但是考虑覆盖问题,一定是边填表边更新.或者都记录vector
    //初始化: 最差就是0,只有两个元素的时候,子序列的个数是0
    //填表顺序: 1. 先固定i,再固定j 2. 先固定j再固定i
    //返回值: 返回dp表中元素的和
    int numberOfArithmeticSlices(vector<int>& nums)
    {
        int n = nums.size();
        unordered_map<long long, vector<int>>hashMap;
        for (int i = 0; i < n; i++)
            hashMap[nums[i]].push_back(i);

        vector<vector<int>>dp(n, vector<int>(n));
        int sum = 0;
        for (int j = 2; j < n; j++)
        {
            for (int i = 1; i < j; i++)
            {
                long long a = (long long)2 * nums[i] - nums[j];
                if (hashMap.count(a))
                {
                    for (auto k : hashMap[a])
                    {
                        if (k < i)
                        {
                            dp[i][j] += dp[k][i] + 1;
                        }
                    }
                }
                sum += dp[i][j];
            }
        }
        return sum;
    }
};