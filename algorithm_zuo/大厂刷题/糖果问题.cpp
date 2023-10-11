//分配糖果:https://leetcode.cn/problems/candy/description/
//n 个孩子站成一排。给你一个整数数组 ratings 表示每个孩子的评分。
//你需要按照以下要求，给这些孩子分发糖果：
//每个孩子至少分配到 1 个糖果。
//相邻两个孩子评分更高的孩子会获得更多的糖果。
//请你给每个孩子分发糖果，计算并返回需要准备的 最少糖果数目 。
// 解法一:O(N),O(3N)
// 生成left数组,从左到右遍历,每个位置只考虑自己前面的那个位置的值,
// 如果比他大,就在他的糖果数量上++,其他不处理.
// 生成right数组,从右往左,每个位置只考虑自己后面的那个值,
// 如果比他大,就在他的糖果数量上++.
// 两个数组每个位置取max就是每个人应该分配的糖果数量.
// 解法二: 使用几个变量代替辅助数组leftright
// 
//进阶问题:在原问题的基础上，增加一个原则:
//相邻的孩子间如果分数一样，分的糖果数必须一样返回至少需要分多少糖
//解法: 同理,跟左边一样就继承,比左边小就=1,比左边大就++生成left数组.

#include<iostream>
#include<vector>
using namespace std;
class Solution
{
public:
    int candy(vector<int>& arr)
    {
        int n = arr.size();
        vector<int>left(n,1);
        vector<int>right(n,1);
        //避免越界访问,从index=1开始
        for (int i = 1; i < n; i++)
        {
            if (arr[i] > arr[i - 1])
                left[i] = left[i - 1] + 1;
        }
        for (int i = n - 2; i >= 0; i--)
        {
            if (arr[i] > arr[i + 1])
                right[i] = right[i + 1] + 1;
        }
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += max(left[i], right[i]);
        }
        return sum;
    }
    int candy_plus(vector<int>& arr)
    {
        int n = arr.size();
        vector<int>left(n, 1);
        vector<int>right(n, 1);
        //避免越界访问,从index=1开始
        for (int i = 1; i < n; i++)
        {
            if (arr[i] > arr[i - 1])
                left[i] = left[i - 1] + 1;
            else if (arr[i] == arr[i - 1])
                left[i] = left[i - 1];
        }
        for (int i = n - 2; i >= 0; i--)
        {
            if (arr[i] > arr[i + 1])
                right[i] = right[i + 1] + 1;
            else if (arr[i] == arr[i + 1])
                right[i] = right[i + 1];
        }
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += max(left[i], right[i]);
        }
        return sum;
    }
};