#include<iostream>
#include<stack>
using namespace std;
//1�� ��� stackPush Ҫ�� stackPop ��ѹ�����ݣ���ô����һ���԰� stackPush �е�����ȫ��ѹ�롣
//2�� ��� stackPop ��Ϊ�գ� stackPush ���Բ����� stackPop ��ѹ�����ݡ�
class MyQueue
{
private:
	stack<int> pushSt;
	stack<int>popSt;
public:
	void pushTopop()
	{
		if (popSt.empty())
		{
			while (!pushSt.empty())
			{
				popSt.push(pushSt.top());
				pushSt.pop();
			}
		}
	}
	void push(int num)
	{
		pushSt.push(num);
	}
	int pop()
	{
		if (popSt.empty() && pushSt.empty())
			return -1;
		pushTopop();
		int ret=popSt.top();
		popSt.pop();
		return ret;
	}
	int top()
	{
		if (popSt.empty() && pushSt.empty())
			return -1;
		pushTopop();
		return popSt.top();
	}
};