#include<iostream>
#include<vector>
using namespace std;

//一个n*n的矩阵中,正方形的数量级是n^3
//首先一个点作为正方形,一共n^2,枚举边长从1~n又是n,=>n^3
class MaxOneBorderSize
{
public:
	//O(n^4)
	int maxSizeBorderTest(vector<vector<int>>& arr)
	{
		int m = arr.size();
		int n = arr[0].size();
		for (int row = 0; row < m; row++)
		{
			for (int col = 0; col < m; col++)
			{
				for (int border = 1; border < min(m - row, n - col); border++)
				{
					//确定一个正方形 n^3
					//n验证4条边是否都是1
					for (;;) {}
					for (;;) {}
					for (;;) {}
					for (;;) {}
				}
			}
		}
	}
	//验证某一点作为正方形左上角验证的过程可以O(N)->O(1)
	// 预处理:
	//两个辅助矩阵,right(i,j)位置记录包含自己在内右侧 有多少x个连续的1
	//			   down(i,j)位置记录包含自己在内 下方 有多少y个连续的1
	//再验证down(i,j+x) right[i+y,j]
	//都成立,说明(i,j)作为正方形左上角的大小是right[i][j]\
	//查3次表的过程都是O(1)
	void setBorderMap(vector<vector<int>>& m, vector<vector<int>>& right, vector<vector<int>>& down)
	{
		int M = m.size();
		int N = m[0].size();
		if (m[M - 1][N - 1] == 1)
		{
			right[M - 1][N - 1] = 1;
			down[M - 1][N - 1] = 1;
		}
		for (int i = M - 2; i >= 0; i--)
		{
			if (m[i][N - 1] == 1)
			{
				right[i][N-1]=1;
				down[i][N - 1] = down[i+1][N-1]+1;
			}
		}
		for (int j = N - 2; j >= 0; j--)
		{
			if (m[M-1][j] == 1)
			{
				down[M - 1][j] = 1;
				right[M - 1][j] = right[M-1][j+1] + 1;
			}
		}
		for (int i = M - 2; i >= 0; i--)
		{
			for (int j = N - 2; j >= 0; j--)
			{
				if (m[i][j] == 1)
				{
					right[i][j] = right[i][j + 1] + 1;
					down[i][j] = down[i+1][j]+1;
				}
			}
		}
	}
	bool hasSizeOfBorder(int size, vector<vector<int>>& right, vector<vector<int>>& down)
	{
		for (int i = 0; i != right.size() - size + 1; i++)
		{
			for (int j = 0; j != right[0].size() - size + 1; j++)
			{
				if (right[i][j] >= size && down[i][j] >= size
					&& right[i + size - 1][j] >= size
					&& down[i][j + size - 1] >= size )
				{
					return true;
				}
			}
		}
		return false;
	}
	int maxSizeBorder(vector<vector<int>>& arr)
	{
		int m = arr.size();
		int n = arr[0].size();
		vector<vector<int>>right (m,vector<int>(n));
		vector<vector<int>>down (m,vector<int>(n));
		setBorderMap(arr,right,down);
		for (int size = min(m, n); size != 0; size--)
		{
			if (hasSizeOfBorder(size, right, down))
			{
				return size;
			}
		}
		return 0;
	}

};