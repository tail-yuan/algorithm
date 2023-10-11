
#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_set>
using namespace std;
//以每一个位置括号为尾巴,能形成的最长连续子串,所以不可能是左括号,所以dp[i]=0
//dp[i]如果是 ) 查看前一个位置的值dp[i-1]代表以i-1为结尾,能形成的最长有效子串,查看dp[i-dp[i-1]]位置是否是(
// 如果是)dp[i]=0
// 如果是(,dp[i]至少是2+dp[i-1]
// ( 之前可能还有一个有效子串P,加上P的长度,即dp[i-dp[i-1]-1-1]
//P之前有无可能还需要加上有序区间Q呢?不用,因为他一定在P的统计之中了
class maxLen
{
public:
	int maxLength(string& str)
	{
		if (str.size() == 0)
			return 0;
		vector<int>dp(str.size(),0);
		int pre = 0;
		int ans = 0;
		for (int i = 1; i < str.size(); i++)
		{
			if (str[i] == ')')
			{
				pre = i - dp[i - 1] - 1;
				if (pre >= 0 && str[pre] == '(')
					dp[i] = dp[i - 1] + 2 + (pre>0 ?dp[pre-1]:0);
			}
			ans = max(ans,dp[i]);
		}
		return ans;
	}
};