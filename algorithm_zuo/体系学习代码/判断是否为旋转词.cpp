#include<iostream>
#include<vector>
using namespace std;
//题干:
//如果一个字符串为str，把字符串str前面任意的部分挪到后面形成的字符串叫
//作str的旋转词。比如str = "12345"，str的旋转词有"12345"、"23451"、
//"34512"、"45123"和"51234"。给定两个字符串a和b，请判断a和b是否互为旋转词。
//比如：
//a = "cdab"，b = "abcd"，返回true。
//a = "1ab2"，b = "ab12"，返回false。
//a = "2ab1"，b = "ab12"，返回true。

// 1. 判断字符串长度是否相同
// 2. 如果相同,a=a+a,然后判断b是否是a的子串(KMP算法),如果是就是旋转词
// 任意n个连续的字符串都互为旋转词
class isRotation
{
public:
	bool isTrue(string& str1, string& str2)
	{
		if (str1.size() != str2.size())
			return false;
		string tmp = str1 + str1;
		return getIndexOf(tmp,str2)!=-1;
	}
	//获取i位置之前,最大(前缀=后缀)值,放在next[i]中记录
	vector<int>getNextArr(string& str)
	{
		if (str.size() == 1)
			return {-1};
		vector<int>next(str.size());
		next[0] = -1;//0前面没字母.-1
		next[1] = 0;
		int i = 2;
		int cn = 0;
		//1. cn位置,前缀字符串的下一个位置和第i个字符比较
		//2. 因为下标和值差一的关系,cn可直接表示长度
		while (i < next.size())
		{
			if (str[i - 1] == str[cn])
				next[i++] = ++cn;
			else if (cn > 0)//可以往前跳
				cn = next[cn];
			else
				next[i++] = 0;
		}
		return next;
	}
	//KMP 获取在str1中的起始位置
	int getIndexOf(string& str1, string& str2)
	{
		if (str1.size() == 0 || str2.size() > str1.size())
			return -1;
		int i1 = 0, i2 = 0;
		vector<int>next = getNextArr(str2);
		while (i1 < str1.size() && i2 < str2.size())
		{
			if (str1[i1] == str2[i2])
			{
				i1++;
				i2++;
			}
			else if (next[i2 == -1])
				i1++;
			else
				i2 = next[i2];
		}
		return i2 == str2.size() ? i1 - i2 : -1;//长-短得到起始下标
	}
};
