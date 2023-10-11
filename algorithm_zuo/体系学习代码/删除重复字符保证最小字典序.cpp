//给定一个全是小写字母的字符串str，删除多余字符，使得每种字符只保留一个，并让最终结果字符串的字典序最小
//【举例】
//str = "acbc"，删掉第一个'c'，得到"abc"，是所有结果字符串中字典序最小的。
//str = "dbcacbca"，删掉第一个'b'、第一个'c'、第二个'c'、第二个'a'，得到"dabc"，
//是所有结 果字符串中字典序最小的。

// 贪心:
// 每遍历到一个字符,就将词频减一,然后继续往下走,直到某一个字符词频为0,就知道后续没有这个字符了,break->
// 就划定了一个范围,在这个范围中[left,right]
// 如果我只保留一个字符(此时词频为0的字符)str[i],剩下字符全删掉,保证最后能让我每种字符都有,
// 在这个范围中选中码值最小的
// 然后选中这个字符str[i],将它前面的全删掉,将[i,right]的字符串中str[i]字符全删除得到这个字符串tmp
// 递归走remove(tmp)
#include<iostream>
#include<vector>
using namespace std;
class RemoveDuplicateLettersLessLexi
{
public:
	int remove(string& str)
	{
		if (str.size() < 2)
			return 0;
		vector<int>count(256, 0);
		for (int i = 0; i < str.size(); i++)
			count[i]++;
		int minIndex = 0;
		for (int i = 0; i < str.size(); i++)
		{
			if (--count[str[i]] == 0)
				break;
			else
				minIndex = str[minIndex] > str[i] ? i : minIndex;//找到字典序最小的下标
		}
		string next = str.substr(minIndex + 1);
		char target = str[minIndex];
		return str[minIndex] - '0' + remove(next.erase(target));
	}
	int removeDuplicateLettersLessLexi(string& str)
	{
		
	}
};