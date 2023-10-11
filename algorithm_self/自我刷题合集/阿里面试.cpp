#include"head.hpp"
//选择一个同学,其他同学数字-1,保证都不为负数,最多能玩多少轮
// 来自阿里笔试
// 牛牛今年上幼儿园了，老师叫他学习减法
// 老师给了他5个数字，他每次操作可以选择其中的4个数字减1
// 减一之后的数字不能小于0，因为幼儿园的牛牛还没有接触过负数
// 现在牛牛想知道，自己最多可以进行多少次这样的操作
// 扩展问题来自leetcode 2141，掌握了这个题原始问题就非常简单了
// leetcode测试链接 : https://leetcode.com/problems/maximum-running-time-of-n-computers/

// 电池给大楼供电问题
// 电池供电时长是有限的,是可以确定区间的[0,累加和(都给一个电脑供电)]
// 所以可以使用二分答案法,给你target时长,看你能不能完成供电
// 返回二分区间中最大值,就是最长时间所求
// 
// 实现函数,给定电池,大楼,标准应该支撑过多少分钟,返回bool值代表能否做到
// 如果x电池值>目标值target,就自己安排到一个楼,不用再切换楼了
// 如果x电池值<目标值target,碎片电池能否给剩余楼层供电
    // 如果碎片电池累加和>楼层数*target,就一定能让所有楼供电target时间
    //(切换供电无消耗,不管怎么安排总能合理安排)
    //https://image-1309381344.cos.ap-nanjing.myqcloud.com/img/image-20230521182626061.png

class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) 
    {
        sort(batteries.begin(),batteries.end());
        int size = batteries.size();
        //数组记录前i个数字的累加和
        vector<long>sums(size);
        sums[0] = batteries[0];
        for (int i = 1; i < size; i++)
        {
            sums[i] = sums[i - 1] + batteries[i];
        }
        long l = 0;
        long m = 0;
        long r = sums[size - 1] / n;

        long ans = -1;
        while (l <= r)
        {
            m = (l + r) / 2;
            if (ok(batteries, sums, m, n))
            {
                ans = m;
                l = m + 1;
            }
            else
            {
                r = m - 1;
            }
        }
        return ans;
    }
    bool ok(vector<int>& arr, vector<long>& sums, long time, int num)
    {
        int l = 0;
        int m = 0;
        int r = arr.size() - 1;
        int left = arr.size();
        while (l <= r)
        {
            m = (l + r) / 2;
            if (arr[m] >= time)
            {
                left = m;
                r = m - 1;
            }
            else
            {
                l = m + 1;
            }
        }
        num -= arr.size() - left;
        long rest = left == 0 ? 0 : sums[left - 1];
        return time * (long)num <= rest;
    }
};