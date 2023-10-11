
//https://leetcode.cn/problems/boats-to-save-people/?utm_source=LCUS&utm_medium=ip_redirect&utm_campaign=transfer2china
//给定数组 people 。people[i]表示第 i 个人的体重 ，船的数量不限，
//每艘船可以承载的最大重量为 limit。每艘船最多可同时载两人，但条件是这些人的重量之和最多为 limit。
//返回 承载所有人所需的最小船数 。

//题解:
//1. 排序 如果有一个人的最大体重已经大于limit肯定走不了
//2. 查找到limit/2的位置即为left,下一个位置即为right
//3. if [left]+[right]>limit,flag[left]=false,left--,
//	 else if [left]+[right]<limit,y=right,right++,直到不能再往右,
// 贪心的让 left的前right-y个,去分别匹配[y,right]的人分别坐一艘船,这样可以让更小的那些去匹配更大的
// 从而做到坐更少的船只.flag[...]=true
// 往两边走,
// 1. 可能左侧先耗尽结束循环,此时
//		船只的数量就是 flag[]=true的个数/2
//			+ flag[]=false的个数/2(可能是奇数,所以向上取整,单独坐一艘船)跟体重大的陪不了,但是和小的可以
//			+ n-right(这些体重太大只能自己坐一艘船)
// 2. 可能右侧先耗尽,此时:
//		船只的数量就是 flag[] = true的个数 / 2
//			+ flag[]=false的个数/2(可能是奇数,所以向上取整,单独坐一艘船)跟体重大的陪不了,但是和小的可以
//公式就是flag[]=true的个数/2
//			+ flag[]=false的个数/2
//			+ n-right(2时为0)

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution
{
public:
	int numRescueBoats(vector<int>& arr, int limit)
	{
		if (arr.size() == 0)
			return 0;
		int n = arr.size();
		sort(arr.begin(), arr.end());
		if (arr[n - 1] > limit) return -1;
		//1. 首先找到left位置 <=limit/2
		int left = -1;
		//left=FindHalfLimitIndex(arr, limit);// 77/78,有一个最长的计算错误
		for (int i = n - 1; i >= 0; i--)
			if (arr[i] <= limit / 2)
			{
				left = i; 
				break;
			}

		if (left == -1) return n;//说明都是大于limit/2只能自己一艘船

		int tmp = left;
		int right = left + 1;
		int noUse = 0;
		while (left >= 0)
		{
			int solved = 0;
			while (right < n && arr[left] + arr[right] <= limit)
				right++, solved++;
			if (solved == 0)
				noUse++, left--;
			else
				left = max(-1, left - solved);
		}
		//只算左区间中有几个used
		//noUse肯定都集中在左边,etc如果为0,代表是右边先耗尽,体重大的都得到了配对安置.
		int all = tmp + 1;
		int use_boat = all - noUse;
		int etc = (n - all-use_boat);
		return use_boat + ((noUse + 1) >> 1) + etc;
	}
	int FindHalfLimitIndex(vector<int>& arr, int limit)
	{
		int target = limit / 2;
		int l = 0, r = arr.size() - 1;
		while (l < r)
		{
			int mid = l + (r - l + 1) / 2;
			if (arr[mid] == target)
				return mid;
			else if (arr[mid] < target)
				l = mid;
			else
				r = mid - 1;
		}
		return l;
	}
};