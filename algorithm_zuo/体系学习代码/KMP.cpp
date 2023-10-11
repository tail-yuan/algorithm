#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;
//M < N 所以T=O(N)
class KMP
{
public:
	//O(M)
	vector<int> getNextArr(string& str)
	{
		vector<int>next(str.size());
		next[0] = -1;
		next[1] = 0;
		if (str.size() == 1)
			return next;
		int i = 2;
		int cn = 0;
		//1. 代表是cn位置的值(前缀的下一个位置)和第i个字符比较
		//2. 前缀的长度是多少
		while (i < next.size())
		{
			if (str[i - 1] == str[cn])
				next[i++] = ++cn;//解决完第i个位置(下标i-1)=cn+1,下一个位置i+1(下标i)马上会使用i位置的值
			else if (cn > 0)//cn可以往前跳
				cn = next[cn];
			else//没法往前跳了
				next[i++] = 0;
		}
		return next;
	}
	int getIndexOf(string& str1, string& str2)
	{
		if (str1.size() == 0 || str2.size()>str1.size())
			return -1;
		int i1 = 0;
		int i2 = 0;
		vector<int> next = getNextArr(str2);//O(M)
		//O(N)
		while (i1 < str1.size() && i2 < str2.size())
		{
			if (str1[i1] == str2[i2])
			{
				i1++;
				i2++;
			}
			else if (next[i2] == -1)// i2==0,无法再向前跳
				i1++;
			else//遇到不相等的位置了,就向前跳
				i2 = next[i2];
		}
		//只要有i2跳出循环说明是匹配成功了
		//只有i1出来,说明不成功
		return i2 == str2.size() ? i1 - i2 : -1;
	}
};