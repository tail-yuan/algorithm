#include"head.hpp"
//情况的划分
//一:不使用魔法卷轴,全是正数,直接累加
//二:使用一次魔法卷轴并且是必须使用
		//1. 第i个位置的数字不在卷轴区间上,dp[i]=dp[i-1]+arr[i]
		//2. 第i个位置的数字在卷轴区间上,[...,i]从i往左扩区间,知道找到最大前缀和时停止.
				//可能一直向前都包含了,都是负数,所以 maxSum=max(sum,0);最大前缀和最小是0
//三:使用两次
//[0,i-1]最大前缀累加和,[i,n-1]也可以求后缀和,从右往左遍历,5-5,right[4]:从4-5最大和,dp[3,5]从3到5最大和...
//[0,i-1][i,n-1]分别用一遍,然后将两个最大累加和相加
//[0,1] [2,n-1]
//[0,2] [3,n-1]
class Solution
{
public:
	int zuo(vector<int>& arr)
	{
		int n = arr.size();
		//情况一
		int p1 = 0;
		for (int num : arr)
		{
			p1 += num;
		}
		//情况二
		vector<int> dp(n);
		//dp[0]=0 前一个数还必须用卷轴之后就是0
		int sum = arr[0];
		//int maxSum = sum;
		int maxSum = max(sum,0);
		for (int i = 1; i < n; i++)
		{
			//不包含
			int z1 = dp[i - 1] + arr[i];
			//包含
			int z2 = maxSum;
			dp[i] = max(z1,z2);

			sum += arr[i];
			maxSum = max(maxSum,sum);
		}
		int p2 = dp[n - 1];
		//使用两次
	}
	//O(N)遍历四遍数组
	int MagicScrollProbelm(vector<int>& arr)
	{
		int n = arr.size();
		//1. 
		int p1 = 0;
		for (auto num : arr)
		{
			p1 += num;
		}
		//2. 
		vector<int>left(n);
		int sum = arr[0];
		int maxSum = max(sum,0);
		for (int i = 1; i < n; i++)
		{
			//1. 
			int z1= left[i - 1] + arr[i];
			//2. 
			int z2 = maxSum;
			left[i] = max(z1, z2);

			sum += arr[i];
			maxSum = max(maxSum,sum);
		}
		int p2 = left[n - 1];
		//3. 
		vector<int>right(n);
		sum = arr[n - 1];
		maxSum = max(sum, 0);
		for (int i = n-2; i>=0; i--)
		{
			int z1 = right[i + 1] + arr[i];
			int z2 = maxSum;
			right[i] = max(z1, z2);

			sum += arr[i];
			maxSum = max(maxSum, sum);
		}
		int p3 = INT_MIN;
		for (int i = 1; i < n; i++)
		{
			p3 = max(p3,left[i-1]+right[i]);
		}

		return max(p1,max(p2,p3));
	}
};