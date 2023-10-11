#include <iostream>
#include<vector>
using namespace std;
class Solution
{
	int n, m;
	const int N = 0x3f3f3f3f;
	vector<vector<bool>>visi;
public:
	int Func(vector<vector<char>>& arr)
	{
		n = arr.size();
		m = arr[0].size();
		int x = 0, y = 0;
		visi = vector<vector<bool>>(n, vector<bool>(m));
		bool isFound = false;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (arr[i][j] == 's')
				{
					x = i;
					y = j;
					isFound = true;
					break;
				}
			}
			if (isFound)
				break;
		}
		int ret = dfs(arr, x, y, 0);
		return ret == N?-1:ret;
	}
	int dx[4] = { -1,1,0,0 };
	int dy[4] = { 0,0,-1,1 };
	int dfs(vector<vector<char>>& arr, int i, int j, int count)
	{
		//既然这里你已经用N代表不可递达,那么再求min时就不用判断了,因为必然取不到
		if (arr[i][j] == '#')
			return N;
		if (arr[i][j] == 'e')
			return count;

		int ans = N;//记录四条路中最短的路径和
		for (int k = 0; k < 4; k++)
		{
			int x = i + dx[k];
			int y = j + dy[k];
			if (x >= 0 && x < n && y >= 0 && y < m && !visi[x][y])
			{
				visi[i][j] = true;
				int ret= dfs(arr, x, y, count + 1);
				ans = min(ans, ret);
				visi[i][j] = false;
			}
		}
		return ans;
	}
};
int main()
{
	int n = 0, m = 0;
	cin >> n >> m;
	vector<vector<char>>arr(n,vector<char>(m));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> arr[i][j];
		}
	}
	Solution s;
	int ret = s.Func(arr);
	cout << ret << endl;
}