
#include<iostream>
#include<vector>
using namespace std;
//多状态的线性dp问题
class Solution
{
public:
    int maxProduct(vector<int>& nums)
    {
        int n = nums.size();
        vector<int>f(n + 1, 1);
        vector<int>g(n + 1, 1);
        int ret = INT_MIN;
        for (int i = 1; i <= n; i++)
        {
            int x = nums[i-1], y = f[i - 1] * nums[i-1], z = g[i - 1] * nums[i-1];
            f[i] = max(x, max(y, z));
            g[i] = max(x, max(y, z));
            ret = max(ret, f[i]);
        }
        return ret;
    }
};

//以i位置为结尾,dp[i]记录的是以i为结尾的所有子数组中乘积最大的子数组的乘积
//i位置自己一组,i位置和前面的相乘为一组,但是如果i位置是负数,那么乘上前i-1个最大的只会变得更小,违背了dp[i]的意义,他需要乘上前面最小的乘积和,这又是一中状态,f[i]=g[i]*nums[i](nums[i]<0)
//这时用f[i]表示最大乘积,g[i]表示最小乘积,
//1.1 子数组选择只有一个数字时,即只有i位置的数字,f[i]=nums[i]
//1.2 子数组要和前面的组合,并且nums[i]>0,选中的是前面也是最大乘积,f[i]=f[i-1]*nums[i]
//1.3 子数组要和前面的组合,并且nums[i]<0,选中的是前面也是最小乘积,f[i]=g[i-1]*nums[i]
//2.1 子数组选择只有一个数字时,即只有i位置的数字,g[i]=nums[i]
//2.2 子数组要和前面的组合,并且nums[i]>0,选中的是前面也是最小乘积,g[i]=g[i-1]*nums[i]
//1.3 子数组要和前面的组合,并且nums[i]<0,选中的是前面也是最大乘积,g[i]=f[i-1]*nums[i]
//f[i]=max(nums[i],f[i-1]*nums[i],g[i-1]*nums[i]) 
//g[i]=min(nums[i],f[i-1]*nums[i],g[i-1]*nums[i])
//初始化: 添加一个虚拟节点,1.新添节点值不影响后续,f[0]=1,g[0]=1 =>原本f[0]=nums[0],*1让值不变,原本求和+0不变一样的.