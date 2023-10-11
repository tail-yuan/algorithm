//�ܹ���Ϊ�Ȳ����е������еĸ���
//�Ȳ����е�Ԫ�ظ����������2
//https://www.bilibili.com/video/BV1NV4y1B7ZZ?p=73&vd_source=cc945ef88574fe2db5e814c0c265a4c7
//vector<index,hashMap<sub,count>>dp
// ��¼��arr[index]=keyΪ��β��,��ֵΪsub��������,
// ���ҳ��ȶ�>=2�ĸ���
//����iλ��ʱ,���α���[1,i-1]�е�ÿһ��������Ϊiλ�������е�ǰһ��λ��,������sub��count
//
//1. ������Χ����,������������֮���Ѿ��ƽ��������,���Կ϶�������3������Ϊ������
//2. �����п��ܴ����ظ�ֵ,��ô��index��ǰ�Ҳ�ֵΪ��ͬsub�������и���ʱ���ۼӹ�ϵ,�����Ǹ���
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
    //����������������ѡ���Ȳ������еĸ���
    //��iλ��Ϊ��β,dp[i]������iΪ��β��������������,�Ȳ������еĸ���.����Ѱ����[0,i-1]���ҵ���jΪ��β��������,�������ĺ���,dp[i]=d[j]
    //����i��һ���ܸ���j�ĺ���,��Ϊdp[i],dp[j]ֻ�Ǽ�¼�˸���,�޷�ȷ���γ�j�����еĵȲ��ij֮��������һ����.����һ��״̬��ʾ�ǲ�����
    //ȷ�����������֮��,�Ϳ����ҵ���������������ʲô.���ǿ��ܴ��ںܶ��,��������Ǹ���,���Զ��ֵ����Ҫ����ͳ��.
    // 
    //dp[i][j]��ʾ��ijλ��Ϊ��β���������еȲ������еĸ���,����Ҫ��ǰ��Ľ����һ��,��kֵ���ڲ���k<iʱ,
    //j������kiΪ��β�������к���,��ʱki����ѡ�����������j,Ҳ����ѡ���֮ǰ�ĺö����Ϻ�j����һ��,����dp[i][j]=dp[k][i]+1
    //��Ϊk �ж��,����dp[i][j]+=dp[k][i]+1
    //����k�±�,1. ��������[0,i-1]��Ѱ��O(N) 2. ������Ԫ�غ��±��,���ڹ�ϣ����.���ǿ��Ǹ�������,һ���Ǳ����߸���.���߶���¼vector
    //��ʼ��: ������0,ֻ������Ԫ�ص�ʱ��,�����еĸ�����0
    //���˳��: 1. �ȹ̶�i,�ٹ̶�j 2. �ȹ̶�j�ٹ̶�i
    //����ֵ: ����dp����Ԫ�صĺ�
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