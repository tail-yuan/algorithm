#include<iostream>
#include<stack>
using namespace std;
class Solution
{
	string in;
public:
	//在out[j]字符出来之前,他一定在栈顶,并且in[j]之前的一定都进栈了
	//然后将out[j]一点点弹出,如果是出栈顺序,必然结束后st为空
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