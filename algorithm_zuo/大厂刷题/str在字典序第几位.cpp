//https://www.bilibili.com/video/BV1NV4y1B7ZZ?p=57&vd_source=cc945ef88574fe2db5e814c0c265a4c7
//给定一个长度Len，表示一共有几位所有字符都是小写(a~z)，
// 可以生成长度为1，长度为2长度为3...长度为len的所有字符串
// 如果把所有字符串根据字典序排序，
// 每个字符串都有所在的位置给定一个字符串str，给定len，
// 请返回str是总序列中的第几个
// 比如len = 4，字典序的前几个字符串为:
// a aa aaa ... aaaz .... azzz 
// b ba baa baaaa aa aaa aaaa aaab ... aaaz ..... bzzz ...c...
// a是这个序列中的第1个，bzzz是这个序列中的第36558个
//比如给定字符串str=cdb,请问他是长度len=7的所有可能字符串中第几个(以字典序排列)
//以a,b为开头,剩下长度为0~6的所有可能性sum(a,b)+以c开头,剩下长度为0的可能性c=1
//这些情况都在cdb字典序之前,剩下db仍未得到排序,继续...
// 开头为ca剩下长度为0~5的所有可能性甲个,以cb开头的乙个,以cc开头的丙个,以cd开头的1个
//继续,以cda为开头,剩下长度为0~4个的所有可能性丁个,到位了此时.
//另外: 以任意字符ch开头剩下长度为0~n的所有可能性和为 1+26^2+26^3+26^4+...+26^n
//提供这个函数f(n)


#include<iostream>
#include<vector>
using namespace std;
class Solution
{
public:
	int f(int n)
	{
		int ans = 1;
		for (int i = 1, base = 26; i <= n; i++, base *= 26)
			ans += base;
		return ans;
	}
	int stringKth(int len, string& str)
	{
		if (str.size() == 0 || str.size() > len)
			return 0;
		int ans = 0;
		for (int i = 0, rest = len - i; i < str.size(); i++, rest--)
		{
			//有几股0~rest这些情况,f无论以谁打头
			ans += (str[i] - 'a') * f(rest) + 1;
		}
		return ans;
	}
};
