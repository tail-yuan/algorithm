// 来自腾讯
// 给定一个只由0和1组成的字符串S，假设下标从1开始，
// 规定i位置的字符价值V[i]计算方式如下 : 
// 1) i == 1时，V[i] = 1
// 2) i > 1时，如果S[i] != S[i-1]，V[i] = 1
// 3) i > 1时，如果S[i] == S[i-1]，V[i] = V[i-1] + 1
// 你可以随意删除S中的字符，返回整个S的最大价值
// 字符串长度<=5000

//00000000011000000: 为了获得最大价值,将中间两个11删除
//0011111111100: 结果就是中间那一串1
//从左到右模型,到达i位置时是保留还是删除,i位置不受之前情况影响
//但是这个题i位置的保留删除是根据前面的情况决定的,
//受到前一个最近的 保留的 字符 lastNum 以及他的值val决定的

#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;
class Solution
{
public:
	int addVal(string& str)
	{
		if (str.size() == 0)
			return 0;
		return process(str,0,'0', 0);
	}
	//index [0,5000] lastch 2种0 1  val: max=5000
	//5000 *2 *5000 = 5*10^7 <10^8 必过 
	int process(string& str, int index, char lastCh, int val)
	{
		if (index == str.size())
			return 0;
		int curVal = str[index] == lastCh ? (val + 1) : 1;
		//1. 保留index位置
		int next1 = process(str,index+1,str[index],curVal);
		//2. 舍弃index位置
		int next2 = process(str, index + 1, lastCh, val);
		return max(curVal+next1, next2);
	}
};