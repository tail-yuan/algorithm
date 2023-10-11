//题干:
//现有司机N*2人，调度中心会将所有司机平分给A、B两个区域
// 第i个司机去A可得收入为incomeil[0]
// 第i个司机去B可得收入为income[i][1]
//返回所有调度方案中能使所有司机总收入最高的方案，是多少钱.整体最大收入是多少
//题解:
//司机人数必须是偶数才能完成分配,
//https://www.bilibili.com/video/BV1NV4y1B7ZZ?p=5&vd_source=cc945ef88574fe2db5e814c0c265a4c7
#include<iostream>
#include<vector>
using namespace std;
class Solution
{
	int n;
public:
	int maxVal(vector<vector<int>>& arr)
	{
		n = arr.size();
		if (n <= 1 || n % 2 != 0)
			return 0;
		int m = n / 2;
		return process(arr,0,m);
	}
	//process ,给定函数一个index相信process能够将index之后的所有司机分配完毕并且保证AB区域数量相同
	//A区域还剩下rest个名额
	//返回值是分配完成之后的整体最大收入
	int process(vector<vector<int>>& arr,int index,int rest)
	{
		if (index == n)
			return 0;
		//还有司机,1. 只能去A 2. 只能去B 3. AB都有空间,涉及到选择
		if (n - index == rest)
			return arr[index][0] + process(arr,index+1,rest-1);
		if (rest == 0)//A 区域已经没有空位置了
			return arr[index][1] + process(arr, index + 1, rest);
		int p1= arr[index][0] + process(arr, index + 1, rest - 1);
		int p2= arr[index][1] + process(arr, index + 1, rest);
		return max(p1, p2);
	}
	//1. 开空间,index[0,N] rest[0,n/2] dp[N][N/2],因为返回dp[0][n/2],多开一行一列,够用就行
	//2. 填表顺序,因为依赖于index+1,rest-1所以从右往左,从上往下
	int maxVal2(vector<vector<int>>& arr)
	{
		n = arr.size();
		int m = n / 2;
		vector<vector<int>>dp(n+1, vector<int>(m+1));
		for (int i = n - 1; i >= 0; i--)
		{
			for (int j = 0; j <= m; j++)
			{
				if (n - i == j)
					dp[i][j] = arr[i][0] + dp[i + 1][j - 1];
				else if (j == 0)
					dp[i][j] = arr[i][1] + dp[i + 1][j];
				else
				{
					int p1 = arr[i][0] + dp[i + 1][j - 1];
					int p2 = arr[i][1] + dp[i + 1][j];
					dp[i][j] = max(p1, p2);
				}
			}
		}
		return dp[0][m];
	}
};

//员工分配AB两地最小消耗
//https://leetcode.cn/problems/two-city-scheduling/submissions/
class Solution2
{
	int n;
public:
	//dfs版本:
	//重复子问题: 到达index位置的人需要考虑去A还是去B,选出最小的费用返回给上一层,需要考虑的是A地区的剩余位置rest
	int twoCitySchedCost1(vector<vector<int>>& arr)
	{
		n = arr.size();
		int m = n / 2;
		return dfs(arr, 0, m);
	}
	int dfs(vector<vector<int>>& arr, int index, int rest)
	{
		if (index == n)
			return 0;
		//还有员工待分配 1. A 无空位只能去B 2. 只能去A 3. AB之间选择最小消耗
		if (rest == 0)
			return arr[index][1] + dfs(arr, index + 1, rest);
		if (n - index == rest)
			return arr[index][0] + dfs(arr, index + 1, rest - 1);
		int p1 = arr[index][0] + dfs(arr, index + 1, rest - 1);
		int p2 = arr[index][1] + dfs(arr, index + 1, rest);
		return min(p1, p2);
	}
	//改为dp index[0,n] rest[0,m]
	//填表时严格依赖于index+1,rrest-1所以填表顺序是从右往左,从上往下
	int twoCitySchedCost(vector<vector<int>>& arr)
	{
		n = arr.size();
		int m = n / 2;
		vector<vector<int>>dp(n + 1, vector<int>(m + 1));
		for (int i = n - 1; i >= 0; i--)
		{
			for (int j = 0; j <= m; j++)
			{
				if (j == 0)
					dp[i][j] = arr[i][1] + dp[i + 1][j];
				else if (n - i == j)
					dp[i][j] = arr[i][0] + dp[i + 1][j - 1];
				else
				{
					int p1 = arr[i][1] + dp[i + 1][j];
					int p2 = arr[i][0] + dp[i + 1][j - 1];
					dp[i][j] = min(p1, p2);
				}
			}
		}
		return dp[0][m];
	}
};