#include<iostream>
#include<vector>
using namespace std;

class RobotWalk
{
public:
	int robotWalk(int N, int S, int E, int K)
	{
		return f(N, S, K, E);
	}
	int f(int N, int cur, int rest, int E)
	{
		if (rest == 0)//base case 不能再走的时候看看到没到终点,到了就是一种方法
			return cur == E ? 1 : 0;
		//到左右边界时只能往一个方向走
		if (cur == 1)
			return f(N, cur + 1, rest - 1, E);
		if (cur == N)
			return f(N,cur-1,rest-1,E);
		//其余位置,就是左方向+右方向的方法
		return f(N, cur + 1, rest - 1, E) + f(N,cur-1,rest-1,E);
	}
	//可变参数只有 rest cur, 初始化状态是f(K,S),只要rest cur确定,那么他的返回值一定确定
	// f(k,s)=f(k-1,s+1) or f(k-1,s-1) 
	// 假设 k=4,s=2 f(4,2)=f(3,1)+f(3,3)
	// f(3,1)=f(2,2) f(3,3)=f(2,2)+f(2,4)
	// f(2,2)=f(2,1) ,在以二叉树结构理解f(4,2)时,发现f(2,2)被重复求解,
	//暴力递归的过程中会存在重复计算一个值的情况,如果将某一个装态的值记录,下次需要他的时候直接查表即可
	//空间换时间,
	//rest K...1 cur 1...N
	//开空间只要开够就行
public:
	int robotWalk2(int N, int S, int E, int K)
	{
		vector<vector<int>>dp(K+1,vector<int>(N+1,-1));//-1代表这个位置没有计算过

		return f2(N, S, K, E,dp);
	}
	int f2(int N, int cur, int rest, int E, vector<vector<int>>&dp)
	{
		//如果计算过这个值就直接返回
		if (dp[rest][cur] != -1)
			return dp[rest][cur];

		if (rest == 0)//base case 不能再走的时候看看到没到终点,到了就是一种方法
		{
			dp[rest][cur]= cur == E ? 1 : 0;//1
			return dp[rest][cur];
		}
		if (cur == 1)
			dp[rest][cur] = f(N, cur + 1, rest - 1, E);
		else if (cur == N)
			dp[rest][cur] = f(N, cur - 1, rest - 1, E);
		else
			dp[rest][cur] = f(N, cur + 1, rest - 1, E) + f(N, cur - 1, rest - 1, E);
		return dp[rest][cur];
	}
	//暴力递归是K层的二叉树,O(2^K)
	//记忆化搜索O(K*N)
	//每一个各自只计算一次,下一次直接查询每个位置的是O(1),表的规模是K*N
	//画出表结构,分析位置依赖->严格表结构
	//列:cur(1~N) 行:rest(0~K) return dp[S][K] 即从哪个位置出发rest=0时
	int dpWay(int N, int K, int S, int E)
	{
		vector<vector<int>> dp(K+1,vector<int>(N+1));
		//from 1
		dp[0][E] = 1;
		for (int rest = 1; rest <= K; rest++)
		{
			for (int cur = 1; cur <= N; cur++)
			{
				if (cur == 1)
					dp[rest][cur] = dp[rest - 1][cur + 1];
				else if (cur == N)
					dp[rest][cur] = dp[rest - 1][cur - 1];
				else
					dp[rest][cur] = dp[rest - 1][cur + 1] + dp[rest - 1][cur - 1];
			}
		}
		return dp[S][K];
	}
};