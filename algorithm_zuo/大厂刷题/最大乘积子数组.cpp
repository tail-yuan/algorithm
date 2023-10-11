
#include<iostream>
#include<vector>
using namespace std;
//��״̬������dp����
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

//��iλ��Ϊ��β,dp[i]��¼������iΪ��β�������������г˻�����������ĳ˻�
//iλ���Լ�һ��,iλ�ú�ǰ������Ϊһ��,�������iλ���Ǹ���,��ô����ǰi-1������ֻ���ø�С,Υ����dp[i]������,����Ҫ����ǰ����С�ĳ˻���,������һ��״̬,f[i]=g[i]*nums[i](nums[i]<0)
//��ʱ��f[i]��ʾ���˻�,g[i]��ʾ��С�˻�,
//1.1 ������ѡ��ֻ��һ������ʱ,��ֻ��iλ�õ�����,f[i]=nums[i]
//1.2 ������Ҫ��ǰ������,����nums[i]>0,ѡ�е���ǰ��Ҳ�����˻�,f[i]=f[i-1]*nums[i]
//1.3 ������Ҫ��ǰ������,����nums[i]<0,ѡ�е���ǰ��Ҳ����С�˻�,f[i]=g[i-1]*nums[i]
//2.1 ������ѡ��ֻ��һ������ʱ,��ֻ��iλ�õ�����,g[i]=nums[i]
//2.2 ������Ҫ��ǰ������,����nums[i]>0,ѡ�е���ǰ��Ҳ����С�˻�,g[i]=g[i-1]*nums[i]
//1.3 ������Ҫ��ǰ������,����nums[i]<0,ѡ�е���ǰ��Ҳ�����˻�,g[i]=f[i-1]*nums[i]
//f[i]=max(nums[i],f[i-1]*nums[i],g[i-1]*nums[i]) 
//g[i]=min(nums[i],f[i-1]*nums[i],g[i-1]*nums[i])
//��ʼ��: ���һ������ڵ�,1.����ڵ�ֵ��Ӱ�����,f[0]=1,g[0]=1 =>ԭ��f[0]=nums[0],*1��ֵ����,ԭ�����+0����һ����.