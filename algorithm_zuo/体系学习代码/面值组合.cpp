#include<iostream>
#include<vector>
using namespace std;
//暴力尝试时
//1. 单可变参数维度,最好就是一个int类型,0维参数
//2. 参数个数尽量少
class CoinsWays
{
public:
	//数组中面值钱确定,张数有无数张 ,问有多少种组合的方式凑够aim
	int ways(vector<int>&arr,int aim)
	{
		return process(arr, 0,aim);
	}
	int process(vector<int>& arr, int index, int rest)
	{
		if (index == arr.size())
			return rest == 0 ? 1 : 0;
		int ways = 0;
		//当递归出现枚举的情况时
		for (int count = 0; count * arr[index] <= rest; count++)
			ways += process(arr,index+1,rest-count*arr[index]);
		return ways;
	}
	//1. index [0,N] rest [0,aim]
	//2. dp[0][aim]
	//3. dp[N][1...]=0 dp[N][0]=1
	//4. dp[index][rest]=dp[index+1/*下一行的*/][rest-count*arr[index]],count=0,1,2,3
	//5. 将暴力递归的依赖关系直接抄下来,然后直接把递归改为数组取值
	int ways(vector<int>& arr, int aim)
	{
		int N = arr.size();
		vector<vector<int>> dp(N+1,vector<int>(aim+1));
		dp[N][0] = 1;
		for (int i = 0; i <= aim; i++)
			dp[N][i] = 0;
		for (int index = N - 1; index >=0; index--)
		{
			//因为同一行的不同列之间是不影响的
			for (int rest = 0; rest <= aim; rest++)
			{
				int ways = 0;
				//当递归出现枚举的情况时
				for (int count = 0; count * arr[index] <= rest; count++)
					ways += dp[index + 1][rest - count * arr[index]];
				dp[index][rest] = ways;
			}
		}
		return dp[0][aim];
	}
	//O(N*aim)的格子,每个格子都有枚举的情况,最坏是aim次,所以是O(N*aim*aim)
	//[rest-count*arr[index]],count=0,1,2,3 在index行,求dp[index][rest]需要他下一行的,
	// a:[index+1][rest+0*x] b:[rest-1*x]  c:[rest-2*x] ...这几个遍历出来的值,求和 =a+b+c+...
	// 在index同一行,rest-x位置求解的时候,用到了b +c +... 又遍历了一遍,[index][rest-1*x]=b+c+...
	// 那么就可以把这个遍历优化,[index][rest]=[index][rest-1*x](前个位置) + a
	//只要保证从左向右的顺序,是先求出来的[index][rest-1*x],即可保证[index][rest]
	//且消除了很多无效的,重复的枚举情况
	int ways(vector<int>& arr, int aim)
	{
		int N = arr.size();
		vector<vector<int>> dp(N + 1, vector<int>(aim + 1));
		dp[N][0] = 1;
		for (int i = 0; i <= aim; i++)
			dp[N][i] = 0;
		for (int index = N - 1; index >= 0; index--)
		{
			//因为同一行的不同列之间是不影响的
			for (int rest = 0; rest <= aim; rest++)
			{
				dp[index][rest] = dp[index+1][rest];
				if (rest - arr[index] >= 0)
					dp[index][rest] += dp[index][rest - arr[index]];
			}
		}
		return dp[0][aim];
	}
	//斜率优化版本(画图观察出来的规律优化)
	//看临近行为能否优化枚举行为
};