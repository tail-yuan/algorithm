
//https://leetcode.cn/problems/super-washing-machines/?utm_source=LCUS&utm_medium=ip_redirect&utm_campaign=transfer2china
//洗衣机问题:只专注于某一个位置i,以单点研究做决策
//1. 假设i位置左侧需要a件衣服才能达到平均,右侧多b件衣服达到平均
//那么就需要将b往左侧扔b轮,轮数 count=max(abs(a),abs(b))
//问i位置经历多少轮才能安静,就是不需要经他衣服
//2. 如果i位置左侧富裕a,右侧也富裕b,说明要往i位置添加衣服,但是由于一边肯定有剩,所以
//以为要消停的轮数也是count=max(a,b)
//3. 如果i位置左侧欠a,右侧欠b,那么要count=a+b
//方便处理,使用数组存放i位置左侧部分累加和,
//算出每个位置的轮数,那么所求肯定是所需轮数最大的,因为你要满足所有位置需要满足
#include<iostream>
#include<vector>
using namespace std;

class Solution
{
public:
    int findMinMoves(vector<int>& nums)
    {
        int n = nums.size();
        if (n == 0)return 0;
        int sum = 0;
        for (auto e : nums)
            sum += e;
        if (sum % n != 0) return -1;
        int avg = sum / n;
        int leftSum = 0, ans = 0;
        for (int i = 0; i < n; i++)
        {
            int leftRest = leftSum - i * avg;
            int rightRest = (sum - leftSum - nums[i]) - (n - i - 1) * avg;
            if (leftRest < 0 && rightRest < 0)
                ans = max(ans, abs(leftRest) + abs(rightRest));
            else
                ans = max(ans, max(abs(leftRest), abs(rightRest)));
            leftSum += nums[i];
        }
        return ans;
    }
};
