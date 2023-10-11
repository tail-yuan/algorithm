
//https://www.bilibili.com/video/BV1NV4y1B7ZZ?p=65&vd_source=cc945ef88574fe2db5e814c0c265a4c7
//https://leetcode.cn/problems/next-permutation/submissions/
//从右往左查找第一个i,[i]<[i+1],如果从右往左一直是升序,说明已经是最大排列了
//下一个排列就是最小值,直接翻转即可
//如果找到i位置,那么就说明[i+1,n]位置从左到右是降序的,下一个排列应该是
//在[i+1,n]中找到>[i]的最小元素,交换位置,之后将[i+1,n]逆序即可,就是下一个排列
// 4 9 7 6 3 1 下一个排列: ->6 9 7 4 3 1-> 6 1 3 4 7 9 
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