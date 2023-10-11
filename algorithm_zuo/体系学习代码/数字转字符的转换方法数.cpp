
#include<iostream>
#include<vector>
using namespace std;
class NumToStringWays
{
public:
	//从str[index]往后能转出多少种有效字符串表达
	int process(string& str, int index)
	{
		if (index == str.size())
			return 1;
		if (str[index] == '0')
			return 0;
		int res = process(str,index+1);
		if (index == str.size() - 1)
			return res;

		if( ((str[index]-'0')*10 + str[index+1] - '0')   <= 26)
			res += process(str,index+2);
		return res;
	}
	int numToStr(string& str)
	{
		return process(str,0);
	}

	//index [0,n]
	//dp[n+1] 
	// 主函数想要的是index=0时,所以最终止是dp[0]
	//dp[n]=1
	int numToStr2(string& str)
	{
		int n = str.size();
		if (n == 0) return 0;
		vector<int>dp(n+1);
		
		dp[n] = 1;
		dp[n - 1] = str[n - 1] == '0' ? 0 : 1;
		for (int i = n - 2; i >= 0; i--)
		{
			if (str[i] == '0')
				dp[i] = 0;
			else
			{
				dp[i] = dp[i + 1];
				if (((str[i] - '0') * 10 + str[i + 1] - '0') <= 26)
					dp[i] += dp[i + 2];
			}
		}
		return dp[0];
	}
};