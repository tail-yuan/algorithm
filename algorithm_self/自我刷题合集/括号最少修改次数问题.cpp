#include<iostream>
#include<vector>
using namespace std;

//���������м��
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
	// left>=rightʱ,dp=0,�����°����鶼��0,�����Խ���
	////����άͼ,left=right�Խ���������������Ҫ���µ�ֵ
	//left��n-1~0,right��0~n-1,��������Ч�ʿ���,ֱ�ӴӶԽ����Ϸ�λ�ÿ�ʼ����,��j��i+1~n�������
	int getMinDp(string& str)
	{
		int n = str.size();
		vector<vector<int>>dp(n,vector<int>(n,0));
		//��ʼ������
		for (int i = 0; i < n; i++)
			dp[i][i] = 0;
		//���ҵ�������Ӵ�,����δֵ֪����
		//for (int left = n - 2; left >= 0; left--)
		//{
		//	for (int right = left+1; right < n; right++)
		//	{
		//		if (str[left] == '(' && str[right] == ')')
		//			dp[left][right] = dp[left + 1][right - 1];//�����ڶ�ά�������½ǵ�ֵ
		//		else
		//			dp[left][right] = 1 + min(dp[left+1][right],dp[left][right]);
		//	}
		//}
		//�����ұ����Ӵ�,left=rightб����һ����б�ߵı���right=len+left-1
		for (int len = 2; len <= n; len++) {
			for (int left = 0; left <= n - len; left++) {
				int right = left + len - 1;

				if (str[left] == '(' && str[right] == ')')
					dp[left][right] = dp[left + 1][right - 1]; // �����ڶ�ά�������½ǵ�ֵ
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