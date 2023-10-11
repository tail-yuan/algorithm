
#include<iostream>
using namespace std;
class GetMax
{
public:
	//n ==1 ? 0 : 1
	int flip(int n)
	{
		return n ^ 1;
	}
	int sign(int n)
	{
		return flip((n >> 31) & 1);//得到符号位 负数&1=1 flip()->0 正数&1=0 flip()->1
	}
	//可能存在溢出的情况(正数-负数得到一个溢出的正数)
	int getMax(int a, int b)
	{
		int c = a - b;
		int scA = sign(c); //a>b c>0 scA=1 
		int scB = flip(scA);// scB*scA=0
		return a * scA + b * scB;//谁大sc就是1,就返回谁
		//将互斥事件相加替换if-else
	}
	int getMax2(int a,int b)
	{
		int c = a - b;
		int sa = sign(a);// 负数->0 非负数->1
		int sb = sign(b);
		int sc = sign(c);
		int difSab = sa ^ sb;//a和b的符号不一样->1 一样->0
		int sameSab = flip(difSab);
		//什么时候返回A是较大值?
		//1. ab符号相同&&c>0即sameSab*sc
		//2. ab符号不同&&a>0即difSab*sa
		//互斥条件相加代替if-else
		int returnA = sameSab * sc + difSab * sa;
		int returnB = flip(returnA);
		return a * returnA + b * returnB;
	}
};