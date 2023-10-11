#include<iostream>
#include<vector>
using namespace std;
//https://leetcode.cn/problems/jump-game-II/
//��step�����ܵ������Զλ��cur,����Ҷ���һ���ܵ������Զλ��next
//���step����,cur=next,���Ǹ�cur׼����,next=x,�ڲ��������������nextֵ,
//�����һ���ܹ����ǵ�������index<=cur,����nextֵ.
//�������βʱ,step�������ٲ���

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