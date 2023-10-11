
//ʵ��a��n�η�����,����������ǽ�a��n��,ʱ�临�Ӷ���O(N)
//����N=75 = 64+ 8+4+1
// a^75=  a^1+a^4+ a^8 + a^64
//75= 1001101,��t=a��ʼt*t,�ڶ�����λiλΪ1,����a^i��,t=t*t
//����ʱ�临�ӶȾͽ�����log(N)����,�м���������λ�ͳ��ϼ���.

//��NΪ����ʱ,ֻ��Ҫ�����x��N�����η�,Ȼ����1������
// ����ϵͳ��Сֵ�޷�ת����ֵ����,ֻ��Ҫ��INT_MAX�η������֮���ٳ���һ��x����


#include<iostream>
using namespace std;
class Solution
{
public:
	int pow(int a, int n)
	{
		int ans = 1;
		int t = a;
		while (n != 0)
		{
			if ((n & 1) != 0)//ֻ���ڱ�־λΪ1�ĵط��ų���
				ans *= t;
			t *= t;
			n >>= 1;
		}
		return ans;
	}
public:
	double mypow(double a, int n)
	{
		if (n == 0)
			return 1.0;
		//����Ǹ�����Сֵ�ͽ���ת��Ϊ�������ֵ
		int pow = std::abs(n == INT_MIN ? n + 1 : n);
		double t = a;
		double ans = 1.0;
		while (pow)
		{
			if ((pow & 1) == 1)
				ans *= t;
			t *= t;
			pow >>= 1;
		}
		if (n == INT_MIN)
			ans *= a;
		return n < 0 ? 1.0 / ans : ans;
		//>> ����������,��߲�����1
		//>>>������������,��߲�����0
	}
};