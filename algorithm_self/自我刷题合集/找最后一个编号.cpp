#include<iostream>
#include<vector>
#include<deque>
using namespace std;
//因为vector的连续性以及去除某一个元素涉及到的数据移动,或者采用其他方式维护的成本过高
//所以使用deque
int FindLastChar(int n,int m)
{
	if (n <= 0 || m <= 0)return -1;
	deque<int> arr;
	for (int i = 1; i <= n; i++)
		arr.push_back(i);
	while (arr.size() > 1)
	{
		for (int i = 1; i < m; i++)//注意次数
		{
			arr.push_back(arr.front());
			arr.pop_front();
		}
		arr.pop_front();
	}
	int last = arr.front();
	return last;
}

int main()
{
	int n = 0, m = 0;
	cin >> n >> m;
	int ret = FindLastChar(n, m);
	cout << ret << endl;
}