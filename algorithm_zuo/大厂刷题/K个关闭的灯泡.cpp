//给定灯泡数组nums,nums[i]表示在第i+1小时将nums[i]号灯泡点亮,并且保证数组nums中无重复值
//也就是不会重复的电量同一个灯泡,
//给定时刻,这个时刻保证两个电量灯泡之间存在K个灯泡是不亮的,
//问,最早出现这种现象的时刻是什么时刻?

//answer1:
//首先将原灯泡数组转化为arr,arr[i]代表第i+1号灯泡在arr[i]时刻被点亮,因为保证了灯泡不重复
//https://www.bilibili.com/video/BV1NV4y1B7ZZ?t=776.5&p=77
//在arr数组中,假设ab位置时满足条件的,中间有K个灯泡,形成的窗口,
//那么a和b的灯泡点亮的时间中的最大值应该<中间窗口中电量时间的最小值,才能保证满足条件
//即 max(a,b)<min([a+1,b-1]),取二者点亮时间最大值是为了保证两个灯都亮,都小于区间最小值,是为了
//保证中间的等在这一时刻都是不亮的.
//记录窗口中最小值问题,使用双指针固定窗口大小k遍历数组,来记录满足条件的时刻,最后取最小值即可
//O(N)拿下,但是需要辅助队列来记录区间最小值

//answer2: 不适用辅助队列记录区间最小值
//1. 数组转换
//2. left,right,中间间隔K个灯泡,验证[left+1,right-1]区间中每一个位置Mid的点亮时间是否都大于max([left],[right])
//	2.1 如果都大于此时说明以left为开头的区间是满足情况的,记录答案,max([left],[right]),
//		然后向后移动,只要[left+1,right-1]区间是可以的,那么必然都> max([left],[right]),那么以left+1为开头的
//		K个灯泡组成的区间一定是不满足的,为什么?因为中间插了一个必然小于[left+1]的灯泡不满足条件,所以
//		left=mid,直接跳到此时right位置,right=left+k
//	2.2 如果存在mid位置不满足,left=mid,right=left+k
//三个指针都不回退,O(N)搞定



#include<iostream>
#include<vector>
using namespace std;
class Solution
{
public:
	int KEmptySlots1(vector<int>& nums, int k)
	{
		int n = nums.size();
		vector<int>arr(n);
		for (int i = 0; i < n; i++)
			arr[nums[i] - 1] = i+1;
		int ans = INT_MAX;
		if (k == 0)//间隔0个灯泡,那么就求解保证两相邻灯泡都点亮的时间最小的即可
		{
			for (int i = 1; i < n; i++)
				ans = min(ans, max(arr[i - 1], arr[i]));
		}
		else
		{
			vector<int>minq(n);//辅助队列
			int l = 0, r = -1;
			//预填充进辅助队列中,前K个元素的最小值进行记录
			for (int i = 1; i < n && i < k; ++i)
			{
				while (l <= r && arr[minq[r]] >= arr[i])
					r--;
				minq[++r] = i;
			}
			//以后指针r为中止控制条件,因为你要保证窗口的存在
			for (int i = 1, j = k; j < n - 1; i++, j++)
			{
				while (l <= r && arr[minq[r]] >= arr[j])
					r--;
				minq[++r] = j;
				int cur = max(arr[i-1], arr[j+1]);
				if (arr[minq[l]] > cur)
					ans = min(ans, cur);
				if (minq[l] == i)//最小值过期处理
					l++;
			}
		}
		return ans == INT_MAX ? -1 : ans;
	}
public:
	int KEmptySlots2(vector<int>& nums, int k)
	{
		int n = nums.size();
		vector<int>arr(n);
		for (int i = 0; i < n; i++)
			arr[nums[i] - 1] = i + 1;
		int ans = INT_MAX;
		for (int left = 0, mid = 1, right = k + 1; right < n; mid++)
		{
			// 验证指针mid,所以注意是mid++
			// mid 永远不和left撞上的！
			// 1) mid在left和right中间验证的时候，没通过！
			// 2) mid是撞上right的时候

			if (arr[mid] > max(arr[left], arr[right]))
			{
				//满足情况继续验证
			}
			else// (arr[mid] <= max(arr[left], arr[right]))
			{
				if (mid == right)//mid验证已经撞到区间结尾right了,验证通过,记录答案
				{
					int cur = max(arr[left], arr[right]);
					ans = min(ans, cur);
					left = mid;
					right = mid + k+1;
				}
				else//验证不通过,left跳过,
				{
					left = mid;
					right = mid + k + 1;
				}
			}
		}
		return ans == INT_MAX ? -1 : ans;
	}
public:
	int KEmptySlots2_(vector<int>& nums, int k)
	{
		int n = nums.size();
		vector<int>arr(n);
		for (int i = 0; i < n; i++)
			arr[nums[i] - 1] = i + 1;
		int ans = INT_MAX;
		for (int left = 0, mid = 1, right = k + 1; right < n; mid++)
		{
			if (arr[mid] <= max(arr[left], arr[right]))
			{
				if (mid == right)//mid验证已经撞到区间结尾right了,验证通过,记录答案
				{
					int cur = max(arr[left], arr[right]);
					ans = min(ans, cur);				
				}
				left = mid;
				right = mid + k + 1;
			}
		}
		return ans == INT_MAX ? -1 : ans;
	}
};