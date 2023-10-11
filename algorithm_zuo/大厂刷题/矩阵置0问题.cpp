
//������������,(i,j)λ��Ϊ0,��ô��һ����һ�ж�����Ϊ0
//
//���:
//ʹ�����ű�,row[0~n],row[i]����i��һ����Ҫ���0,col[i]������һ����Ҫ����0
//�ڱ��������ʱ��,����arr[i][j]λ����0,��ôrow[i]=true,col[j]=true
//���޸�����ʱ��֪����һ����һ����Ҫ��0
//---------����Ż��ռ临�Ӷ�?
//����ԭ����ĵ�0�е�0�д���ղŵ���������,row��col
//��(1,1)λ�ÿ�ʼ����,����(i,j)λ��Ϊ0,��matrix[0][j]=0,matrix[i][0]=0
//i,j�����ж���Ҫ����Ϊ0.����ֻ�ܴ�������һ��һ�в�����0�����
//����,��֪���Ǹ���Ϊ0,����ԭ������0. �Ǹ���Ϊ0,ֻ��Ҫ����һ������Ϊ0,�����������ж���ҪΪ0
//����ʹ����������,��ǵ�һ�е�һ���Ƿ���Ҫ����Ϊ0
//---------���Ż�,ֻ����һ������
// 
//(0,0)λ��ֻ��Ҫ�����0�б䲻��0,������col0�����0�е���Ҫ��Ҫ��0
//matrix[0][j]����[j]��һ���Ƿ�Ҫ��0. ��(0,0)λ�þ���0�б䲻��0,������ܴ��ڵĵ�һ����0
//col0�����0���Ƿ�Ϊ0
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
		//�������˵�һ��֮��Ĳ���
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
		//����
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