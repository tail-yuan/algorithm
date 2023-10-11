#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<cstring>
#include<unordered_map>
#include<map>
using namespace std;
vector<string>Func(string str)
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
	return arr;
}
int main()
{
	int aim = 0;
	cin >> aim;
	string str;
	cin >> str;
	vector<string> arr = Func(str);
	map<int, int>treeMap;
	int n = arr.size();
	for (int i = 0; i < n - 1; i += 2)
	{
		int key = atoi(arr[i].c_str()), val = atoi(arr[i + 1].c_str());
		treeMap.insert({ key,val });
	}
	auto ret1 = treeMap.lower_bound(aim);
	if (ret1 == treeMap.end())
		printf("%.1lf\n", atoi(arr[n - 1].c_str()) / 1.0);
	//cout << ret->second << endl;
	else
	{
		auto tmp = ret1;
		auto ret2 = ret1;
		if (ret1 != treeMap.begin())
			ret2 = --ret1;
		ret1 = tmp;
		// cout << ret1->second << " " << ret2->second << endl;

		if (ret1->first - aim < aim - ret2->first)
			printf("%.1lf\n", ret1->second / 1.0);
		else if (ret1->first - aim > aim - ret2->first)
			printf("%.1lf\n", ret2->second / 1.0);
		else
			printf("%.1lf\n", (ret1->second + ret2->second) / 2.0);
	}
	return 0;
}