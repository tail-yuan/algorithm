
//给定一个数组arr，你可以在每个数字之前决定+或者但是必须所有数字都参与再给定一个数target，
//请问最后算出target的方法数是多少?每一种方法必须得用到所有的数字组合

#include<iostream>
#include<vector>
using namespace std;
//子问题:没到达一个节点都需要考虑传来的index位置的数字是+还是-
//每个节点都可能是target值,此时要记录count.但是题干要求每一个数都得用到,那么结果肯定在叶子节点上
class Solution
{
	int count;
	int aim;
	int n;
public:
	int getWays(int target, vector<int>& arr)
	{
		aim = target;
		n = arr.size();
		dfs(arr, 0,0);
		return count;
	}
	void dfs(vector<int>& arr, int index,int path)
	{
		if (index == n)
		{
			if (path == aim)
				count++;
			return;
		}
		dfs(arr, index + 1, path + arr[index]);
		dfs(arr, index + 1, path - arr[index]);
	}
};