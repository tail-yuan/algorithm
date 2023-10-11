//https://leetcode.cn/problems/valid-parentheses/submissions/
//ʹ��ջ�ṹ,�������ž�ѹջ,���Ǿ͵���ջ��,���ҽ���ƥ��.
//�м䵯����,���߲�ƥ���false.�������֮��ջӦ���ǿյĲ�True

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
	//Ӧ��ѹ������ʱѹ�������Ӧ��������,����ֱ�ӱȶ���ȼ���
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
	//ʹ��ϵͳ�ṩ��ջ���Լ�ʵ�ֵ�ջҪ��,����ʹ��������ʽģ��,�Ż�����ʱ��
	bool isValidParent(string& str)
	{
		if (str.size() == 0)
			return true;
		int n = str.size();
		const int N = 10001;//��Ŀ����str����,������ļ���
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