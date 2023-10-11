
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//�˿���˳�ӵ��ж�,nums[]���������ȡ��5������
//[0,13]���ַ�Χ,A������1Ҳ������14,0�����������С��,����ƥ����������
#include <functional>
class Solution {
public:
    bool isStraight(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int>visi(15);
        for (int i = 0; i < nums.size(); i++)
        {
            visi[nums[i]]++;
            if (nums[i] == 1)
                visi[14]++;
        }
        int count = 0;
        //ȷ����һ����Ϊ0������
        int start = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] != 0)//�޷Ǿ�����������0
            {
                start = nums[i];
                if (start == 1 && (nums[i + 1] - nums[i]) > 2)
                {
                    start = nums[i + 1];
                }
                break;
            }
        }
        //start��λ������
        for (int i = 0; i < 5; i++) 
        {
            if (visi[start + i] == 0) 
            {
                count++;
            }
        }
        if (visi[0] == 0)
        {
            if (count > 0)return false;
            else return true;
        }
        else
        {
            if (count > 0)
            {
                if (visi[0] >= count)return true;
                else return false;
            }
            else
                return true;
        }
    }
};
/*
class Solution 
{
public:
    //�����ǳ���Ϊ5��һ������,�ж��Ƿ���������
    //˼·: ����֮��õ�һ������,����0�ĸ���count0,����ȱ�ڸ���count
    //���count0>=count ��������true
    //��������: A=1 ->A=14,ʹ�ñ������,����Ƿ���ֹ�
    bool isStraight(vector<int>& nums) 
    {
        vector<bool>visi(15,false);
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int count0 = 0, count = 0;
        int start = 0;
        bool flag = false;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] == 0)count0++;
            else
            {
                if (!flag)
                {
                    start = i;
                    flag = true;
                }

                if (nums[i] == 1)//˵����A->14
                {
                    visi[14] = true;
                    visi[1] = true;
                }
                else
                {
                    visi[nums[i]] = true;
                }
            }
        }
        if (count0 == 0)//˵��û��0 ,ֻ��Ҫ�ж�start��ʼ5�����Ƿ�Ϊtrue
        {
            for (int i = 0; i < 5; i++)
            {
                if (visi[start + i] == false)
                    return false;
            }
            return true;
        }
        return false;
    }
};
int main()
{
    Solution s;
    vector<int>arr{ 1,2,3,4,5};
    cout<<s.isStraight(arr);
}
*/