
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
		return flip((n >> 31) & 1);//�õ�����λ ����&1=1 flip()->0 ����&1=0 flip()->1
	}
	//���ܴ�����������(����-�����õ�һ�����������)
	int getMax(int a, int b)
	{
		int c = a - b;
		int scA = sign(c); //a>b c>0 scA=1 
		int scB = flip(scA);// scB*scA=0
		return a * scA + b * scB;//˭��sc����1,�ͷ���˭
		//�������¼�����滻if-else
	}
	int getMax2(int a,int b)
	{
		int c = a - b;
		int sa = sign(a);// ����->0 �Ǹ���->1
		int sb = sign(b);
		int sc = sign(c);
		int difSab = sa ^ sb;//a��b�ķ��Ų�һ��->1 һ��->0
		int sameSab = flip(difSab);
		//ʲôʱ�򷵻�A�ǽϴ�ֵ?
		//1. ab������ͬ&&c>0��sameSab*sc
		//2. ab���Ų�ͬ&&a>0��difSab*sa
		//����������Ӵ���if-else
		int returnA = sameSab * sc + difSab * sa;
		int returnB = flip(returnA);
		return a * returnA + b * returnB;
	}
};