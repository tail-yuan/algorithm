#include<iostream>
#include<vector>
using namespace std;
class CardsInLine
{
public:
	int win1(vector<int>& arr)
	{
		if (arr.size() == 0)
			return 0;
		return max(f(arr, 0, arr.size() - 1),s(arr, 0, arr.size() - 1));
	}
	int f(vector<int>& arr, int i, int j)
	{
		if (i == j)
			return arr[i];
		//先手拿左边的还是右边的
		return max(arr[i]+s(arr, i + 1, j) ,
					arr[j]+s(arr,i,j-1) );
	}
	int s(vector<int>& arr, int i, int j)
	{
		if (i == j)
			return 0;
		return min(f(arr, i + 1, j), f(arr, i, j - 1));//先手拿的剩下的那个左右边界最小的
	}
	//范围尝试,i<j,所以表的左下半区肯定没用
	//1.  i  [0,N-1] j  [0,N-1]二维表 f s 
	//2. 最终位置是f[0][N-1] s[0][N-1]
	//3. f表i==j位置=arr[i] s表i==j位置,0
	//4. 依赖关系,f[i][j]依赖于s[i+1][j] s[i][j-1]依赖于s表中对应点的左边和下边的值,一条斜线,反之也是,
	// 而 i=j这条斜线知道,所以可以交替的求出对方表的前一条斜线
	int win2(vector<int>& arr)
	{
		if (arr.size() == 0)
			return 0;
		int N = arr.size();
		vector<vector<int>>f(N, vector<int>(N));
		vector<vector<int>>s(N, vector<int>(N));
		for (int i = 0; i < N; i++)
			f[i][i] = arr[i];
		int row = 0;
		int col = 1;
		//对角线的方式
		while (col < N)
		{
			int i = row;
			int j = col;
			while (i < N && j < N)
			{
				f[i][j] = max(arr[i]+s[i+1][j],arr[j]+s[i][j-1]);
				s[i][j] = min(f[i+1][j],f[i][j-1]);
				i++;
				j++;
			}
			col++;
		}
		return max(f[0][N-1],s[0][N-1]);
	}
};
