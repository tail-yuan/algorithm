
//1. 给定一个函数f， 可以1～5的数字等概率返回一个。 请加工出1～7的数字等概率返回一个的函数g。
	
//2. 给定一个函数f， 可以a～b的数字等概率返回一个。 请加工出c～d的数字等概率返回一个的函数g。
// 构建0 1等概率,然后拼接二进制位即可
// 
//3. 给定一个函数f， 以p概率返回0， 以1-p概率返回1。 请加工出等概率返回0和1的函数g
// 产生两次,00 11重做, 01 10 都是p*(1-p)等概率,约定01是0 10 是1,构建了0 1产生等概率.


#include<iostream>
#include<vector>
using namespace std;

class Rand5ToRand7
{
public:
	int rand1To5()
	{
		return (int)(rand() % 5 + 1);
	}
	int r01()
	{
		int res = 0;
		do
		{
			res = rand1To5();
		} while (res == 3);
		return res < 3 ? 0 : 1;
		//1 2 ->0
		//4 5 ->1
		//3 重做
	}
	int rand1To7()//二进制三位是[0,7],我只要[0,6],遇到7 就重做,然后集体加1,即可得到1~7
					//											集体加30,即可得到30~36   m~n
	{
		int num = 0;
		do 
		{
			num = r01() << 2 + r01() << 1 + r01();
		} while (num==7);
		return num + 1;
	}

	int rand01p()
	{
		double p = 0.83;
		return rand() % 1 < p ? 0 : 1;
	}
	int rand01()
	{
		int num;
		do
		{
			num = rand01p();
		}while (num==rand01p());//两次等概率产生都是0,或者都是1,00 11时重新生成,直到出现01或10
		return num;//num是0就返回0,是1就返回1
	}
};