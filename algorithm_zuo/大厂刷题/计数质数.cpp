//在最原始方式的基础之上,尝试哪些数组组合是完全可以跳过不用再进行判断的,
//偶数就可以直接跳过,
//从小值开始尝试乘积时,乘上的因子是偶数也可以直接跳过
//所以最后就是在1~n数组中,将奇数和奇数的乘积在数组中标记false,
//3*3 3*5 3*7 3*9...
//5*5 5*7 ...
//7*7 7*9 7*11...
//只需要尝试比自己大的和自己相乘,因为比自己小的之前的数字一定已经尝试过了,
//肯定还是存在已经试过的东西,无法避免一个数字多次尝试,只是尽可能的尝试避免
//每乘积得到一个数字就标记他不是素数
//最后找到所有标记为true的数字个数,用count数字的控制代替遍历的方式判断truefalse
#include<iostream>
#include<vector>
using namespace std;
class Solution
{
public:
	int countPrimes(int n) 
	{
		if (n < 3)
			return 0;
		vector<bool>f(n, false);
		int count = n/2;//排除偶数之后剩下的数字,剩下的是可能是素数的个数
		for (int i = 3; i * i < n; i += 2)
		{
			if (f[i])//i位置已经被之前遍历标记位true代表不是素数了,直接跳过
				continue;
			for (int j = i * i; j < n; j+=2*i)//规律下一个就是2*i
			{
				if (!f[j])
				{
					--count;
					f[j] = true;
				}
			}
		}
		return count;

	}
};