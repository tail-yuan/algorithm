#include<iostream>
#include<stack>
using namespace std;
//1. ѹ��ʱ,�����min_st����С,������ջ��ѹ��
//2. ����ʱ,�����min_stջ����ͬ,����Ҫ����������
//1_: ά��min_st�дӵ׵������𽥼�С�� 
//2_: ���������Сջ�к����Ѿ�Ӧ�õ�����Ԫ��
class MinStack
{
private:
	stack<int>data_st;
	stack<int>min_st;
public:
	void push(int num)
	{
		data_st.push(num);
		if (min_st.empty())
			min_st.push(num);
		else
		{
			int top_ = min_st.top();
			if (num <= top_)
				min_st.push(top_);
		}
	}
	int pop()
	{
		if (!data_st.empty())
		{
			int top_ = data_st.top();
			data_st.pop();
			if (top_ == min_st.top())
				min_st.pop();
			return top_;
		}
	}
	int getMin()
	{
		if (!min_st.empty())
			return min_st.top();
	}
};