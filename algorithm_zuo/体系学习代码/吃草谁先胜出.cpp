#include<iostream>
#include<vector>
using namespace std;

//ÿ��ѡ���4�Ĵη������Ĳ�,˭�ȳ���˭�ͻ�ʤ
//1. ���
// 0~4֮����Ҫ�����ж�,֮��,�ӵ�һ�γ�16�ݿ�ʼ����,���������Ӯ������Ӯ,�����ԳԵ��Ѿ�>n��û����Ӯ������
//
class Eat
{
public:
	string winner1(int n)
	{
		// 0  1  2  3  4 
		// �� �� �� �� ��
		if (n < 5)
			return (n==0 || n == 2) ? "����" : "����";
		int base = 1;
		while (base <= n)
		{
			if (winner1(n - base) == "����")//�ݹ�����ӹ���,����ӹ��̷��غ���Ӯ��ʵ���������̵�����Ӯ
				return "����";
			if (base > n/4)//����base*4 >INT_MAXԽ��
				break;
			base *= 4;
		}
		return "����";
	}
	void test()
	{
		//�����Ǻ��Ⱥ�����
		for (int i = 0; i <= 50; i++)
		{
			//cout << i << " " << winner1(i) << endl;
			cout << i << " " << winner1(i)<<":"<<winner2(i) << endl;
		}
	}
	string winner2(int n)
	{
		if (n % 5 == 0 || n % 5 == 2)
			return "����";
		else
			return "����";
	}
};
//int main()
//{
//	Eat e;
//	e.test();
//}