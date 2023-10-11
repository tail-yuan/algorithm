
//实现a的n次方计算,正常计算就是将a乘n次,时间复杂度是O(N)
//假设N=75 = 64+ 8+4+1
// a^75=  a^1+a^4+ a^8 + a^64
//75= 1001101,从t=a开始t*t,在二进制位i位为1,乘上a^i次,t=t*t
//这样时间复杂度就降低至log(N)级别,有几个二进制位就乘上几次.

//当N为负数时,只需要先求出x的N整数次方,然后用1除即可
// 但是系统最小值无法转绝对值正数,只需要将INT_MAX次方求出来之后再乘上一次x即可


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
			if ((n & 1) != 0)//只有在标志位为1的地方才乘上
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
		//如果是负数最小值就将其转化为正数最大值
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
		//>> 带符号右移,左边补的是1
		//>>>不带符号右移,左边补得是0
	}
};