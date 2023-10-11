#include<iostream>
#include<string>
#include<vector>
#include<stack>
using namespace std;


class ReverseStackUsingRecursive
{
public:
	int getAndRemoveLastElement(stack<int>st)
	{
		int result = st.top(); st.pop();
		if (st.empty())
			return result;
		else
		{
			int last = getAndRemoveLastElement(st);
			st.push(result);
			return last;
		}
	}
	void reverse(stack<int>st)
	{
		if (st.empty())
			return;
		int i = getAndRemoveLastElement(st);
		reverse(st);
		st.push(i);
	}
};