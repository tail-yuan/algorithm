#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<stack>
using namespace std;
//全排列之后,判断字符串是否是出栈顺序
class Solution
{
	vector<string> ans;
	int n;
	string in;
public:
	bool isLegal(string out)
	{
		stack<char>st;
		int j = 0;
		for (int i = 0; i < in.size(); i++)
		{
			st.push(in[i]);
			while (!st.empty() && out[j] == st.top())
			{
				st.pop();
				j++;
			}
		}
		return st.size()==0;
	}
	void dfs(string& str, int l,int r)
	{
		if (l == r)
		{
			if(isLegal(str))
				ans.push_back(str);
			return;
		}
		for (int i = l; i <= r; i++) 
		{
			std::swap(str[l], str[i]);
			dfs(str, l + 1, r);//这里他吗的是L+1
			std::swap(str[i], str[l]); // 恢复原始顺序
		}
	}
	void  Func(string&str)
	{
		n = str.size();
		in = str;
		dfs(str, 0,n-1);
	}
	void print()
	{
		for (auto e : ans)
		{
			cout << e << endl;
		}
		cout << ans.size() << endl;
	}
};
int main()
{
	string str;
	cin >> str;
	Solution s;
	s.Func(str);
	s.print();
	return 0;
}