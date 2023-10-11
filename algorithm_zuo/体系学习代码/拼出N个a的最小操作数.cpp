#include<iostream>
#include<vector>
using namespace std;

//题干:
//  s=a m=s 
// op1:m=s s=s+s 
// op2:s=s+m
// 问:当想要拼出n个a时最少的调用操作的次数是多少?
//贪心:如果n是质数,只需要调用N-1次op2,就是最好的次数.(初始第一次的调用,op1 op2效果相同)
//证明:
// (1) m=a s=2a
// (2) m=2a s=4a 
// 考虑到操作12以及质数的特殊性,如果后续调用一次op1,就拼不出一个质数长度.
//思路:
// 如果N是质数,返回N-1
// 如果N不是质数:(可以是各种质数相乘构成的合数)
// 假设构成n:n=x*y*z 
// 先拼出x*y 再z份 z是个质数,就只需要再调用z-1 op2
// 先拼出x 再y份 y是个质数,就只需要再调用y-1 op2
// 先拼出x  x是个质数,就只需要再调用x-1 op2
// x+y+z-3即找到所有质数因子,累加和减去个数

class SplitNbySM
{
public:
	pair<int, int> divSumAndCount(int n)
	{
		int sum = 0;
		int count = 0;
		for (int i = 2; i <= n; i++)
		{
			while (n % i == 0)
			{
				sum += i;
				count++;
				n /= i;
			}
		}
		return make_pair(sum,count);
	}
	bool isPrime(int val)
	{
		if (val == 1)return false;
		if (val == 2)return true;
		for (int i = 2; i <= sqrt(val); i++)
		{
			if (val % i == 0)
				return false;
		}
		return true;
	}
	int minOps(int n)
	{
		if (n < 2)
			return 0;
		if (isPrime(n))
			return n - 1;
		pair<int, int>ret = divSumAndCount(n);
		return ret.first - ret.second;
	}
};