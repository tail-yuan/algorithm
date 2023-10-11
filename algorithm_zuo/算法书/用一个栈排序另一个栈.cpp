
#include<iostream>
#include<stack>
using namespace std;
class SortSt
{
	stack<int>help;
public:
	void SortStFunc(stack<int>& st)
	{
		while (!st.empty())
		{
			int cur = st.top(); st.pop();
			if (help.empty() || help.top() >= cur)
			{
				help.push(cur);
			}
			//helpһֱ��ջ,ֱ��help.top() > cur
			while (cur > help.top())
			{
				st.push(help.top());
				help.pop();
			}
			//������
			help.push(cur);
		}
	}
};
class SortStackWithAnotherStack
{
private:
	stack<int>help;
public:
	//1. Ҫʵ��st�д�ջ����ջ���ǴӴ�С,����help���Ǵ�С����,Ȼ������ѹ��st����
	//2. ���cur>help.top(), while help.pop(); else help.push(cur)
	void sortStack(stack<int>& st)
	{
		while (!st.empty())
		{
			int cur = st.top(); st.pop();
			while (!help.empty() && cur < help.top())
			{
				st.push(help.top());
				help.pop();
			}
			help.push(cur);
		}
		//�����˽�ʣ��ķŻ�st
		while (!help.empty())
		{
			st.push(help.top());
			help.pop();
		}
	}
	void f(stack<int>& st)
	{
		while (!st.empty())
		{
			int cur = st.top(); st.pop();
			if (help.empty() || cur < help.top())
				help.push(cur);
			else
			{
				//һֱ��ջ,���ҷ���st��
				while (cur > help.top())
				{
					st.push(help.top());
					help.pop();
				}
				help.push(cur);
			}
		}
	}
};