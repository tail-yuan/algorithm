
//���������з���32λ����a��b�� ����ʹ������������� �ֱ�ʵ��a��b�ļӡ� ���� �ˡ� ����
//�� ��Ҫ��
//�������a�� bִ�мӼ��˳����������ͻᵼ�����ݵ������ ��ô��ʵ�ֵĺ������ضԴ�
//���� ����֮���뱣֤������̲��������

// �ӷ�:
// c = a ^ b (�ֻ�ʵ���޽�λ���Ч��) 
// d= (a&b)<<1 (��λЧ��)
// c�ٺ�d��������,ֱ��d��λ��ϢΪ0�����ܻ�����޽�λʱ.
// ����:
// ����a+b���෴��(ȡ����1��ӵĽ��)
// �˷�:
// ������ÿһλȥ���,Ȼ������һλ֮���ۼӼ���,�����ƶ���01
// ����ģ��:
// ��b�����һλ����0ʱ,�ͽ�a��ֵ�ۼӵ�result��ȥ,Ȼ������һλa,b���޷�������ֱ��bΪ0
// ����: a/b
// b����iλ,��b��ӽ�����С��a,Ȼ��a=a-b ����aֵ,��¼����iλ
// ����һλ�൱����ֵ*2,����iλ,�൱��b*2^i,��<a������¼�ȥ�õ��µ�aֵ,
// ����b����ȥ��������µ�aֵ�Լ��µ�i,ƴ�����е�i���ɵõ���
// ��Ϊ���Ƶ�������ܴ������,������aȥ���ƿ���b ���ӵİ�ȫ
//

#include<iostream>
using namespace std;
class Operator
{
public:
	int my_add(int a, int b)
	{
		int sum = a;
		while (b)
		{
			sum = a ^ b;
			b = (a & b) << 1;
			a = sum;
		}
		return sum;
	}
	int negNum(int x)
	{
		return my_add(~x, 1);
	}
	int my_sub(int a, int b)
	{
		return my_add(a,negNum(b));
	}
	int multi(int a, int b)
	{
		int res = 0;
		while (b != 0)
		{
			if ((b & 1) != 0)
				res = my_add(res,a);
			a <<= 1;
			b= b>>1;//��������
		}
		return res;
	}

	bool isNeg(int a)
	{
		return a < 0;
	}

	int my_div(int a, int b)
	{
		int x = isNeg(a) ? negNum(a) : a;
		int y = isNeg(b) ? negNum(b) : b;
		int res = 0;
		//aֵ��С2^i��������iλ,��ȥa��ֵ,��¼i
		for (int i = 31; i > -1; i= my_sub(i,1))//����һ�μ����λ����������,�Ƶ�ʱ����һλλ�Ƶ�,����iҲ��ʱ�������
		{
			if ((x >> i) >= y)
			{
				res |= (1 << i);
				x = my_sub(x,y<<i);
			}
		}
		//���ab���,���Ǹ�ֵ
		return isNeg(a) ^ isNeg(b) ? negNum(res) : res;
	}
};