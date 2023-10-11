#include<iostream>
#include<vector>
using namespace std;
//���ݰ��� https://image-1309381344.cos.ap-nanjing.myqcloud.com/img/image-20230709123015746.png
//������˰��� https://image-1309381344.cos.ap-nanjing.myqcloud.com/img/image-20230709123055916.png

class Fib
{
public:
	int getFibN(int n)
	{
		if (n < 1)
			return 0;
		//����Fib�������base����
		vector<vector<int>>base = {
			{1,1},
			{1,0}
			};
		vector<vector<int>>  res = matrixPower(base,n-2);
		return res[0][0]+res[1][0];
	}
	vector<vector<int>> matrixPower(vector<vector<int>>& base, int n)
	{
		vector<vector<int>>res(base.size(),vector<int>(base[0].size()));
		//�Խ�������Ϊ1 ��Ϊ��˵Ļ���
		for (int i = 0; i < base.size(); i++)
			res[i][i] = 1;

		vector<vector<int>> t = base;
		for (; n != 0; n >>= 1) 
		{
			if ((n & 1) != 0)
			{
				res = mulMatrix(res,t);//
			}
			t=mulMatrix(t,t);
		}
		return res;
	}
	//���������ξ������ O(1)
	vector<vector<int>> mulMatrix(vector<vector<int>>& m1, vector<vector<int>>&m2)
	{
		vector<vector<int>>res(m1.size(), vector<int>(m2[0].size()));
		for (int i = 0; i < m1.size(); i++)
		{
			for (int j = 0; j < m2[0].size(); j++)
			{
				for (int k = 0; k < m2.size(); k++)
				{
					res[i][j] += m1[i][k] * m2[k][j];
				}
			}
		}
		return res;
	}
};
// ���ϸ�ʽ+û�е���ת��,��������Fib��·�Ż�Ϊlog(N)
// 
// ��ʼ��һͷ����ĸţ
// ĸţ��������ʱ�����,�ڵ����꿪ʼ���µ�ĸţ
//������ĸţ�ǲ�������
//���ڵ�n��һ���ж���ͷĸţ
// ţ������:1 2 3 4 6 9...
// ����     1 2 3 4 5 6...
// ��Ϊţ������ʱ�����,��n���ţ����������һֱ�������ǰһ���ţ��+����֮ǰ��ţ������
// F(N)=F(N-1)+F(N-3)
// ���Կ���ת��Ϊ3������ʽ 3*3�ľ���
// ...
// F(N)F(N-1)F(N-2)= |F(3)F(2)F(1)|* |3*3�ľ���|^(n-3)
// �Ż�Ϊlog(N)ˮƽ


//��ʼ��һͷ��������
// ĸţ��������ʱ�����,�ڵ����꿪ʼ���µ�����,һ������
//�����������ǲ�������
//���ڵ�n��һ���ж���ͷ����
// F(N)=F(N-1)+2*F(N-2) =>pick N-2 , 
// 2*2�׾���=>F(N)F(N-1)=|F(2)F(1)|*|2*2�׾���|^(n-2)
//��������5������
// F(N)=F(N-1)+2*F(N-2)-F(N-5) =>pick N-5 , 
// 5*5�׾���=>F(N)F(N-1)F(N-2)F(N-3)F(N-4)=|F(5)F(4)F(3)F(2)F(1)|*|2*2�׾���|^(n-5)