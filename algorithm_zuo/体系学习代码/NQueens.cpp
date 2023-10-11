#include<iostream>
#include<string>
#include<vector>
#include<stack>
using namespace std;
//��һ�п�ʼ,ÿһ�дӵ�һ�п�ʼѡ��һ������,
//ֻ��Ҫ��֤��һ��ѡ�еĸ��Ӻ�֮ǰѡ�еĲ���ͻ(����һ��,����һ��,����һ��б��)����
class NQueens
{
public:
	int num(int n)
	{
		if (n < 1)
			return 0;
		int* record = new int[n];//record[i]=j ��¼��i�еĻʺ���ڵ�j��
		return process(record,0,n);
	}
	int process(int* a, int i, int n)
	{
		//base case �ӿ�ͷ�����ղ���ͻ��,�ߵ�β��,˵������һ����Ч������β,���ط�����1
		if (i == n)
			return 1;
		int res = 0;
		for (int j = 0; j < n; j++)
		{
			if (isValid(a, i, j))
			{
				a[i] = j;
				res += process(a,i+1,n);
			}
		}
		return res;
	}
	//�ڵ�i��ѡ��,ֻ��Ҫ��ע[0,i-1]λ�����Ƿ��j��ͻ
	bool isValid(int* record, int i, int j)
	{
		for (int k = 0; k < i; k++)
		{
			if (j == record[k] || abs(record[k] - j) == abs(k - i))//��б��
				return false;
		}
		return true;
	}
};
//����ʱ������Ż�,����O(N!)ʱ�临�Ӷ��ǲ����Ż���
//������32�ʺ�����
// n�ʺ���������������limit��nλ��1,ǰ��ȫ��0
//����3��������Ϊ������Ϣ�ļ�¼,int������32λ,λ����,1�����Ѿ�ռ��
// ������8�ʺ�����,�����ȵ�һ��ѡ�е���i=5λ,��ô�������ƾ���:
// colLimit   00001000 ��colLimit|��5λΪ1
// leftLimit  00010000 ��leftLimit|0000100,Ȼ�������ƶ�һλ
// rightLimit 00000100 ��rightLimit|0000100,Ȼ�������ƶ�һλ
//     |֮��: 00011100
//     ~֮��: 11100011
// &limit֮��:11100011
// ���ڵڶ���ѡ�еڶ�λ��1
// ֮��õ�����pos,1����λ�ô������ѡ��,0������ѡ��
// colLimit   01001000 ��colLimit|��2λΪ1
// leftLimit  10010000 ��leftLimit|0000100,Ȼ�������ƶ�һλ
// rightLimit 00100100 ��rightLimit|0000100,Ȼ�������ƶ�һλ
//     |֮��: 11111100
//     ~֮��: 00000011
// &limit֮��:00000011 1���ǿ��Էŵ�λ�� limit���þ���ȡ��֮��ǰ�����õ�λ��ȫ���ص�
class NQueens_Plus
{
public:

	int process(int limit, int colLim, int leftLim, int rightLim)
	{
		//����к�limit��ͬ��,˵��collim��ȫ1,ÿһ��ȡһ��λ�õĻ�ÿһ�ж�ȡ1��,��һ�ַ�������1 
		if (limit == colLim)
			return 1;

		int pos = 0;
		int theRightestOne = 0;
		//������|������|�����ƾ�����λ������,
		pos = limit & (~(colLim | leftLim | rightLim));
		int res = 0;
		while (pos != 0)
		{
			//ʵ���м���1ѭ�����߼���,��ÿ��1λ�ö���һ�λʺ�
			theRightestOne = pos & (~pos + 1);//��ȡ���ұߵ�1
			pos = pos - theRightestOne;			//��ȡ֮���ȥ���ұ�1=>����µ���
			//��һ��ѡ���������Ϣ����posֵ
			res += process(limit,colLim | theRightestOne,
							(leftLim | theRightestOne)<<1,
							(rightLim | theRightestOne)>>1);
		}
		return res;
	}
	int num(int n)
	{
		if (n < 1 || n>32)
			return 0;
		//n�ʺ�����ͽ���nλ����Ϊ1 -1����32λȫ1
		int limit = n == 32 ? -1 : (1 << n) - 1;
		return process(limit,0,0,0);
	}
};