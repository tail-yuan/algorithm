#include<iostream>
#include<vector>
#include<string>
using namespace std;

//1. �ж������Ƿ�����,ʹ��count����,����������count++,����������,count--
// ��������г���count<0˵��������
// ����������֮��count!=0,˵��ʧ��
//2. ��������ٵ���������ʹ����������,��Ҫ������ٸ�����
// ��������г���count<0˵�������Ŷ���,��һ������ans++,count=0,�����Ҹ�������һ��������
// ����������֮��count!=0,count>0,˵�������Ŷ���,������count�������Ž���ƥ�伴��

class count
{
public:
	int needParentheses(string str)
	{
		int count = 0;
		int ans = 0;
		for(int i=0;i<str.size();i++)
		{
			if (str[i] == '(')
				count++;
			else //')' count ��Ҫ--
			{
				if (count == 0)//��-=-1,�������һ��֮��,count��������
					ans++;
				else
					count--;
			}
		}
		return ans + count;
	}
};

class CoinsWays
{
public:
	int ways(vector<int>& arr,int aim)
	{
		return process(arr,0,aim);
	}
	int process(vector<int>& arr, int index, int rest)
	{
		if (index == arr.size())
			return rest == 0 ? 1 : 0;
		int ways = 0;
		for (int count = 0; count * arr[index] <= rest; count++)
		{
			ways += process(arr,index+1,rest-count*arr[index]);
		}
		return ways;
	}
	//1.�ҿɱ����,index [0,n] rest[0,aim]
	//2.dp[n+1][aim+1] 
	//3.����base case ��ʼ�� dp[n][0] =1,dp[n][1..aim]=0
	//4.ȷ������,��������,��ֹ״̬dp[0][aim]
	// O(N*aim) ��ǰö������O(aim)=>O(N*aim^2)
	// ͬһ��,�����������ǰ���,���Դ�ǰ������,ֱ��ȡֵ�ķ�ʽ
	int ways2(vector<int >& arr, int aim)
	{
		int n = arr.size();
		if (n <= 0)return 0;
		vector<vector<int>>dp(n+1,vector<int>(aim+1));
		dp[n][0] = 1;
		for (int i = 1; i < aim + 1; i++)
			dp[n][i] = 0;
		for (int i = n - 1; i >= 0; i--)
		{
			//ͬһ��֮���Ԫ�ػ���Ӱ��,���� �����һ��Ǵ��ҵ�����һ����
			for (int j = 0; j <= aim; j++)
			{
				int ways = 0;
				for (int count = 0; count * arr[i] <= j; count++)
				{
					//ways += process(arr, index + 1, rest - count * arr[index]);
					ways += dp[i+1][j-count*arr[i]];
					dp[i][j] = ways;
				}
			}
		}
		return dp[0][aim];
	}
	int ways3(vector<int >& arr, int aim)
	{
		int n = arr.size();
		if (n <= 0)return 0;
		vector<vector<int>>dp(n + 1, vector<int>(aim + 1));
		dp[n][0] = 1;
		for (int i = 1; i < aim + 1; i++)
			dp[n][i] = 0;
		for (int i = n - 1; i >= 0; i--)
		{
			//ͬһ��֮���Ԫ�ػ���Ӱ��,���� �����һ��Ǵ��ҵ�����һ����
			for (int j = 0; j <= aim; j++)
			{
				//int ways = 0;
				//for (int count = 0; count * arr[i] <= j; count++)
				//{
				//	//ways += process(arr, index + 1, rest - count * arr[index]);
				//	ways += dp[i + 1][j - count * arr[i]];
				//	dp[i][j] = ways;
				//}
				dp[i][j] = dp[i+1][j];
				if (j - arr[i] >= 0)
					dp[i][j]+=dp[i][j-arr[i]];
			}
		}
		return dp[0][aim];
	}
};
class BobDie
{
public:
	int process(int N, int M, int row, int col, int rest)
	{
		if (row<0 || col<0 || row>N || col>M)
			return 0;
		if (rest == 0)
			return 1;
		int res = process(N, M, row - 1, col, rest - 1) +
			process(N, M, row + 1, col, rest - 1) +
			process(N, M, row, col - 1, rest - 1) +
			process(N, M, row, col + 1, rest - 1);
		return res;
	}
	string bob1(int N, int M, int i, int j, int k)
	{
		//���������
		int res = process(N, M, i, j, k);
		int all = pow(4, k);
		int gcd = get_gcd( all,res);
		string ret = "";
		return ret + to_string(res / gcd) + " / "+to_string(all/gcd);
	}
	int get_gcd(int x, int y)
	{
		return y == 0 ? x : get_gcd(y,x%y);
	}

	//1. row [0,N] col[0,M] rest[k,0]
	//2. dp[N+2][M+2][k+1]
	//3. dp[][][0]=1
	//4. �������Ͻ���,��ֹ״̬->dp[i+1][j+1][k]
	int bob2(int N, int M, int i, int j, int k)
	{
		vector<vector<vector<int>>>dp(N+2,vector<vector<int>>(M+2,vector<int>(k+1)));
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= M; j++)
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
		return dp[i+1][j+1][k];
	}
};
class RobotWalk
{
public:
	int robotWalk(int N, int S, int E, int K)
	{
		return f(N,S,E,K);
	}
	int f(int N, int cur, int E, int rest)
	{
		if (rest == 0)
			return cur == E ? 1 : 0;
		if (cur == 1)
			return f(N,cur+1,E,rest-1);
		if (cur == N - 1)
			return f(N, cur - 1, E, rest - 1);
		return f(N,cur+1,E,rest-1)+f(N,cur-1,E,rest-1);
	}
	//1. cur[0,N] rest[0,K]
	//2. dp[N+1][K+1]
	//3. dp[E][0]=1 dp[...][0]=0
	//4. ��ֹ:dp[S][K] dp[cur][rest]
	int robotWalk2(int N, int S, int E, int K)
	{
		vector<vector<int>>dp(N+1,vector<int>(K+1));
		dp[0][E] = 1;
		for (int cur = 1; cur <= N; cur++)
		{
			for (int rest = 1; rest <= K; rest++)
			{
				if (cur == 1)
					dp[cur][rest]=dp[cur + 1][rest - 1];
				if (cur == N - 1)
					dp[cur][rest] = dp[cur + 1][rest - 1];
				dp[cur][rest] = dp[cur + 1][rest - 1] + dp[cur + 1][rest - 1];
			}
		}
		return dp[S][K];//��ʼֵ?
	}
};