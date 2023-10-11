
//给定规定时间T,在规定时间内,将所有香蕉吃完时设定的一个小时吃香蕉的最小速度k

//吃的速度越快,花费的时间就越小,单调性
//最大速度对应着最小的时间,如果设定香蕉中最大值为吃的速度k,
//所有的速度就都在1~maxVal之间,使用二分查找的方式,查看mid位置设置为速度所需要的时间是否<=T
//找到满足条件的最右边的速度值即为答案
#include<iostream>
#include<vector>
using namespace std;
class Solution
{
public:
    int minEatingSpeed(vector<int>& piles, int h)
    {
        int l = 1;
        int r = 0;
        for (auto e : piles)
            r = max(e, r);
        int ans = 0;
        while (l <= r)
        {
            int mid = l + ((r - l) >> 1);
            if (hours(piles, mid) <= h)
            {
                ans = mid;
                r = mid - 1;
            }
            else
                l = mid + 1;
        }
        return ans;
    }
    //因为如果剩下时间,废废就歇着,所以时间是香蕉个数/速度向上取整
    //经过公式推导之后a/b向上取整的公式就是 (a+b-1)/b
    long hours(vector<int>& nums, int speed)
    {
        long ans = 0;
        int offset = speed - 1;
        for (auto e : nums)
        {
            ans += (e + offset) / speed;
        }
        return ans;
    }
};