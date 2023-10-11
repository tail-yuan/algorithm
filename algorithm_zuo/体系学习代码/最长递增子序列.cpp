#include<iostream>
#include<vector>
using namespace std;

//dp[i]:��iλ�ý�β���γɵ�����������е�ֵ
//���·�ʽ:arr[i]ʱ,ǰ���[0...i-1]�����б�arr[i]С��ֵ��������Ϊ��arr[i]Ϊ��β�������еĵ����ڶ���ֵ,�����ҵ���������dp[x],��Ҫ���dp[]ֵ+1.��֤����+�
//1. ��Ѱ��ʽ�����Ǳ���,O(N)->��ʱ�临�Ӷ���O(N^2)
//2. ����ends����,������Ч������Ч��������,end[i]���������i+1Ϊ���ȵ��������е���С��β��ends[i]�����
//  2.1 ���·�ʽ:������arr[i],����Ч���ж��ֲ��ҵ�>=arr[i]�����λ��,�ҵ���,��������,�Ҳ����ͷŵ���Ч����һ��λ��,����չ��Ч��
//  2.2 dp[i]=end��������Ч������ͬ�Լ������м���ֵ
// ����������ends����һ���ǵ�����
//����ends�����еĵ�����,�Ż�֮ǰö�ٵķ�ʽ.O(N*logN)
//����һ��Ҳ����Ϊһ��������,���Գ�ʼ��Ϊ1

class Solution
{
public:
    //�����ķ�ʽ
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
                    dp[i] = max(dp[i], dp[j] + 1);//ѡ������һ��dp[j]+1����dp[i]
                }
                ret = max(ret, dp[i]);//ÿ�����һ���͸������ֵ
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
        ends[0] = nums[0];//��ends[0]Ϊ��β��ǰ1�����������еĽ�β��ends[0]
        dp[0] = 1;
        int l = 0;
        int r = 0;
        int right = 0;
        int m = 0;
        for (int i = 1; i < n; i++)
        {
            l = 0; 
            r = right;
            ////�����ҵ����ڵ���x������λ�� < >=ģ��,>=�Ǹ�λ�þ���ends�п��Ը��µ�,����������û��Ŀ��,����Ҫ�ڽ�β�����
            //while (l < r)
            //{
            //    m = l + (r - l) / 2;
            //    if (ends[m] < nums[i])
            //        l = m + 1;
            //    else
            //        r = m;
            //}//��������,l��r��ָͬ����λ�ÿ���=,����>
            while (l <= r)
            {
                m = l + (r - l) / 2;
                if (ends[m] < nums[i])
                    l = m + 1;
                else r = m-1;
            }//��β����,l=r+1,Ҳ����1. û��Ŀ��ʱ��r+1λ������,2. ��>nums[i]�ĵ�һ��ends[j]����Ϊnums[i],���ض���������
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