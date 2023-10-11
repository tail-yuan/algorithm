#include<iostream>
#include<vector>
using namespace std;

//从两边往中间剥
class bracketsModifyMin
{
public:
	int process(string& str, int left, int right, char open, char close)
	{
		if (left >= right)
			return 0;
		if (str[left] == open && str[right] == close)
			return process(str,left+1,right-1,open,close);
		return 1 + min(process(str,left+1,right,open,close),process(str,left,right-1,open,close));
	}
	int getMin(string& str)
	{
		return process(str,0,str.size()-1,'(',')');
	}
	//left[0,n-1] right[0,n-1]
	//dp[n][n] return dp[0][n-1]
	// left>=right时,dp=0,所以下半数组都是0,包括对角线
	////画二维图,left=right对角线以上区域是需要更新的值
	//left从n-1~0,right从0~n-1,但是提升效率考虑,直接从对角线上方位置开始更新,即j从i+1~n区域更新
	int getMinDp(string& str)
	{
		int n = str.size();
		vector<vector<int>>dp(n,vector<int>(n,0));
		//初始化数组
		for (int i = 0; i < n; i++)
			dp[i][i] = 0;
		//从右到左遍历子串,出现未知值问题
		//for (int left = n - 2; left >= 0; left--)
		//{
		//	for (int right = left+1; right < n; right++)
		//	{
		//		if (str[left] == '(' && str[right] == ')')
		//			dp[left][right] = dp[left + 1][right - 1];//依赖于二维数组左下角的值
		//		else
		//			dp[left][right] = 1 + min(dp[left+1][right],dp[left][right]);
		//	}
		//}
		//从左到右遍历子串,left=right斜线上一个格斜线的表述right=len+left-1
		for (int len = 2; len <= n; len++) {
			for (int left = 0; left <= n - len; left++) {
				int right = left + len - 1;

				if (str[left] == '(' && str[right] == ')')
					dp[left][right] = dp[left + 1][right - 1]; // 依赖于二维数组左下角的值
				else
					dp[left][right] = 1 + min(dp[left + 1][right], dp[left][right - 1]);
			}
		}
		return dp[0][n - 1];
	}
};
int main()
{
	bracketsModifyMin bs;
	string str1 = "()()()()";//0
	string str2 = "(()))(";//2
	string str3 = "((())()(";//3
	cout<<bs.getMin(str1)<<endl;
	cout<<bs.getMinDp(str1) << endl;

	cout << bs.getMin(str2) << endl;
	cout << bs.getMinDp(str2) << endl;

	cout << bs.getMin(str3) << endl;
	cout << bs.getMinDp(str3) << endl;
	return 0;
}