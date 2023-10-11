#include<iostream>
#include<vector>
using namespace std;

//һ��n*n�ľ�����,�����ε���������n^3
//����һ������Ϊ������,һ��n^2,ö�ٱ߳���1~n����n,=>n^3
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
					//ȷ��һ�������� n^3
					//n��֤4�����Ƿ���1
					for (;;) {}
					for (;;) {}
					for (;;) {}
					for (;;) {}
				}
			}
		}
	}
	//��֤ĳһ����Ϊ���������Ͻ���֤�Ĺ��̿���O(N)->O(1)
	// Ԥ����:
	//������������,right(i,j)λ�ü�¼�����Լ������Ҳ� �ж���x��������1
	//			   down(i,j)λ�ü�¼�����Լ����� �·� �ж���y��������1
	//����֤down(i,j+x) right[i+y,j]
	//������,˵��(i,j)��Ϊ���������ϽǵĴ�С��right[i][j]\
	//��3�α�Ĺ��̶���O(1)
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