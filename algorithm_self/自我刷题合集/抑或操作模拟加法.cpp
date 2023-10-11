#include<iostream>
using namespace std;

class myAdd
{
public:
	string addBinaryStrings(string& a, string& b)
	{
		string ret;
		int carry = 0;
		int i = a.size() - 1;
		int j = b.size() - 1;
		while (i >= 0 || j >= 0 ||carry>=0)
		{
			int sum = carry;
			if (i >= 0)
			{
				sum += a[i] - '0';
				i--;
			}
			if (j >= 0)
			{
				sum += b[j] - '0';
				j--;
			}
			ret = static_cast<char> ((sum % 2) + '0') + ret;
			carry = sum / 2;	//0/2=0 1/2=0 2/2=1 以后进位就这么写
		}
		return ret;
	}
};