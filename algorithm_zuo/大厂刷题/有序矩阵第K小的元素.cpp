//https://leetcode.cn/problems/kth-smallest-element-in-a-sorted-matrix/?utm_source=LCUS&utm_medium=ip_redirect&utm_campaign=transfer2china
//矩阵前提是每一行有序,每一列有序.
// 
//题解:
//1. 如何找到小于K的数字一共有多少个?
// 和右上角元素x比较,if k<x: x往左走, if k>x: 因为一行是有序的,左侧都比k小,收集多少个,然后往下走
// 
//2. 如何找到最接近K的数字?
// 同理,在往下走时说明此时的k>x,记录x. 过程中更新x的最大值,但是小于K,即可.
//3. 题干: 如何找到第K小的数字,那么区间范围是minVal(0,0) ~maxVal(n-1,m-1),使用二分的方式,统计比Mid小的
//数字有多少个sum,和K比较.if sum<K,说明mid得向右找,else 往左找.
// -------最容易忽略的就是:
//可能找到第k'个数时候正好凑够K个,但是在矩阵中可能没有k',那么返回最接近k'的数字
//最终得到结果.
//T(N): 查表O(n+m) 二分次数是O(log(maxVal-minVal))
#include<iostream>
#include<vector>
using namespace std;
class Solution
{
    class Info
    {
    public:
        int near;
        int num;
        Info(int ne, int nu)
            :near(ne)
            , num(nu)
        {}
    };
    int n;
    int m;
public:
    int kthSmallest(vector<vector<int>>& arr, int k)
    {
        n = arr.size(), m = arr[0].size();
        int left = arr[0][0], right = arr[n - 1][m - 1];
        int ans = 0;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            //查表时要找<=mid的数字和<=mid个数字的个数
            Info info = noMoreNum(arr, mid);
            if (info.num < k)
                left = mid + 1;
            else
            {
                ans = info.near;
                right = mid - 1;
            }
        }
        return ans;
    }
    Info noMoreNum(vector<vector<int>>& arr, int val)
    {
        int near = INT_MIN;
        int count = 0;
        int i = 0, j = m - 1;
        while (i < n && j >= 0)
        {
            int x = arr[i][j];
            if (x > val)
                  j--;
            else
            {
                count += j + 1;
                near = max(x, near);//时刻记录最接近val的数字是啥
                i++;
            }
        }
        return Info(near,count);
    }
};