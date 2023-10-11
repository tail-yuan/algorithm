
#include<iostream>
#include<vector>
using namespace std;

struct TreeNode
{
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
};
class numsTree
{
	typedef TreeNode Node;
public:
	int process(int n)
	{
		if (n < 0)
			return 0;
		if (n == 0)
			return 1;
		if (n == 1)
			return 1;
		if (n == 2)
			return 2;
		int res = 0;
		for (int leftNum = 0; leftNum <= n - 1; leftNum++)
		{
			int leftWays = process(leftNum);
			int rightWays = process(n-leftNum-1);
			res = leftWays * rightWays;
		}
		return res;
	}
	// n [0,n] 
	int num_trees(int n)
	{
		vector<int> dp(n+1);
		dp[0] = 1;
		for (int i = 1; i < n + 1; i++)
		{
			for (int j = 0; j <=i-1; j++)
			{
				dp[i] += dp[j] * dp[i - j - 1];
			}
		}
		return dp[n];
	}
};