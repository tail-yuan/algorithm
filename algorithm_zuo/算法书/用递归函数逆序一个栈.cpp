#include<iostream>
#include<stack>
using namespace std;

class ReverseSt
{
public:
	//将stack栈底元素返回并移除
	//子问题: 相信dfs函数能够将首元素之后的所有元素中栈底元素返回并移除...,数组是将index++,链表是传li->next,栈只能一步步弹栈
	//		返回之后.只考虑开始元素,我弹出了,然后dfs把结果返回给我了,我是不是得重新入栈,所以就重新入栈.
	//		不要过分想具体实现,就宏观的看,然后专注于起始位置得到结果后怎么处理
	//出口:   弹完之后发现为空了,说明就是最后一个元素,记录返回
	//
	int dfs(stack<int>&st)
	{
		int result = st.top(); st.pop();
		if (st.empty())
			return result;
		int tmp= dfs(st);
		st.push(result);
		return tmp;
	}
	// 调用dfs获取栈底元素并移除,然后重新插入就行
	// 获取到栈底元素之后,我相信reverseSt函数能将st中其他元素逆序好,然后我直接把自己插入即可.
	// 1. 调用dfs          2. 调用reverseSt肯定能处理好              3. 之后把自己重新放到栈顶即可
	void reverseSt(stack<int>& st)
	{
		if (st.empty()) return;
		int tmp= dfs(st);
		reverseSt(st);
		st.push(tmp);
	}
};











class ReverseStack
{
public:
	void reverseStack(stack<int>& st)
	{
		if (st.empty())
			return;
		else
		{
			int i = getAndRemoveLastElement(st);
			reverseStack(st);
			st.push(i);
		}
	}
	//获取并移除栈底元素,递归函数中return 的一直是last,在empty()之前就是这个栈底元素返回
	int getAndRemoveLastElement(stack<int>& st)
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
};
int main()
{
	ReverseStack s;
	stack<int> st;
	st.push(1);
	st.push(2);
	st.push(3);
	s.reverseStack(st);
	return 0;
}