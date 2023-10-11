#include<iostream>
#include<string>
#include<vector>
#include<stack>
using namespace std;
//规定1和A对应、 2和B对应、 3和C对应...
//那么一个数字字符串比如"111"， 就可以转化为"AAA"、 "KA"和"AK"。
//给定一个只有数字字符组成的字符串str， 返回有多少种转化结果。




//从左到右实现左函数,[1,i-1]位置,[i]数字字符如果为...
// [i]+zuo[i+1,...],
// a: i自己转换 + 后续[i+1]区间内的转换方法
// a: pairr<i,i+1>转换 + 后续[i+2]区间内的转换方法
// 
//如果[i]数字字符是在3到9,那么只能自己转化为对应字母,无法实现和后面一个字符组合->一个字母
//如果[i]数字字符是1,那么a.可以转化为单个字母 b. 可以和后一个组成pair->字母 =>结果就是a+b
//如果[i]数字字符是2,判断[i+1]位置组合起来是否>26,再决定是a+b 还是单个一个a

//如果i位置已经到达最后,说明这是之前选择出来的一种整体有效的结果,return 1
//如果[i]==0,说明之前的转化过程让我这个位置无法转化成字母,从这开始之后都无法转化为,return 0
class ConvertToLetterString
{
public:
	int process(string& str, int i)
	{
		if (i == str.size())
			return 1;
		if (str[i] == '0')
			return 0;
		if (str[i] == '1')
		{
			int res = process(str,i+1);
			if (i + 1 < str.size())
				res += process(str,i+2);
			return res;
		}
		if (str[i] == '2')
		{
			int res = process(str, i + 1);
			if (i + 1 < str.size() && (str[i] >= '0' && str[i] <= '6'))
				res += process(str, i + 2);
			return res;
		}
		//3<=str[i]<=9,只能自己参加转化
		return process(str,i+1);
	}
};