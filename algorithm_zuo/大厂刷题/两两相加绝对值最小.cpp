#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
//题目要求:
//给定一个数组arr，可能有正、有负、有0，无序只能挑选两个数字，
//想尽量让两个数字加起来的绝对值尽量小返回可能的最小的值
//题解:
//如果数组中全是正数,那么选择最小的两个值相加
//如果数组中全是负数,那么选择最大的两个值相加
//如果有正有负有0,那么从小到大排序之后,在正数中找到和负数最接近的数字相加,时刻记录最小值
class Solution
{
public:
	int getMinAbs(vector<int>& arr)
	{
		int n = arr.size();
		int ret = 0;
		if (n < 2)
		{
			for (auto e : arr)
				ret += e;
			return ret;
		}
		sort(arr.begin(), arr.end());
		int target = 0;
		//1. 二分查找的方式确定0的位置,因为0可能不存在,<= > 两部分.可能存在都是负数,或者都是正数
		int pos0 = FindXPos(arr,0);
		if (pos0 < 0)
			return min(arr[0] + arr[1],arr[n-1]+arr[n-2]);
		
		//1.5 为了提升查找最靠近的效率,使用二分查找的方式
		//2. 遍历左区间小于0的部分,在右边>0的部分中找最靠近[i]的
		int ans = INT_MAX;
		for (int i = 0; i < pos0; i++)
		{
			int aim = -arr[i];
			int close= findClosestValue(arr,aim);
			ans = min(ans, close);
		}
		return ans;
	}
	int FindXPos(vector<int>&arr,int aim)
	{
		int n = arr.size();
		int left = 0, right = n - 1;
		int pos0 = -1;
		while (left < right)
		{
			int mid = left + (right - left + 1) / 2;
			if (arr[mid] > aim) right = mid - 1;
			else if (arr[mid] == aim)return mid;
			else left = mid;
		}
		//到这说明没找到
		return pos0;
	}
	int findClosestValue(const std::vector<int>& arr, int x) {
		int left = 0;
		int right = arr.size() - 1;
		while (left <= right) 
		{
			int mid = left + (right - left) / 2;
			if (arr[mid] == x) 
				return arr[mid];
			else if (arr[mid] < x) 
				left = mid + 1;
			else 
				right = mid - 1;
		}
		if (right < 0) 
			return arr[left];
		else if (left >= arr.size()) 
			return arr[right];
		else 
		{
			if (x - arr[right] < arr[left] - x) 
				return arr[right];
			else 
				return arr[left];
		}
	}
};