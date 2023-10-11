#include<iostream>
#include<vector>
using namespace std;
bool isPrime(int n)
{
	if (n <= 1)
		return false;
	for (int i = 2; i * i < n; i++)
		if (n % i == 0)
			return false;
	return true;
}
int findK(int n)
{
	for (int i = n; i >= 2; i--)
	{
		if (isPrime(i))
			return i;
	}
	return -1;
}
int main()
{
	int n = 0;
	cin >> n;
	int ret=findK(n);
	cout << ret << endl;
	return 0;
}