//https://www.bilibili.com/video/BV1NV4y1B7ZZ?p=70&vd_source=cc945ef88574fe2db5e814c0c265a4c7
// https://leetcode.cn/problems/heaters/
//供暖站
//对两个数组进行排序,
//这样的话比较i和i+1位置哪个更合适,如果i+1更合适,那么i位置既不是此时房屋的最佳选择,也不是之后所有房屋的最佳选择
//如果i位置是合适的,那么选定i位置,即为此时房屋的最佳选择.
//依次寻找能够实现index位置房屋供暖的供暖站中最短的半径,记录
//然后求出每个最佳供暖站和对应房屋的最大半径
//当发现两个供暖站到达某个房屋的距离相同时,可以选择下一个,也可以不选择
//因为不选择下一个的话,如果他满足下一个位置最小半径时,也会被选中
//但是存在相同火炉点是重复位置的话,不跳会出现重复选中位置.所以得跳
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution 
{
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) 
    {
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        int ans = 0;
        int j = 0;
        for (int i = 0; i < houses.size(); i++)
        {
            while (!best(houses, heaters, i, j))
                j++;
            ans = max(ans, abs(houses[i] - heaters[j]));
        }
        return ans;
    }
    bool best(vector<int>& houses, vector<int>& heaters, int i, int j)
    {
        return j == heaters.size() - 1 || 
            abs(houses[i] - heaters[j]) < abs(houses[i] - heaters[j+1]);
                                    //< 代表 相等的时候返回false,也跳到下一个位置
    }
};