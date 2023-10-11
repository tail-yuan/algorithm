
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//扑克牌顺子的判断,nums[]就是随机抽取的5个数字
//[0,13]数字范围,A可以是1也可以是14,0代表大王或者小王,可以匹配任意数字
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
        //确定第一个不为0的数字
        int start = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] != 0)//无非就是跳过两个0
            {
                start = nums[i];
                if (start == 1 && (nums[i + 1] - nums[i]) > 2)
                {
                    start = nums[i + 1];
                }
                break;
            }
        }
        //start定位定错了
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
    //输入是长度为5的一串数字,判断是否是连续的
    //思路: 排序之后得到一串数字,计算0的个数count0,计算缺口个数count
    //如果count0>=count 个数就是true
    //连续条件: A=1 ->A=14,使用标记数组,标记是否出现过
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

                if (nums[i] == 1)//说明是A->14
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
        if (count0 == 0)//说明没有0 ,只需要判断start开始5个数是否都为true
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