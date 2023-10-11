#include<iostream>
#include<vector>
using namespace std;

//给定一个数组arr长度为N， 你可以把任意长度大于0且小于N的前缀作为左部分， 剩下的
//作为右部分。 但是每种划分下都有左部分的最大值和右部分的最大值， 请返回最大的，
//左部分最大值减去右部分最大值的绝对值
// 先确定区间最大值max,无论被划分到哪个部分,一定是max参与运算
//	1. 如果被划分到左部分,如何获取右侧区间中最大值x ,让abs(max-x)最大?
//	右部分区间只要arr[n-1]一个,->只要arr[n-1]值
//		如果右部分中有num >  arr[n-1]=> abs(max-num)<abs(max-arr[n-1])
//		如果右部分中有num< arr[n-1],不满足题意,因为我们要的就是右部分最大值
// 同理,左部分只要arr[0]一个

class MaxABSBetweenLeftAndRight
{
public:
	int getMax1(vector<int>& arr)
	{
		int maxVal = INT_MIN;
		for (int i = 0; i < arr.size(); i++)
			maxVal = max(maxVal,arr[i]);
		return maxVal - min(arr[0],arr[arr.size() - 1]);
	}
	//遍历求最大abs值
	int getMax2(vector<int>& arr)
	{
		int res = INT_MIN;
		int maxLeft = 0;
		int maxRight = 0;
		for (int i = 0; i != arr.size() - 1; i++)
		{
			maxLeft = INT_MIN;
			for (int j = 0; j <= i; j++)
				maxLeft = max(arr[j],maxLeft);
			maxRight = INT_MIN;
			for (int j = 0; j <= i; j++)
				maxRight = max(arr[j], maxRight);
			res = max(abs(maxLeft-maxRight),res);
		}
		return res;
	}
	//辅助数组记录前[i]个中数字最大值,后x个中最大值
	int getMax(vector<int>& arr) 
	{
		int n = arr.size();
		vector<int>lArr(n);
		vector<int>rArr(n);
		lArr[0] = arr[0];
		rArr[n - 1] = arr[n - 1];
		for (int i = 1; i < n; i++)
			lArr[i] = max(lArr[i-1],arr[i]);
		for (int i = n - 2; i >= 0; i--)
			rArr[i] = max(rArr[i+1],arr[i]);
		int maxVal = 0;
		for (int i = 0; i < n - 1; i++)
			maxVal = max(maxVal,abs(lArr[i]-rArr[i]));
		return maxVal;
	}
};