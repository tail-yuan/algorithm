#include<iostream>
#include<vector>
#include<stack>
using namespace std;

//每一个数,找到最大子数组,其中这个数是最小值,指标=最小值*子数组累加和,此时这个数的指标最大
//最后选出最大的指标即可
//使用单调栈,
//找到这个数左边最近比他小的下标为left,找到右边最近比他小的下标为right,这个范围[left,right]就是他的子数组
//它就是这个区域的最小值,然后运算即可
//T=O(N)


//[0,a)求和
int GetMax(vector<int>& arr)
{
	//辅助数组arr[i]表示前i项的累加和
	vector<int>sums(arr.size());
	for (int i = 1; i < arr.size(); i++)
		sums[i] = sums[i - 1] + arr[i];
	
	stack<int> st;
	int maxSum = 0;
	for (int i = 0; i < arr.size(); i++)
	{
		while (!st.empty() && arr[st.top()] >= arr[i])//i位置的值>栈顶
		{
			int targetIndex = st.top(); st.pop();
			//自己累加和-左边界累加和=自己子数组累加和
			int sum = st.empty() ? sums[i - 1] : (sums[i - 1] - sums[st.top()] * arr[targetIndex]);
			maxSum = max(maxSum, sum);
		}
		st.push(i);
	}
	//说明现在是有序的,也就是没找到右边比他小的,右边界直接定位size-1
	while (!st.empty())
	{
		int j = st.top(); st.pop();
		int sum = st.empty() ? sums[arr.size() - 1] : (sums[arr.size() - 1] - sums[st.top()])* arr[j];
		maxSum = max(maxSum, sum);
	}
	return maxSum;
}