#include"head.hpp"
class Solution
{
public:
	//配置溶液体积恰好为C([1,1000])时最大物质含量是多少
	int ChemicalMaxValue(vector<int>& w, vector<int>& v, int x, int c)
	{
		int n = v.size();
		vector<int>dp((n+1), -1);
		//全初始化为-1,是向代表没有解决方案
		//想要得到体积为c时最大容量,所以要取到c,则开辟c+1个空间
		for (int i = 0; i < n; i++)
		{
			//=是指将体积恰好为c的数值先放入dp数组中
			//<是将体积相同的溶液中含量最多的保存即可(最大含量嘛,只要含量多的保存,剩下的没用)
			if (v[i] <= c)
			{
				dp[v[i]] = max(dp[v[i]], w[i]);
			}
		}
		//10^8以内的就可以通过
		for (int i = 1; i <= c; i++)
		{
			//i=10
			//v:1 + 9 =1和=9的溶液最大含量值相加
			//v:2 + 8
			//v:4+6
			//v:5+5+x 额外化学反应
			//不能再出现6+4 了,因为已经算过了,所以j<i/2
			for (int j = 1; j < i / 2; j++)
			{
				//还需要保证的是,体积为i时是有解决方案的,不能是-1
				if (dp[i] != -1 && dp[i - j] != -1)
				{
					dp[i] = max(dp[i], dp[i] + dp[j] + (j == i - j ? x : 0));
				}
			}
		}
		return dp[c];
	}
};