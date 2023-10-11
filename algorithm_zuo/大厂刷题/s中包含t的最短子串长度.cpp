//引例: 找到最短包含子串的长度
//s 中包含t串所有字符的最短子串长度,t中字符在s中出现的顺序可以是无序的.
//单调性: s中子串区间越大,包含的t的字符就越多
//使用滑动窗口: 欠债还款模型
//当r==s.zie()时停止,所以是以i位置为结尾的模型
//https://leetcode.com/problems/minimum-window-substring/submissions/
//拓展: 找到这个字符串
#include<iostream>
using namespace std;
class Solution
{
public:
	string minWindow(string s, string t) 
	{
		if (s.size() < t.size())return "";
		int hash[256] = { 0 };
		for (char ch : t)
			hash[ch]++;
		int all = t.size();
		int l = 0, r = 0;
		int minLen = INT_MAX;
		int start = 0;
		while(r<s.size())
		{
			hash[s[r]]--;
			if (hash[s[r]] >= 0)
				all--;
			if (all == 0)//当所有该还的在这个窗口就可以还完时,尝试缩小左边界,找最短子串.
						//也就是l位置字符可能是多还给你的,在上述操作之后hash[s[l]]<0
			{
				while (hash[s[l]] < 0)
					hash[s[l++]]++;
				if (minLen > r - l + 1)
				{
					minLen = r - l + 1;
					start = l;
				}
				//l++
				hash[s[l++]]++;
				all++;
			}
			r++;
		}
		return minLen==INT_MAX?"":s.substr(start, minLen);
	}
public:
	int minLength(string& s, string& t)
	{
		if (s.size() < t.size())return 0;
		//首先将t中字符统计
		int countMap[256] = { 0 };
		for (int i = 0; i < t.size(); i++)
			countMap[t[i]]++;
		int all = t.size();
		int l = 0, r = 0;
		int minLen = INT_MAX;
		while (r != s.size())
		{
			countMap[s[r]]--;//还款
			if (countMap[s[r]] > 0)
				all--;
			if (all == 0)//都还完了,就可以缩小窗口了
			{
				while (countMap[s[l]] < 0)//一直缩小l
					countMap[s[l++]]++;
				minLen = min(minLen, r - l + 1);//缩小到最短的,还完款的子串
				//l++
				countMap[s[l]]++;
				all++;
			}
			r++;
		}
		return minLen == INT_MAX ? 0 : minLen;
	}
};