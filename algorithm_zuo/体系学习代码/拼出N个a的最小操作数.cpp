#include<iostream>
#include<vector>
using namespace std;

//���:
//  s=a m=s 
// op1:m=s s=s+s 
// op2:s=s+m
// ��:����Ҫƴ��n��aʱ���ٵĵ��ò����Ĵ����Ƕ���?
//̰��:���n������,ֻ��Ҫ����N-1��op2,������õĴ���.(��ʼ��һ�εĵ���,op1 op2Ч����ͬ)
//֤��:
// (1) m=a s=2a
// (2) m=2a s=4a 
// ���ǵ�����12�Լ�������������,�����������һ��op1,��ƴ����һ����������.
//˼·:
// ���N������,����N-1
// ���N��������:(�����Ǹ���������˹��ɵĺ���)
// ���蹹��n:n=x*y*z 
// ��ƴ��x*y ��z�� z�Ǹ�����,��ֻ��Ҫ�ٵ���z-1 op2
// ��ƴ��x ��y�� y�Ǹ�����,��ֻ��Ҫ�ٵ���y-1 op2
// ��ƴ��x  x�Ǹ�����,��ֻ��Ҫ�ٵ���x-1 op2
// x+y+z-3���ҵ�������������,�ۼӺͼ�ȥ����

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