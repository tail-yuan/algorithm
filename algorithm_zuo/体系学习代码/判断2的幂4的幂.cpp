#include<iostream>
using namespace std;


class Power
{
public:
	//��������ֻ����һ��1
	bool power2(int x)
	{
		return (x & (x - 1)) == 0;
	}
	// 0x0000001
	// 0x0000100
	// 0x0010000
	// 0x1000000
	//&=
	//0101010101 ֻҪ��4���ݴη��õ�����λ�Ͼ���
	bool power4(int x)
	{
		return ((x & (x - 1)) == 0) &&((x & 0x55555555) != 0);
	}
};
int main()
{
	Power p;
	cout<<p.power2(16);
	cout<<p.power4(16);
}