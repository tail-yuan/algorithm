#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//��x���ַ������ƴ�Ӳ��ܵõ���С�ֵ���
//���ֵ���С���ַ���ռ�ݸ�Ȩֵλ(����ǰ��),ʹ�������ַ���Ȩֵ��С
//
//̰��˼��:���f(a+b) < f(b+a),��ô����aƴ����b��ǰ��

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