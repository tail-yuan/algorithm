//有一个长度为 n 的按严格升序排列的整数数组 nums ，在实行 search 函数之前，
//在某个下标 k 上进行旋转，使数组变为[nums[k], nums[k + 1], ....., nums[nums.length - 1], nums[0], nums[1], ......., nums[k - 1]]。
//给定旋转后的数组 nums 和一个整型 target ，
//请你查找 target 是否存在于 nums 数组中并返回其下标（从0开始计数），如果不存在请返回 - 1。
//
//数据范围：
//要求：空间复杂度  ，时间复杂度
//
//比如，数组[0, 2, 4, 6, 8, 10]在下标3处旋转之后变为[6, 8, 10, 0, 2, 4], 
//当给定target为10时，10的下标是2，target为3时，nums数组中不存在3，所以返回 - 1
//当然笔试可以使用hashMap<key,index>即可,<O(N),O(N)>
#include<iostream>
#include<vector>
using namespace std;
//旋转之后左右区间各自有序,
//使用单调性,使用二分查找<O(logN),O(1)>
class RotateArrFindIndex
{
public:
	int search(vector<int>& nums, int target)
	{
		int left = 0, right = nums.size() - 1;
		while (left <= right)
		{
			int mid = left + (right - left) / 2;
			if (nums[mid] == target)
				return mid;
			if (nums[left] < nums[mid])// mid属于左半区间有序
			{
				if (nums[left] < target && target < nums[mid])
					right = mid - 1;
				else
					left = mid + 1;
			}
			else//mid属于右边区间有序
			{
				if (nums[mid] < target && target < nums[right])
					left = mid + 1;
				else
					right = mid - 1;
			}
		}
		return -1;
	}
};