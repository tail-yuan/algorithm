#include<iostream>
using namespace std;


class Power
{
public:
	//二进制上只能有一个1
	bool power2(int x)
	{
		return (x & (x - 1)) == 0;
	}
	// 0x0000001
	// 0x0000100
	// 0x0010000
	// 0x1000000
	//&=
	//0101010101 只要在4的幂次方得到的数位上就是
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