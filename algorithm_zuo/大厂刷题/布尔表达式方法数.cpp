//https://leetcode.cn/problems/boolean-evaluation-lcci/
//给定一个布尔表达式和一个期望的布尔结果 result，布尔表达式由 0 (false)、1 (true)、& (AND)、 | (OR) 和 ^ (XOR) 符号组成。
//实现一个函数，算出有几种可使该表达式得出 result 值的括号方法。
//偶数下标一定是0或者1,奇数下标一定是运算符
//问如果以添加括号的方式改变运算优先级,让整体表达式呈现True 或者false的方法数.
//https://www.bilibili.com/video/BV1NV4y1B7ZZ?p=21&vd_source=cc945ef88574fe2db5e814c0c265a4c7
//题解:
//以i位置操作符为最后参与运算的操作符,此时被划分为两个区间.
//if [i]==&,计算得到左侧区间为True的方法数a,右侧为True的方法数b,整体返回a*b种
//if [i]==|,左侧为True,a种,右侧为Trueb种,左侧为假c种,右侧为假d种.
//	整体返回a*d+b*c+d*c
//所以给定func函数范围,func函数返回范围内为True或者false的方法数
//lr位置必须是0或者1
//因为在划分区间的时候存在重复计算,所以可以改为记忆化搜索.
#include<iostream>
#include<vector>
using namespace std;
class Solution
{
	class Info
	{
	public:
		int t;
		int f;
		Info(int t1 = -1, int f1 = -1)
			:t(t1)
			, f(f1)
		{}
		bool isNULL()
		{
			return t == -1 && f == -1;
		}
	};
	vector<vector<Info>>memo;
public:
	int countEval(string s, int result)
	{
		if (s.size() == 0)return 0;
		int n = s.size();
		memo= vector<vector<Info>>(n,vector<Info>(n));
		Info allInfo = func(s,0,s.size()-1);
		return result == 1 ? allInfo.t : allInfo.f;
	}
private:

	//保证传递的lr位置都是01,不能是运算符
	Info func(string& str, int l, int r)
	{
		if (!memo[l][r].isNULL()) return memo[l][r];
		int t = 0, f = 0;
		if (l == r)
		{
			t = str[l] == '0' ? 0 : 1;
			f = str[l] == '1' ? 0 : 1;
			memo[l][r] = Info(t, f);
			//return Info(t, f);
			return memo[l][r];
		}
		//区间中至少是1个操作符,2个数字
		//枚举每一个操作符为最后一次运算时的操作符
		//这里split变化一定是+2,因为要跳到下一个字符位置
		for (int split = l + 1; split < r; split+=2)
		{
			Info left = func(str, l, split - 1);
			Info right = func(str, split + 1, r);
			int a = left.t, b = left.f;
			int c = right.t, d = right.f;
			if (str[split] == '&')
			{
				t += a * c;
				f += b * c + a * d + b * d;
			}
			else if (str[split] == '|')
			{
				t += a * c + a * d + b * c;
				f += b * d;
			}
			else
			{
				t += a * d + b * c;
				f += a * c + b * d;
			}
		}
		memo[l][r] = Info(t, f);
		//return Info(t, f);
		return memo[l][r];
	}
};