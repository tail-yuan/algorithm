//https://leetcode.cn/problems/trapping-rain-water/

//题解:
//只专注于i位置能存放几格水
//[0,i-1]区间最大值是left, [i+1,n-1]区间最大值是right
//那么i位置能存放水的最大值一定能够涨到min(left,right),在你不知道多远的位置left或者right给你兜底
//当然别忘了减去arr[i].
//如果left,right最大值还没自己高呢,说明i位置存储水是0
//辅助数组存放前i-1中最大值是多少,i+1~n-1最大值是多少

//双指针方式
// https://www.bilibili.com/video/BV1NV4y1B7ZZ?t=534.5&p=31
//0位置和n-1位置没意义,肯定是0
//l=1,r=n-1,leftMax,rightMax,假设leftmax>rightmax
//就先更新那头的指针位置水量,因为左侧最大值肯定>=leftMax,右侧已经确定了,所以[i]位置就是rightMax-[i]
//划过之后考虑更新rightMax
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int trap(vector<int>& arr)
    {
        int n = arr.size();
        if (n < 2)return 0;
        int l = 1, r = n - 2;
        int leftMax = arr[0], rightMax = arr[n - 1];
        int sum = 0;
        while (l <= r)
        {
            if (leftMax <= rightMax)
            {
                sum += max(0, leftMax - arr[l]);
                leftMax = max(leftMax, arr[l++]);
            }
            else
            {
                sum += max(0, rightMax - arr[r]);
                rightMax = max(rightMax, arr[r--]);
            }
        }
        return sum;
    }
    int trap1(vector<int>& arr) 
    {
        int n = arr.size();
        vector<int>leftArr(n);
        vector<int>rightArr(n);
        for (int i = 0, l = arr[0]; i < n; i++)
        {
            leftArr[i] = max(l, arr[i]);
            if (l < arr[i])
                l = arr[i];
        }
        for (int i = n - 1, r = arr[n - 1]; i >= 0; i--)
        {
            rightArr[i] = max(r, arr[i]);
            if (r < arr[i])
                r = arr[i];
        }

        int sum = 0;
        for (int i = 1; i < n - 1; i++)
        {
            sum += max(0, min(leftArr[i], rightArr[i]) - arr[i]);
        }
        return sum;
    }
};