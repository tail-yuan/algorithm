#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class Info
{
public:
	int cost;
	int minVal;
public:
	Info(int c, int m)
		:cost(c)
		, minVal(m)
	{}
};
vector<string> Func(string str)
{
	char* tmp = new char[str.size() + 1];
	strcpy(tmp, str.c_str());
	char* cur = strtok(tmp, ":,");
	vector<string>arr;
	while (cur)
	{
		arr.push_back(cur);
		cur = strtok(NULL, ":,");
	}
	delete[] tmp;
	return arr;
}
struct Less
{
	bool operator()(Info& i1, Info& i2)
	{
		bool flag = false;
		if (i1.minVal < i2.minVal) flag = true;
		if (i1.minVal == i2.minVal)
		{
			if (i1.cost > i2.cost)flag = true;
		}
		return !flag;
	}
};
int main()
{
	string str;
	cin >> str;
	if (str.size() == 0)
		cout << 0 << endl;

	vector<string>arr = Func(str);
	priority_queue<Info, vector<Info>, Less> pq;
	for (int i = 0; i < arr.size() - 1; i+=2)
	{
		int key = atoi(arr[i].c_str()), val = atoi(arr[i + 1].c_str());
		pq.push(Info(key,val));
	}
	//根据val建立小堆,网上推导毫安时
	//while (!pq.empty())
	//{
	//	Info top = pq.top(); pq.pop();
	//	cout << top.cost << " ";
	//}
	Info cur = pq.top(); pq.pop();
	int sum = cur.minVal;
	vector<Info>v;
	while (!pq.empty() && sum <= 4800)
	{
		cur = pq.top(); pq.pop();
		v.push_back(cur);
		int x = cur.cost;
		sum += x;
	}
	cout << (sum > 4800 ? -1 : sum) << endl;
	return 0;
}