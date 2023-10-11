#include<iostream>
#include<stack>
using namespace std;

class ReverseSt
{
public:
	//��stackջ��Ԫ�ط��ز��Ƴ�
	//������: ����dfs�����ܹ�����Ԫ��֮�������Ԫ����ջ��Ԫ�ط��ز��Ƴ�...,�����ǽ�index++,�����Ǵ�li->next,ջֻ��һ������ջ
	//		����֮��.ֻ���ǿ�ʼԪ��,�ҵ�����,Ȼ��dfs�ѽ�����ظ�����,���ǲ��ǵ�������ջ,���Ծ�������ջ.
	//		��Ҫ���������ʵ��,�ͺ�۵Ŀ�,Ȼ��רע����ʼλ�õõ��������ô����
	//����:   ����֮����Ϊ����,˵���������һ��Ԫ��,��¼����
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
	// ����dfs��ȡջ��Ԫ�ز��Ƴ�,Ȼ�����²������
	// ��ȡ��ջ��Ԫ��֮��,������reverseSt�����ܽ�st������Ԫ�������,Ȼ����ֱ�Ӱ��Լ����뼴��.
	// 1. ����dfs          2. ����reverseSt�϶��ܴ����              3. ֮����Լ����·ŵ�ջ������
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
	//��ȡ���Ƴ�ջ��Ԫ��,�ݹ麯����return ��һֱ��last,��empty()֮ǰ�������ջ��Ԫ�ط���
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