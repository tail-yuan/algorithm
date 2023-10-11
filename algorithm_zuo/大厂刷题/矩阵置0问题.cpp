
//矩阵置零问题,(i,j)位置为0,那么这一行这一列都设置为0
//
//题解:
//使用两张表,row[0~n],row[i]代表i这一行需要变成0,col[i]代表这一列需要都变0
//在遍历数组的时候,发现arr[i][j]位置是0,那么row[i]=true,col[j]=true
//在修改数组时就知道哪一行哪一列需要变0
//---------如何优化空间复杂度?
//利用原数组的第0行第0列代表刚才的两个数组,row和col
//从(1,1)位置开始遍历,发现(i,j)位置为0,则matrix[0][j]=0,matrix[i][0]=0
//i,j这两列都需要设置为0.但是只能存在于这一行一列不存在0的情况
//否则,不知道是更新为0,还是原来就是0. 是更新为0,只需要将这一列设置为0,否则这行这列都需要为0
//所以使用两个变量,标记第一行第一列是否需要设置为0
//---------再优化,只是用一个变量
// 
//(0,0)位置只需要代表第0行变不变0,另外用col0代表第0列到底要不要变0
//matrix[0][j]代表[j]这一列是否要变0. 由(0,0)位置决定0行变不变0,解决可能存在的第一行有0
//col0解决第0列是否为0
#include<iostream>
#include<vector>
using namespace std;
class Solution
{
public:
	void setMatrixZeroes(vector<vector<int>>& matrix)
	{
		int n = matrix.size(), m = matrix[0].size();
		bool col0 = false;
		int i = 0, j = 0;
		for (i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (matrix[i][j] == 0)
				{
					matrix[i][0] = 0;
					if (j == 0)
						col0 = true;
					else
						matrix[0][j] = 0;
				}
			}
		}
		//遍历除了第一列之外的部分
		for (i = n - 1; i >= 0; i--)
		{
			for (j = 1; j < m; j++)
			{
				if (matrix[i][0] == 0 || matrix[0][j] == 0)
					matrix[i][j] = 0;
			}
		}
		if (col0)
		{
			for (i = 0; i < n; i++)
				matrix[i][0] = 0;
		}
	}
public:
	void setMatrixZeroes(vector<vector<int>>& matrix)
	{
		int n = matrix.size(), m = matrix[0].size();
		bool zeroRow = false, zeroCol = false;
		int i = 0, j = 0;
		for (i = 0; i < n; i++)
		{
			if (matrix[i][0] == 0)
			{
				zeroCol = true;
				break;
			}
		}
		for (j = 0; j < m; j++)
		{
			if (matrix[0][j] == 0)
			{
				zeroRow = true;
				break;
			}
		}
		for (i = 1; i < n; i++)
		{
			for (j = 1; j < m; j++)
			{
				if (matrix[i][j] == 0)
				{
					matrix[0][j] = 0;
					matrix[i][0] = 0;
				}
			}
		}
		//设置
		for (i = 1; i < n; i++)
		{
			for (j = 1; j < m; j++)
			{
				if (matrix[i][0] == 0|| matrix[0][j]==0)
					matrix[i][j] = 0;
			}
		}
		if (zeroRow)
		{
			for (j = 0; j < m; j++)
				matrix[0][j] = 0;
		}
		if (zeroCol)
		{
			for (i = 0; i < n; i++)
				matrix[i][0] = 0;
		}
	}
};