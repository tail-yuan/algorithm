#include<iostream>
#include<vector>
using namespace std;
//https://leetcode.cn/problems/jump-game-II/
//在step步内能到达的最远位置cur,如果我多走一步能到达的最远位置next
//如果step增加,cur=next,就是给cur准备的,next=x,在步数不变区间更新next值,
//即最近一步能够覆盖的区间内index<=cur,更新next值.
//当到达结尾时,step就是最少步数

class Solution1
{
public:
	int jump(vector<int> nums) 
	{
		int n = nums.size();
		if (n == 0)
			return 0;
		int step = 0, cur = 0, next = nums[0];
		for (int i = 0; i < n; i++)
		{
			if (i > cur)
				step++, cur = next;
			next = max(next, i + nums[i]);
		}
		return step;
	}
};
//https://leetcode.cn/problems/jump-game/description/
class Solution
{
public:
	bool canJump(vector<int>& nums) 
	{
		int n = nums.size();
		int fast = 0;
		int cur = 0;
		for (int i = 0; i < n; i++)
		{
			if (i <= cur)
			{
				fast = max(fast, i + nums[i]);
				if (fast >= n-1)
					return true;
			}
			cur = fast;
		}
		return false;
	}
};