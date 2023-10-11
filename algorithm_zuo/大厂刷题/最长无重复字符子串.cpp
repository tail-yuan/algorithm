#include<iostream>
#include<vector>
using namespace std;

//以i为结尾,dp[i]代表以i位置为结尾时的最长无重复子串的长度.
// 正常求解是以i为结尾往前最多能推多远,保证连续的基础之上
//dp希望求i位置时能够利用之前的结果dp[i-1]进行加速求解
//影响因素: 1. [i]位置元素上次出现的位置 x,用map表记录
//		   2. dp[i-1]记录的是[i-1]位置能够往前拓展的长度,i-dp[i-1]就是[i-1]重复字符的位置y
//if x < y,dp[i]=dp[i-1]+1
//if x > y,dp[i]=i-x
//优化: 因为只需要依赖dp[i-1]的值,所以我可以用一个变量存储,而不使用整个dp数组空间.
//	   上次出现的位置也可以用变量存储,而不需要再开一张表

class Solution
{
public:
	int longestSubStrWithoutRepeatChar(string& str)
	{
		if (str.size() == 0) return 0;
		vector<int>my_map(256,-1);//所以字符的上一个位置全部初始化为-1
		int n = str.size();
		int ans = 1;//至少是1
		int pre = 1;//dp[i-1],用一个变量记录
		my_map[str[0]] = 0;
		for (int i = 1; i < n; i++)
		{
			int p1 = i - my_map[str[i]];
			int p2 = pre + 1;
			int cur = min(p1, p2);//两种情况哪个离得更远
			ans = max(ans, cur);
			pre = cur;
			my_map[str[i]] = i;
		}
		return ans;
	}
};