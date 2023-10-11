
//给定两个有符号32位整数a和b， 不能使用算术运算符， 分别实现a和b的加、 减、 乘、 除运
//算 【要求】
//如果给定a、 b执行加减乘除的运算结果就会导致数据的溢出， 那么你实现的函数不必对此
//负责， 除此之外请保证计算过程不发生溢出

// 加法:
// c = a ^ b (抑或实现无进位相加效果) 
// d= (a&b)<<1 (进位效果)
// c再和d进行运算,直到d进位信息为0就是总会出现无进位时.
// 减法:
// 就是a+b的相反数(取反和1相加的结果)
// 乘法:
// 二进制每一位去相乘,然后左移一位之后累加即可,二进制都是01
// 代码模拟:
// 当b的最后一位不是0时,就将a的值累加到result上去,然后左移一位a,b做无符号右移直到b为0
// 除法: a/b
// b右移i位,让b最接近但是小于a,然后a=a-b 更新a值,记录右移i位
// 右移一位相当于数值*2,右移i位,相当于b*2^i,在<a的情况下减去得到新的a值,
// 再让b右移去计算更新新的a值以及新的i,拼接所有的i即可得到商
// 因为右移的情况可能存在溢出,所以让a去左移靠近b 更加的安全
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
			b= b>>1;//算术右移
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
		//a值缩小2^i倍即右移i位,减去a的值,记录i
		for (int i = 31; i > -1; i= my_sub(i,1))//从上一次减完的位置再向右移,移的时候不是一位位移的,所以i也与时俱进即可
		{
			if ((x >> i) >= y)
			{
				res |= (1 << i);
				x = my_sub(x,y<<i);
			}
		}
		//如果ab异号,就是负值
		return isNeg(a) ^ isNeg(b) ? negNum(res) : res;
	}
};