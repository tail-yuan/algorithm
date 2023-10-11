//�ַ���ֻ��'0'��'1'�����ַ����ɣ�
//���ַ�������Ϊ1ʱ�� ���п��ܵ��ַ���Ϊ"0"�� "1"��
//���ַ�������Ϊ2ʱ�� ���п��ܵ��ַ���Ϊ"00"�� "01"�� "10"�� "11"��
//���ַ�������Ϊ3ʱ�� ���п��ܵ��ַ���Ϊ"000"�� "001"�� "010"�� "011"�� "100"��
//"101"�� "110"�� "111"
//...
//���ĳһ���ַ����У� ֻҪ�ǳ���'0'��λ�ã� ��߾Ϳ���'1'�� �������ַ���������
//���ַ�����
//����һ������N�� �������г���ΪN���ַ����У� ����ַ�����������
//���磬 N = 3�� ����3�� ��Ϊֻ��"101"�� "110"�� "111"��ꡣ

// 1. �������� 
// �Ȼ����2^n���ַ���,Ȼ��ÿ������Ҫ�ж��Ƿ���,���Ҳ��O(N) ������������O(2^N * N)
// 2. ��Χ֮���Ƶ�,Ȼ��ʹ�ô������ͨ��
// 
// 3.�龰����ΪFib����,�Ż�֮���ΪO(logN)����
//  ����Ϊi���ַ���ǰ��һ���ַ�������1�� 1[����Ϊi�ַ�������ƴ��]�Ŀ�����F,
//  ��ô��Ҫ���F(8)��ʵ��Ӧ�õ���F(7),�ϸ�Ǳ̨�ʹ涨��ͷ�ı�����1
//	�ڳ���Ϊi���ַ�����,��һ��λ���ַ�ѡ����0 1,
//   3.1 ���ѡ��1,��ô����i-1���ַ������������,F(i)=F(i-1)
//   3.2 ���ѡ��0,��ô�ڶ����ַ�������1,����i-2���ַ������������,F(i)=F(i-2)
//  ����F(i)=F(i-1)+F(i-2)=>Fib ��������,�Ż�������T(N),���Ϊlog(N)
//

#include<iostream>
#include<vector>
using namespace std;

class ZeroLeftOneStringNumber
{
public:
	int getNum1(int n)
	{
		if (n < 1)
			return 0;
		return process(1, n);
	}
	int process(int i, int n)
	{
		if (i == n - 1)
			return 2;
		if (i == n)
			return 1;
		return process(i+1,n)+process(i+2,n);
	}
	//2. 
	int getNum2(int n)
	{
		if (n < 1)
			return 0;
		if (n == 1)
			return 1;
		int pre = 1;
		int cur = 1;
		int tmp = 0;
		for (int i = 2; i < n - 1; i++)
		{
			tmp = cur;
			cur += pre;
			pre = tmp;
		}
		return cur;
	}
	//3. 
	int getNum3(int n)
	{
		if (n < 1)
			return 0;
		if (n == 1 || n == 2)
			return n;
		vector<vector<int>>base = { {1,1},{1,0} };
		vector<vector<int>>res = matrixPower(base,n-2);
		return 2 * res[0][0] + res[1][0];
	}
	vector<vector<int>>matrixPower(vector<vector<int>>& m, int p)
	{
		vector<vector<int>> res(m.size(),vector<int>(m[0].size()));
		for (int i = 0; i < m.size(); i++)
			res[i][i] = 1;
		
		vector<vector<int>>t = m;
		for (; p != 0; p >>= 1)
		{
			if ((p & 1) !=0)
			{
				res = mulMatrix(res,t);
			}
			t = mulMatrix(t,t);
		}

		return res;
	}
	vector<vector<int>> mulMatrix(vector<vector<int>>& m1, vector<vector<int>>& m2)
	{
		vector<vector<int>>res(m1.size(),vector<int>(m2[0].size()));
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