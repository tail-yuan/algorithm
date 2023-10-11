#include<iostream>
using namespace std;
//数据范围可以任意约束,所以这个套路很重要
// -183~182 判断是否可以转换 minq=-18 minr=-3
class Convert
{
public:
	//符合人们正常书写习惯的才是有效的
	//1. 不能单写一个 - ;- 后面第一个不能是0; 数字就是数字中间不能出现字母
	//2. 写数字打头的不能是0
	// 
	//使用负数接受,因为负数比正数多一个
	//-2147483648 2147483647
	// 
	bool isValid(string& str)
	{
		if (str[0] != '-' && (str[0] < '0' || str[0]>'9'))
			return false;
		if (str[0] == '-' && (str.size() == 1 || str[1] == '0'))
			return false;
		if (str[0] == '0' && str.size() > 1)
			return false;
		for (int i = 1; i < str.size(); i++)
		{
			if (str[i] < '0' || str[i]>'9')
				return false;
		}
		return true;
	}
	int convert(string& str)
	{
		if (str.size() == 0)
			return 0;
		if (!isValid(str))
			return 0;
		bool flag = str[0] == '-' ? true : false;
		
		//拼接过程中判断越界用的
		int minq = INT_MIN / 10;
		int minr = INT_MIN % 10;

		int res = 0;
		int cur = 0;
		for (int i = flag ? 1 : 0; i < str.size(); i++)
		{
			cur = '0' - str[i];
			//res再*10就会越界 || res*10正好等于,但是余数更小+上也会越界
			if (res < minq || (res == minq && cur < minr))
				return 0;
			res = res * 10 + cur;
		}
		if (flag && res == INT_MIN)//-2147483648无法转化为正数
			return 0;

		return flag ? res : -res;
	}
};