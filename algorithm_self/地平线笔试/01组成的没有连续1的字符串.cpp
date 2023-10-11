#include <iostream>
#include<vector>
using namespace std;
class Solution
{
	string str = "01";
	vector<string>ans;
	int n;
public:
	bool isLegal(string& str)
	{
		for (int i = 0; i < str.size()-1; i++)
		{
			if (str[i] == '1' && str[i+1]=='1')
			{
				return false;
			}
		}
		return true;
	}
	void dfs(int len,string path)
	{
		if (len == n)
		{
			if(isLegal(path))
				ans.push_back(path);
			return;
		}
		for (int i = 0; i < 2; i++)
		{
			dfs(len + 1, path + str[i]);
		}
	}
	vector<string>Func(int _n)
	{
		n = _n;
		dfs(0,"");
		return ans;
	}
};
int main() 
{
	int n = 0;
	cin >> n;
	Solution s;
	vector<string>ans= s.Func(n);
	for (auto e : ans)
	{
		cout << e << " ";
	}
	cout << endl;
}
