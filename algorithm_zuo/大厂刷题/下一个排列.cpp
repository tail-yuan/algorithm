
//https://www.bilibili.com/video/BV1NV4y1B7ZZ?p=65&vd_source=cc945ef88574fe2db5e814c0c265a4c7
//https://leetcode.cn/problems/next-permutation/submissions/
//����������ҵ�һ��i,[i]<[i+1],�����������һֱ������,˵���Ѿ������������
//��һ�����о�����Сֵ,ֱ�ӷ�ת����
//����ҵ�iλ��,��ô��˵��[i+1,n]λ�ô������ǽ����,��һ������Ӧ����
//��[i+1,n]���ҵ�>[i]����СԪ��,����λ��,֮��[i+1,n]���򼴿�,������һ������
// 4 9 7 6 3 1 ��һ������: ->6 9 7 4 3 1-> 6 1 3 4 7 9 
// 6 1 3 4 7 9
#include<iostream>
#include<vector>
using namespace std;
class Solution
{
public:
    void nextPermutation(vector<int>& nums)
    {
        int n = nums.size();
        int firstLess = -1;
        for (int i = n - 2; i >= 0; i--)
        {
            if (nums[i] < nums[i + 1])
            {
                firstLess = i;
                break;
            }
        }
        if (firstLess < 0)
            reverse(nums.begin(),nums.end());
        else
        {
            int rightClose = -1;
            for (int i = n - 1; i > firstLess; i--)
            {
                if (nums[i] > nums[firstLess])
                {
                    rightClose = i;
                    break;
                }
            }
            swap(nums[firstLess], nums[rightClose]);
            reverse(nums.begin()+firstLess+1,nums.end());
        }
    }
};