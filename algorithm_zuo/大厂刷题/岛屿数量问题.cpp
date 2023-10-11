#include<iostream>
#include<vector>
using namespace std;
class Solution
{
	int m;
	int n;
	//vector<vector<bool>> visi;
	int ret;
public:
	int Func(vector<vector<int>>& arr)
	{
		m = arr.size(), n = arr[0].size();
		//visi = vector<vector<bool>>(m, vector<bool>(n,false));
		ret = 0;
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				//if (arr[i][j] == 1 && !visi[i][j])
				if (arr[i][j] == 1 )
				{
					//visi[i][j] = true;
					arr[i][j] = 2;
					ret++;
					dfs(arr, i, j);
				}
			}
		}
		return ret;
	}
	//只有是没用过的1才能够进入到这个递归函数中,然后进行标记
	//目的就是将相连的1全部标记.
	int dx[4] = {-1,1,0,0};
	int dy[4] = {0,0,1,-1};
	void dfs(vector<vector<int>>& arr, int i, int j)
	{
		for (int k = 0; k < 4; k++)
		{
			int x = i + dx[k], y = j + dy[k];
			//if (x >= 0 && x < m && y >= 0 && y < n && !visi[x][y] && arr[x][y] == 1)
			if (x >= 0 && x < m && y >= 0 && y < n && arr[x][y] == 1)
			{
				//visi[x][y] = true;
				arr[x][y] = 2;
				dfs(arr,x,y);
			}
		}
	}
};

int main()
{
	int m = 0, n = 0;
	cin >> m >> n;
	vector<vector<int>>arr(m,vector<int>(n));
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			cin >> arr[i][j];
	Solution s;
	int ret=s.Func(arr);
	cout << ret << endl;
	return 0;
}