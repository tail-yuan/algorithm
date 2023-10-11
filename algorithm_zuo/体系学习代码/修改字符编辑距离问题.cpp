//给定两个字符串str1和str2，再给定三个整数ic、dc和rc，分别代表插入、删
//除和替换一个字符的代价，返回将str1编辑成str2的最小代价。
//【举例】
//str1 = "abc"，str2 = "adc"，ic = 5，dc = 3，rc = 2
//从"abc"编辑成"adc"，把'b'替换成'd'是代价最小的，所以返回2
//str1 = "abc"，str2 = "adc"，ic = 5，dc = 3，rc = 100
//从"abc"编辑成"adc"，先删除'b'，然后插入'd'是代价最小的，所以返回8
//str1 = "abc"，str2 = "abc"，ic = 5，dc = 3，rc = 2
//不用编辑了，本来就是一样的字符串，所以返回0

// 以str1为行,str2为列构建一张二维表
// dp[i][j]代表的是str1[0...i-1]构成str2[0...j-1]的代价是多少
// dp[0][0] 空串组成空串的代价是 0
// 第一列,str1由前i个字符->str2的空串的代价->i*del删除代价,同理第一行就是i*add新增代价
// 其余情况:
// 情况1: [0...i-2,i-1] 让str1[0...i-2]等于str2[0...j-1],将str1[i-1]删除=> dp[i-1][j] + del
// 情况2: [0...i-2,i-1] 让str1[0...i-1]等于str2[0...j-2],在str1[i]位置新增一个str2[j-1]字符=> dp[i][j-1] + add
// 情况3: [0...i-2,i-1] 让str1[0...i-2]等于str2[0...j-2],将str1[i-1]位置替换为str2[j-1]字符=> dp[i-1][j-1] + replace
// 情况4: str1[i-1] ==str2[j-1]最后一个字符相等,让str[0...i-2]等于str[0...j-2]然后将str1[i-1]拷贝为str2[j-1]=>dp[i-1][j-1]+copy(0)
// 34是互斥出现的
#include<iostream>
#include<vector>
using namespace std;
class EditCost
{
public:
	int minCost(string&str1,string&str2,int delCost,int addCost,int replaceCost)
	{
		int m = str1.size(), n = str2.size();
		vector<vector<int>> dp(m,vector<int>(n));
		dp[0][0] = 0;
		for (int i = 0; i < m; i++)
			dp[i][0] = i * delCost;
		for (int i = 0; i < n; i++)
			dp[0][i] = i * addCost;
		for (int i = 1; i < m; i++)
		{
			for (int j = 1; j < n; j++)
			{
				if (str1[i - 1] == str2[j - 1])
					dp[i][j] = dp[i - 1][j - 1];
				else
					dp[i][j] = dp[i - 1][j - 1] + replaceCost;
				dp[i][j] = min(dp[i][j],dp[i-1][j]+delCost);
				dp[i][j] = min(dp[i][j],dp[i][j-1]+addCost);
			}
		}
		return dp[m-1][n-1];
	}
};