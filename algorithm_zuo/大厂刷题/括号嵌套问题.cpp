//给定一个字符串str,str表示一个公式加减乘除符号和左右有括号,返回公式的计算结果
// 难点在于括号可能嵌套很多层
//str="48*((70-65)-43)+8*1"，返回-1816
//str="3+1*4"，返回7
//str="3+(1*4)"，返回7
//[说明]
//1. 不需要对输入字符串进行公式有效性检查
//2. 如果是负数,就需要用括号括起来.4*(-3).-3*4也可以不用扩起来.
//3. 不用考虑计算过程中溢出的问题.

//题解:
// 如果没有(),只有+-*/四则运算,使用栈辅助运算.(后序发现必须得从前往后计算getNum,所以使用deque了)
// 就是func(index)函数作用,给定index,返回值是计算结果和
// 结束位置要么为),要么就是字符串的结尾.
//那么只要从左往右遍历,遇到(,就将下一个位置交给func(),
//通过这种调用递归的方式,实现括号中内容的区别运算,然后将计算结果返回给上一层函数.
//在此基础上,因为上一层接收到()计算结果之后需要从()下一个位置继续计算,但是起始位置不知道,所以func函数
//在返回计算记过之外,再将结束位置)返回,那么上一层再次开始就从返回的结束位置开始.
//队列中维护的一定是 数字,字符,数字,字符...

///使用func递归调用的方式可以解决更多的括号嵌套问题.只要是括号里面的,就交给func计算完成之后,将结果和结束位置
///返回给上一层调用继续进行
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
	//<结果,哪个位置停的>
	pair<int, int> func(string& str, int i)
	{
		//stack<int>st;
		deque<int>dq;
		int cur = 0;
		pair<int, int>bra;
		while (i < str.size() && str[i] != ')')
		{
			if (str[i] > '0' && str[i] < '9')//收集数字
				cur = cur * 10 + (str[i] - '0'), i++;
			else if (str[i] != '(')//运算符
			{
				addNum(cur, dq,str[i]);//int.+-和*/运算优先级封装到AddNum函数中进行
				i++;
				cur = 0;
			}
			else//(,扔到递归中,返回值bra抓住,接上
			{
				bra = func(str, i + 1);
				cur = bra.first;
				i = bra.second+1;//结束位置是),从下一个位置开始计算
			}
		}
		addNum(cur, dq,'+');//遇到)退出了,还没把最后一个数字压入栈中
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