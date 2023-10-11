#include<iostream>
#include<vector>
#include<string>
using namespace std;

class BobDie
{
public:
	//在N*M的范围内,从(row,col)出发,走rest步在不出界(算活)时,返回生存方法数
	int process(int N, int M, int row, int col, int rest)
	{
		if (row < 0 || row>N || col > M || col < 0)
			return 0;
		if (rest == 0)
			return 1;
		int res = process(N, M, row - 1, col, rest - 1)
			+ process(N, M, row + 1, col, rest - 1)
			+ process(N, M, row, col + 1, rest)
			+ process(N, M, row, col - 1, rest);
		return res;
	}
	string bob1(int N, int M, int i, int j, int k)
	{
		//所有路
		int all = pow(4, k);//每一步到达每个位置有4中选择,走了K步
		int live = process(N, M, i, j, k);
		int gcd1 = gcd(all, live);
		string res = "";
		return res + to_string(live / gcd1) + "/" + to_string(all / gcd1);
	}
	int gcd(int m, int n)
	{
		return n == 0 ? m : gcd(n, m % n);
	}

	string bob2(int N, int M, int i, int j, int k)
	{
		vector<vector<vector<int>>>dp(N + 2, vector<vector<int>>(M + 2, vector<int>(k + 1)));
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
				dp[i][j][0] = 1;
		}
		for (int rest = 1; rest <= k; rest++) {
			for (int row = 1; row <= N; row++) {
				for (int col = 1; col <= M; col++) {
					dp[row][col][rest] = dp[row-1][col][rest-1];
					dp[row][col][rest] += dp[row+1][col][rest-1];
					dp[row][col][rest] += dp[row][col-1][rest-1];
					dp[row][col][rest] += dp[row][col+1][rest-1];
				}
			}
		}
		//所有路
		int all = pow(4, k);//每一步到达每个位置有4中选择,走了K步
		int live = dp[i+1][j+1][k];
		int gcd1 = gcd(all, live);
		string res = "";
		return res + to_string(live / gcd1) + "/" + to_string(all / gcd1);
	}
};