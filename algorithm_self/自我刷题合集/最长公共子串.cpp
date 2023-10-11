#include<iostream>
#include<vector>
using namespace std;

// 使用二维数组dp来记录中间结果，dp[i][j]表示以str1[i - 1]和str2[j - 1]结尾的最长公共子串的长度。
//在计算dp[i][j]时，如果str1[i - 1]和str2[j - 1]相等，那么dp[i][j]等于dp[i - 1][j - 1] + 1，否则dp[i][j]为0。
//在上述代码中，初始化部分是为了构建动态规划的辅助数组`dp`，用于记录中间结果。

//1. `int dp[m + 1][n + 1]; `：这里定义了一个二维数组`dp`，它的行数为`m + 1`，列数为`n + 1`。这里的`m`和`n`分别是`str1`和`str2`的长度。
//
//2. 边界条件初始化：
//3. 其他位置初始化：
//- 在动态规划的填充过程中，我们会根据`str1`和`str2`的字符比较来更新`dp`数组中的值。
// 如果`str1[i - 1]`和`str2[j - 1]`相等，我们将`dp[i][j]`设置为`dp[i - 1][j - 1] + 1`，
// 表示以`str1[i - 1]`和`str2[j - 1]`结尾的最长公共子串的长度增加1。
// 否则，我们将`dp[i][j]`设置为0，表示以`str1[i - 1]`和`str2[j - 1]`结尾的最长公共子串不存在（长度为0）。
//初始化过程是动态规划算法中的一部分，它确保在填充`dp`数组时，我们从正确的基本情况出发，然后逐步计算得到更复杂的情况，直到得到最终的结果。这样，我们就能正确地找到两个字符串的最长公共子串。
class longestPulicSubStr
{
public:
	string longestCommonSubstring(string& str1, string& str2)
	{
		int m = str1.size();
		int n = str2.size();
		//dp[i][j]表示以str1[i - 1]和str2[j - 1]结尾的最长公共子串的长度
		vector<vector<int>> dp(m+1, vector<int>(n+1));
		int maxLen = 0, endIndex = 0;
		//将`dp`数组第一列的所有元素初始化为0，表示`str2`为空字符串时，最长公共子串的长度为0。
		for (int i = 0; i <= m; i++)
			dp[i][0] = 0;
		//将`dp`数组第一行的所有元素初始化为0，表示`str1`为空字符串时，最长公共子串的长度为0。
		for (int j = 0; j <= n; j++)
			dp[0][j] = 0;
		for (int i = 1; i <= m; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (str1[i - 1] == str2[j - 1])
				{
					dp[i][j] = dp[i - 1][j - 1] + 1; //表示以`str1[i - 1]`和`str2[j - 1]`结尾的最长公共子串的长度增加1。
					if (dp[i][j] > maxLen)
					{
						endIndex = i-1;
						maxLen = dp[i][j];
					}
				}
				else
					dp[i][j] = 0;//表示以`str1[i - 1]`和`str2[j - 1]`结尾的最长公共子串不存在（长度为0）
			}
		}
		return str1.substr(endIndex-maxLen+1,maxLen);
	}
};