
#include<iostream>
#include<stack>
using namespace std;

class StackSortStack
{
public:
	void stackSortStack(stack<int>& st)
	{
		stack<int>stHelper;
		while (!st.empty())
		{
			int tmp = st.top(); st.pop();
			if (stHelper.empty() || tmp <= stHelper.top())
			{
				//stHelper.push(tmp);
			}
			else
			{
				//µ¯µ½±ÈtopÐ¡
				while (tmp > stHelper.top())
				{
					st.push(stHelper.top());
					stHelper.pop();
				}
				//stHelper.push(tmp);
			}
			stHelper.push(tmp);
		}
		while (!stHelper.empty())
		{
			st.push(stHelper.top());
			st.pop();
		}
	}
};