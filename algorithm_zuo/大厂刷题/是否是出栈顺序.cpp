#include<iostream>
#include<stack>
using namespace std;
class Solution
{
	string in;
public:
	//��out[j]�ַ�����֮ǰ,��һ����ջ��,����in[j]֮ǰ��һ������ջ��
	//Ȼ��out[j]һ��㵯��,����ǳ�ջ˳��,��Ȼ������stΪ��
	bool isLegal(string& out)
	{
		int j = 0;
		stack<char>st;
		for (int i = 0; i < in.size(); i++)
		{
			st.push(in[i]);
			while (!st.empty() && out[j] == st.top())
			{
				st.pop();
				j++;
			}
		}
		return st.empty();
	}
};