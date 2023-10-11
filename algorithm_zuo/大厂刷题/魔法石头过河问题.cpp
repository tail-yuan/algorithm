#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//一堆石头,无色,红色,蓝色,
//如果只有红色石头和蓝色石头数目相同时,并且所有石头都有颜色,才能过河
//只能将无色染为其他两种颜色,问最小代价是多少
//给定数组[0,x,y],0代表这个石头无色,x为染色为红色的代价是多少,y为染为蓝色的代价
//[1,.,.]1代表是红色,2代表室蓝色,而且不能改颜色，所以后两个数X无意义

//贪心的思想
//假设所有无色石头都转化为红色,总代价是cost,
//遍历一遍数组后知道应该分配K个无色石头给染成蓝色
//那么在无色石头中选择K个,改换门厅之后使得cost下降最多的几个,染为蓝色即可
class Solution
{
public:
	struct comp
	{
		bool operator()(const vector<int>& x, const vector<int>& y)
		{
			if (x[0] == 0 && y[0] == 0)
			{
				if ((x[1] - x[2]) < (y[1] - y[2]))//让转换代价小的排在前面,最后在全到A之后的总代价加上转换之后的代价即可
					return true;
				else
					return false;
			}
			//当至少一个为有颜色时,怎么排他俩都无所谓
			return false;
		}
	};
	int magicStones(vector<vector<int>>& arr)
	{
		int n = arr.size();
		if (n % 2 != 0)return -1;
		sort(arr.begin(), arr.end(), comp());
		int zero = 0, red = 0, blue = 0;
		int cost = 0;
		for (int i = 0; i < n; i++)
		{
			if (arr[i][0] == 0)
			{
				zero++;
				cost += arr[i][1];
			}
			else if (arr[i][0] == 1)red++;
			else if (arr[i][0] == 2)blue++;
		}
		//其中有一种石头数目大于一半,还不让更改颜色,肯定玩不了
		if (red > (n / 2) || blue > (n / 2))
			return -1;
		blue = zero - ((n / 2) - red);
		for (int i = 0; i < blue; i++)
			cost += arr[i][2] - arr[i][1];//从红到蓝的代价变化多少
		return cost;
	}
};

//类似于司机两地分配最大收益问题或者说最小消耗
//[0,x,y]0号司机分配到A地收益是x,分配到B地收益是y
//问将所有司机均分到两地的最大收益是多少?
// A分配完了,剩下的都去B不也就分好了吗?所以只专注于一个目的地即可
// dfs代表A地还剩下rest个位置时,index号司机选择之后获得的最大收益.
//dfs:到达index下标司机时,有两种选择,去A去B分别产生影响,
//dfs返回值代表index去A或者B之后所获得的收益,选择二者最大的即可
// 
//	//index: [1~n],rest[1~m],多开一行多开一列 dp[n+1][m+1],访问原始数组时注意下标-1
	//根据dfs初始化最后一行,第一列:dp[n][j]=0,dp[i][0]=arr[i-1][1]+dp[i+1][0]
	//dp[i][j]=min(arr[i-1][0]+ dp[i+1][j-1],arr[i-1][1]+ dp[i+1][j])
	//填表顺序: 依赖于i+1,所以从下往上填写,从左往右
	//返回值: dp[0][m]
//使用贪心的方式:
class Solution
{
	int n1;
public:

	int twoCitySchedCost(vector<vector<int>>& arr)
	{
		int N = arr.size();
		vector<int>nums(N);
		int sum = 0;
		for (int i = 0; i < N; i++)
		{
			nums[i] = arr[i][1] - arr[i][0];//记录i号司机从A转化为B使得总代价变化[1]-[0]这么多
			sum += arr[i][0];//先全去A区
		}
		sort(nums.begin(), nums.end());//选中前M个,让总代价减少
		int M = N / 2;
		for (int i = 0;i<M;i++)
		{
			sum += nums[i];
		}
		return sum;
	}
public:

	int twoCitySchedCost2(vector<vector<int>>& arr)
	{
		int n = arr.size(), m = n / 2;
		vector<vector<int>>dp(n + 1, vector<int>(m + 1, 0));
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
public:

	int twoCitySchedCost1(vector<vector<int>>& costs)
	{
		n1 = costs.size();
		int _n = n1 / 2;
		return dfs(costs, 0, _n);
	}
	int dfs(vector<vector<int>>& arr, int index, int rest)
	{
		if (index == n1)
			return 0;
		//A 无剩余位置,都去B吧
		if (rest == 0)
			return arr[index][1] + dfs(arr, index + 1, rest);
		//A剩余位置正好,都来A吧
		if (n1 - index == rest)
			return arr[index][0] + dfs(arr, index + 1, rest - 1);
		int p1 = arr[index][0] + dfs(arr, index + 1, rest - 1);
		int p2 = arr[index][1] + dfs(arr, index + 1, rest);
		return min(p1, p2);
	}
};