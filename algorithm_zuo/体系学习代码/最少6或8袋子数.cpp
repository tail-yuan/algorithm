#include<iostream>
#include<vector>
using namespace std;
//1. ̰�ĵķ�ʽ,
// �Ȼ�ȡ8��ʹ�õ��������,�ж�rest�Ƿ�����6װ,���ܵĻ�����һ��8��,���ж�
// ֱ��ʹ��8�Ĵ���Ϊ0,�����м���һ�������ʹ��6װ���.
// �Ż�:�������8���ӹ�����,rest>24ֻ��6�㶨ʱ,��ȫ������8�㶨,��ʱ�����˳�,��Ϊ�϶�������6��� 
// O(1) ��Ϊrest�ò��˼��ξͻ�����ѭ��
//2. ��int ����int ->���
//����1���ʹ�ö�����,��ӡ���,��Ѱ����,Ȼ���ܽ�,ֱ�ӷ���,Ч��һ������ߵ�.
class minBags
{
public:
	int minBagBase6(int rest)
	{
		return rest % 6 == 0 ? rest / 6 : -1;
	}
	int minBags1(int apple)
	{
		if (apple < 0)return -1;
		int bag6 = -1;
		int bag8 = apple / 8;
		int rest = apple - bag8 * 8;
		while (bag8 >= 0 && rest<24)
		{
			int resUse6 = minBagBase6(rest);
			if (resUse6!=-1)
			{
				bag6 = resUse6;
				break;
			}
			rest = apple - (--bag8) * 8;
		}
		return bag6 == -1 ? -1 : bag6 + bag8;
	}
	void test()
	{
		for (int i = 0; i < 100; i++)
		{
			cout << i << " " << minBags1(i) << ":" << minBags2(i) << endl;
		}
	}
	int minBags2(int apple)
	{
		if (apple % 2 == 1)
			return -1;
		if (apple < 18)
		{
			return apple == 0 ? 0 : (apple == 6 || apple == 8 ? 1 :
				apple == 12 || apple == 16 ? 2 : -1);
		}
		return (apple - 18) / 8 + 3;
	}
};
//int main()
//{
//	minBags mb;
//	mb.test();
//}