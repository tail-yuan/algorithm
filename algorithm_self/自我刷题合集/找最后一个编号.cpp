#include<iostream>
#include<vector>
#include<deque>
using namespace std;
//��Ϊvector���������Լ�ȥ��ĳһ��Ԫ���漰���������ƶ�,���߲���������ʽά���ĳɱ�����
//����ʹ��deque
int FindLastChar(int n,int m)
{
	if (n <= 0 || m <= 0)return -1;
	deque<int> arr;
	for (int i = 1; i <= n; i++)
		arr.push_back(i);
	while (arr.size() > 1)
	{
		for (int i = 1; i < m; i++)//ע�����
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