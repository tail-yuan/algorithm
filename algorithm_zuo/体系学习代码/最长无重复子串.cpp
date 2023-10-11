//在一个字符串中找到没有重复字符子串中最长的长度。
//例如：
//abcabcbb没有重复字符的最长子串是abc，长度为3
//bbbbb，答案是b，长度为1
//pwwkew，答案是wke，长度是3
//要求：答案必须是子串，"pwke" 是一个子字符序列但不是一个子字符串。

//遇到子串问题,想的都是以i位置为结尾....
//以i位置为结尾,能向前到达的最长子串长度->dp[i]
//dp[i-1]记录的是从i-1位置向前推最远无重复子串,也就是说在i-dp[i]位置出现了重复字符
// 1. i位置字符在dp[i]所在区间中不重复,那么最远只能和dp[i-1]+1
// 2. i位置字符在dp[i]所在区间中有重复,那么找到重复的位置j,dp[i]= i-j
//例1: dp[i-1]=5 
// a b c d e  a  ?
//       j   i-1 i		1.如果 ?=h,dp[i]=dp[i-1]+1  2. 如果?=d,dp[i]=i-j
//即:两个限制,一个是i字符上次出现的位置,一个是i-1上一次出现的位置,那个近那个就是最终限制
#include<iostream>
#include<vector>
using namespace std;
class LongestNoRepeatSubstring
{
public:
	int maxUnique(string& str)
	{
		if (str.size() == 0)
			return 0;
		vector<int>hashMap(256,-1);//记录某一个字符上次出现的位置
		int ret = 0;
		int pre = -1;
		int cur = 0;
		for (int i = 0; i < str.size(); i++)
		{
			pre = max(pre, hashMap[i]);
			cur = i - pre;
			ret = max(ret, cur);
			hashMap[str[i]] = i;
		}
	/*	for (int i = 0; i < str.size(); i++)
		{
			pre = max(pre,hashMap[i]);
			int cur = i - pre;
			ret = max(ret, cur);
			hashMap[str[i]] = i;
		}*/
		return ret;
	}
};