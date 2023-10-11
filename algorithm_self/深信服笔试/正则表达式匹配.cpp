//#include <iostream>
//#include<vector>
//using namespace std;
//
//int main() 
//{
//	string s, p;
//	cin >> s >> p;
//	int n = s.size(), m = p.size();
//	s = " " + s; p = " " + p;
//	vector<vector<bool>>dp(n + 1, vector<bool>(m + 1,false));
//	dp[0][0] = true;
//	for (int i = 1; i <= m; i++)
//	{
//		if (p[i] == '*')
//			dp[0][i] = true;
//		if (p[i] != '*')
//			break;
//	}
//	for (int i = 1; i <= n; i++)
//	{
//		for (int j = 1; j <= m; j++)
//		{
//			if (s[i] == p[j])
//				dp[i][j] = dp[i - 1][j - 1];
//			else
//			{
//				if (p[j] == '.')
//					dp[i][j] = dp[i - 1][j - 1];
//				else
//				{
//					if (s[i] == p[j - 1])
//					{
//						dp[i][j] = dp[i - 1][j - 2] || dp[i - 1][j];
//					}
//				}
//			}
//		}
//	}
//	bool flag = dp[n][m];
//	if (flag)
//		cout << 1 << endl;
//	else
//		cout << 0 << endl;
//}
//// 64 Î»Êä³öÇëÓÃ printf("%lld")