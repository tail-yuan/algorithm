//����һ���ַ���str,str��ʾһ����ʽ�Ӽ��˳����ź�����������,���ع�ʽ�ļ�����
// �ѵ��������ſ���Ƕ�׺ܶ��
//str="48*((70-65)-43)+8*1"������-1816
//str="3+1*4"������7
//str="3+(1*4)"������7
//[˵��]
//1. ����Ҫ�������ַ������й�ʽ��Ч�Լ��
//2. ����Ǹ���,����Ҫ������������.4*(-3).-3*4Ҳ���Բ���������.
//3. ���ÿ��Ǽ�����������������.

//���:
// ���û��(),ֻ��+-*/��������,ʹ��ջ��������.(�����ֱ���ô�ǰ�������getNum,����ʹ��deque��)
// ����func(index)��������,����index,����ֵ�Ǽ�������
// ����λ��ҪôΪ),Ҫô�����ַ����Ľ�β.
//��ôֻҪ�������ұ���,����(,�ͽ���һ��λ�ý���func(),
//ͨ�����ֵ��õݹ�ķ�ʽ,ʵ�����������ݵ���������,Ȼ�󽫼��������ظ���һ�㺯��.
//�ڴ˻�����,��Ϊ��һ����յ�()������֮����Ҫ��()��һ��λ�ü�������,������ʼλ�ò�֪��,����func����
//�ڷ��ؼ���ǹ�֮��,�ٽ�����λ��)����,��ô��һ���ٴο�ʼ�ʹӷ��صĽ���λ�ÿ�ʼ.
//������ά����һ���� ����,�ַ�,����,�ַ�...

///ʹ��func�ݹ���õķ�ʽ���Խ�����������Ƕ������.ֻҪ�����������,�ͽ���func�������֮��,������ͽ���λ��
///���ظ���һ����ü�������
#include<iostream>
#include<queue>
using namespace std;

class Solution
{
public:
	int calculate(string& str)
	{
		return func(str, 0).first;
	}
	//<���,�ĸ�λ��ͣ��>
	pair<int, int> func(string& str, int i)
	{
		//stack<int>st;
		deque<int>dq;
		int cur = 0;
		pair<int, int>bra;
		while (i < str.size() && str[i] != ')')
		{
			if (str[i] > '0' && str[i] < '9')//�ռ�����
				cur = cur * 10 + (str[i] - '0'), i++;
			else if (str[i] != '(')//�����
			{
				addNum(cur, dq,str[i]);//int.+-��*/�������ȼ���װ��AddNum�����н���
				i++;
				cur = 0;
			}
			else//(,�ӵ��ݹ���,����ֵbraץס,����
			{
				bra = func(str, i + 1);
				cur = bra.first;
				i = bra.second+1;//����λ����),����һ��λ�ÿ�ʼ����
			}
		}
		addNum(cur, dq,'+');//����)�˳���,��û�����һ������ѹ��ջ��
		return {getNum(dq),i};//str[i]=)
	}
	void addNum(int cur, deque<int>& st,char op)
	{
		if (!st.empty() && (st.back() == '*' || st.back() == '/'))
		{
			char opt = st.back(); st.pop_back();
			int x = st.back(); st.pop_back();
			cur = opt == '*' ? (x * cur) : (x / cur);
		}
		st.push_back(cur);
		st.push_back(op);
	}
	int getNum(deque<int>& st)
	{
		int ans = st.front(); st.pop_front();
		while (!st.empty())
		{
			char opt = st.front(); st.pop_front();
			int y = st.front(); st.pop_front();
			ans += opt == '+' ? (y) : (-y);
		}
		return ans;
	}
	void test()
	{
		deque<int>st;
		st.push_back(1);
		st.push_back('+');
		st.push_back(2);
		st.push_back('-');
		st.push_back(3);
		st.push_back('+');
		st.push_back(4);
		int ret = getNum(st);
	}
};
//int main()
//{
//	Solution s;
//	s.test();
//}