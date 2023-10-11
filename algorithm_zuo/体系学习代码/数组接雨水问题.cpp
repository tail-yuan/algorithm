#include<iostream>
#include<vector>
using namespace std;

// 无法实现求解每个波谷,然后将雨水累加.你刚求解的小波谷可能是在一个大的波谷中,那么你刚求解的就完全失去意义
// 只关注index位置至少能存储多少水->是左侧区间的最大值leftMax rightMax的较小值减去arr[index]
// 如果本身是最大的值,返回0,代表无法这个位置存储水
//=> max(min(leftMax,rightMax)-arr[i],0)
// 法一:采用辅助数组,一个记录tmp[i]代表[0,i-1]位置最大值
//					,一个记录tmp[i]代表[i+1,arr.size()-1]区间最大值
// <O(N),O(N)>
// 法二: 使用有限几个变量 <O(N),O(1)>
//	左右指针
//	左右最大值哪边小,lr哪个位置的存数值就被确定
// 0位置 n-1位置肯定存不住水,忽略
//	
class GetSumWater
{
public:
	//<O(N^2),O(1)>
	int getWater1_1(vector<int>& arr)
	{
		if (arr.size()<3)//只有两个值也存不住水
			return 0;
		int ret = 0;
		for (int i = 0; i < arr.size() - 1; i++)
		{
			int leftMax = 0;
			int rightMax = 0;
			for (int l = 0; l < i; l++)
				leftMax = max(arr[l],leftMax);
			for (int r = i + 1; i < arr.size(); i++)
				rightMax = max(arr[r],rightMax);
			ret += max(0,min(leftMax,rightMax)-arr[i]);
		}
	}
	//<O(N), O(N)>
	int getWater1_2(vector<int>& arr)
	{
		if (arr.size() < 3)//只有两个值也存不住水
			return 0;
		int n = arr.size() - 2;
		vector<int>leftMax(n);
		vector<int>rightMax(n);
		// leftMax[i]记录的是前i个值的最大值
		for (int i = 1; i < n; i++)
			leftMax[i] = max(leftMax[i-1],arr[i]);
		//rightMax[i]代表[i+1,arr.size()-2]区间最大值
		rightMax[n - 1] = arr[n + 1];
		for (int i = n - 2; i >= 0; i--)
			rightMax[i] = max(rightMax[i+1],rightMax[i+2]);

		int ret = 0;
		for (int i = 1; i <= n; i++)
			ret += max(0, min(leftMax[i - 1], rightMax[i-1] - arr[i]));
		return ret;
	}
	int getWater2(vector<int>& arr)
	{
		if (arr.size() < 3)//只有两个值也存不住水
			return 0;
		int ret = 0;
		int leftMax = arr[0];
		int rightMax = arr[arr.size()-1];
		//下标代替双指针
		int l = 1;
		int r = arr.size() - 2;
		while (l <= r)
		{
			if (leftMax <= rightMax)//只专注于l位置至少存多少水的门槛已经限定,就是leftMax
			{
				ret += max(0,leftMax-arr[l]);
				leftMax = max(leftMax,arr[l]);//if need 更新leftMax
				l++;
			}
			else//只专注于r位置至少存多少水的门槛已经限定,就是rightMax
			{
				ret += max(0,rightMax-arr[r]);
				rightMax = max(rightMax,arr[r]);
				r--;
			}
		}
		return ret;
	}
};