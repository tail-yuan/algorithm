//4399笔试
//一堆球,标号分别是1~31
//随手抓一把,为了让手中球字符出现次数都不一样,问最少放回多少个球

#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
vector<int>Func(string& str)
{
	char* tmp = new char[str.size() + 1];
	strcpy(tmp, str.c_str());
	char* cur = strtok(tmp, ",");
	vector<int>ans;
	while (cur != NULL)
	{
		ans.push_back(atoi(cur));
		cur = strtok(NULL, ",");
	}
	delete[]tmp;
	return ans;
}
int return_nums(vector<int>& arr)
{
	//1. 先对数字进行词频统计
	vector<int>cnts(31,0);
	for (int i = 0; i < arr.size(); i++)
		cnts[arr[i]]++;
	//但是else处理方式存在特殊情况,当都只出现一次时,nums中都是1,需要特判,不需要放回
	bool flag = true;
	for (int i = 0; i < cnts.size(); i++)
	{
		if (cnts[i] != 0 && cnts[i] != 1)
			flag = false;
	}
	if (flag)
		return 0;
	else
	{
		//2. 次数相同的划为一组,统计组数
		vector<int>nums;
		for (int i = 0; i < cnts.size(); i++)
		{
			if (cnts[i] != 0)
				nums.push_back(cnts[i]);
		}
		//3. 这回只需要实现nums中的去重操作,即组去重.nums中数字都不一样,代表每种字符出现次数不同
		unordered_set<int>hashSet;
		int count = 0;
		for (int i = 0; i < nums.size(); i++)
		{
			while (hashSet.count(nums[i]) != 0)
			{
				--nums[i];
				count++;
			}
			//都-到0,代表没有这个数字了,就不放到hashSet中了
			if (nums[i] != 0)
				hashSet.insert(nums[i]);
		}
		return count;
	}
}
//int main()
//{
//	string str;
//	cin >> str;
//	vector<int>arr = Func(str);
//	int ret = return_nums(arr);
//	cout << ret << endl;
//	return 0;
//}