//谷歌面试题扩展版面值为1-N的牌组成一组每次你从组里等概率的抽出1~N中的一张,下次抽会换一个新的组，
//有无限组当累加和<a时，你将一直抽牌当累加和>=a且<b时，你将获胜当累加和>=b时，你将失败
//返回获胜的概率，给定的参数为N，a，b


//题解:
//每次都有1/N的概率从[1,N-1]区间选中x,使得累加和到达cur,获胜的概率是p,返回
//以1/n的概率到达cur,获胜的概率是y,那么返回y/N
// N=4,那么此时累加和cur=5赢的概率就是,(p(6)+p(7)+p(8)+p(9))/4=p(5)
//		那么此时累加和cur=4赢的概率就是,(p(6)+p(7)+p(8)+p(5))/4=p(4)
// 此时要想知道p(4)只需要知道p(5)和p(9)就可以求得,就不需要再去枚举一下p(6.7.8)的概率是多少然后返回
// p(4)*N=p(5)+p(5)*4-p(9)
// p(i)*N=p(i+1)+4*p(i+1)-p(i+N+1)
// 这种是距离a比较远的区间,是满足这种特性的
// 当处于a的前一个位置时,并不满足上述公式,p(a-1) = (b-a)/N
// 当处于a的前2个位置时,并不满足上述公式,...
// 当处于b-N-1位置,以及之前的位置时是满足之前公式的. 
// [b-N,a]的范围是特殊范围是需要单列的,区别是是否-后面的尾巴,-p(i+N+1)
//如何等概率? 将枚举行为优化
#include<iostream>
#include<vector>
using namespace std;
class Solution
{
	int n;
	int a;
	int b;
public:
	double func(int N, int a, int b)
	{
		if (a >= b || n == 0 || a < 0 || b < 0)//游戏没法进行下去
			return 0.0;
		if (b - a >= n)//当赢的区域非常大,你抽一张什么牌都赢
			return 1.0;
		vector<double>dp(n);
		for (int i = a; i < b; i++)
			dp[i] = 1.0;
		for (int i = b; i < n; i++)
			dp[i] = 0.0;
		for (int cur = a - 2; cur >= 0; cur--)
		{
			double w = dp[cur + 1] + dp[cur + 1] * N;
			if (cur + 1 + N < b)
				w -= dp[cur + 1 + N];
			dp[cur] = w/N;
		}
		return dp[0];
	}
public:
	//将枚举行为优化
	double getP_plus(int cur)
	{
		if (cur >= a && cur < b)
			return 1.0;
		if (cur > b)
			return 0.0;
		if (cur = a - 1)
			return (b - a) / n;
		double w = getP_plus(cur + 1) + getP_plus(cur + 1) * n;
		if (cur + 1 + n < b)
			w -= getP_plus(cur + 1 + n);
		return w / n;
	}
public:
	double func(int N, int _a, int _b)
	{
		n = N;
		a = _a;
		b = _b;
		if (a >= b || n == 0||a<0||b<0)//游戏没法进行下去
			return 0.0;
		if (b - a >= n)//当赢的区域非常大,你抽一张什么牌都赢
			return 1.0;
		return getP(0);
	}
	double getP(int cur)
	{
		if (cur >= a && cur < b)
			return 1.0;
		if (cur >= b)
			return 0.0;
		double w = 0.0;
		for (int i = 1; i <= n; i++)
			w += getP(cur+i);
		return w / n;
	}
public:
	//具体理解版本n=10 a=17 b=21
	double f()
	{
		return p(0);
	}
	//当你累加和来到cur时,返回你的获胜概率
	double p(int cur)
	{
		if (cur >= 17 && cur < 21)
			return 1.0;
		if (cur >= 21)
			return 0.0;
		double w = 0.0;
		for (int i = 1; i <= 10; i++)
			w += p(cur + i);
		return w / 10;
	}
};