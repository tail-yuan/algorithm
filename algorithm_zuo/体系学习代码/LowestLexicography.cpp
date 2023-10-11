#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//将x个字符串如何拼接才能得到最小字典序
//让字典序小的字符串占据高权值位(放在前面),使得整个字符串权值最小
//
//贪心思想:如果f(a+b) < f(b+a),那么就让a拼接在b的前面

struct Compare
{
	bool operator()(const string& s1, const string& s2)
	{
		return strcmp((s1 + s2).c_str(), (s2 + s2).c_str());
	}
};
string LowestString(vector<string>& arr)
{
	if (arr.size() == 0)return "";
	sort(arr.begin(),arr.end(),Compare());
	string res = "";
	for (int i = 0; i < arr.size(); i++)
	{
		res += arr[i];
	}
	return res;
}