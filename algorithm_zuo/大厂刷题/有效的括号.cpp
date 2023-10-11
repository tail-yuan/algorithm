//https://leetcode.cn/problems/valid-parentheses/submissions/
//使用栈结构,是左括号就压栈,不是就弹出栈顶,和我进行匹配.
//中间弹空了,或者不匹配就false.遍历完成之后栈应该是空的才True

#include<iostream>
#include<stack>
#include<unordered_map>
using namespace std;
class Solution
{
public:
	bool isValidParent(string& str)
	{
		if (str.size() == 0)
			return true;
		unordered_map<char, char>hashMap;
		hashMap[')'] = '(';
		hashMap[']'] = '[';
		hashMap['}'] = '{';

		stack<char>st;
		for (int i = 0; i < str.size(); i++)
		{
			if (str[i] == '(' || str[i] == '[' || str[i] == '{')
				st.push(str[i]);
			else
			{
				if (st.empty() || st.top() != hashMap[str[i]])
					return false;
				else
					st.pop();
			}
		}
		return st.empty() ? true : false;
	}
	//应该压左括号时压入和他对应的右括号,后序直接比对相等即可
	bool isValidParent(string& str)
	{
		if (str.size() == 0)
			return true;
		stack<char> st;
		for (int i = 0; i < str.size(); i++)
		{
			if (str[i] == '(' || str[i] == '[' || str[i] == '{')
				st.push(str[i] == '(' ? ')' : (str[i] == '[' ? ']' : '}'));
			else
			{
				if (st.empty() || st.top() != str[i])
					return false;
				else
					st.pop();
			}
		}
		return st.empty() ? true : false;
	}
	//使用系统提供的栈比自己实现的栈要慢,可以使用数组形式模拟,优化常数时间
	bool isValidParent(string& str)
	{
		if (str.size() == 0)
			return true;
		int n = str.size();
		const int N = 10001;//题目限制str长度,任意更改即可
		char st[N] = {0};
		int size = 0;
		for (int i = 0; i < n; i++)
		{
			if (str[i] == '(' || str[i] == '[' || str[i] == '{')
				st[size++] = str[i] == '(' ? '}' : (str[i] == '[' ? ']' : '}');
			else
			{
				if (size == 0 || st[--size] != str[i])
					return false;
			}
		}
		return size == 0 ? true : false;
	}
};