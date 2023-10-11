//把一个数字用中文表示出来。数字范围为 [0, 99999]。
//为了方便输出，使用字母替换相应的中文，万W 千Q 百B 十S 零L。使用数字取代中
//文数字注：对于 11 应该表示为 一十一(1S1)，而不是十一(S1)
//输入描述：
//数字 0（包含）到 99999（包含）。
//输出描述：
//用字母替换相应的中文，万W 千Q 百B 十S 零L
//示例1 :
//输入
//12001
//输出
//1W2QL1

#include<iostream>
#include<vector>
using namespace std;
class ChineseEspression
{
public:
	string num1to9(int num)
	{
		if (num < 1 || num>9)
			return "";
		 vector<string> arr = {"一","二","三","四","五","六","七","八","九"};
		 return arr[num - 1];
	}
	string num1to99(int num,bool isHasBai)// 0 12->十二 1 12->一百 一十二
	{
		if (num < 1 || num>99)
			return "";
		if (num < 10)
			return num1to9(num);
		int shi = num / 10;
		if (shi == 1 && !isHasBai)
			return "十" + num1to9(num % 10);
		else
			return num1to9(shi) + "十" + num1to9(num%10);
	}
	string num1to999(int num)
	{
		if(num < 1 || num>999)
			return "";
		if (num < 100) return num1to99(num,false);
		
		string res = num1to9(num / 100) + "百";
		int rest = num % 100;
		if (rest == 0)
			return res;
		else if (rest >= 10)
			res += num1to99(rest, true);
		else
			res + "零" + num1to9(rest);
		return res;
	}
	string num1to9999(int num)
	{
		if (num < 1 || num>9999)
			return "";
		if (num < 1000) return num1to999(num);
		string res = num1to9(num / 1000) + "千";
		int rest = num % 1000;
		if (rest == 0)
			return res;
		else if (rest > 100)
			res += num1to999(rest);
		else
			res += "零" + num1to99(rest,false);
		return res;
	}
	//中文是四个四个一组,所以要拼四个不同的说法,之后就四个四个网上加
	string num1to99999999(int num)
	{
		if (num < 1 || num>99999999)
			return "";
		int wan = num / 10000;
		int rest = num % 10000;
		if (wan == 0)
			return num1to9999(num);
		else
		{
			string res = num1to9(wan) + "万";
			if (rest < 1000)
				return res + "零" + num1to999(rest);
			else
				return res + num1to9999(rest);
		}
	}
	string getNumChiExp(int num)
	{
		if (num == 0) return "零";
		string res = num < 0 ? "负" : "";
		int yi = abs(num /100000000);
		int rest = abs(num %100000000);
		if (yi == 0)
			return res+num1to99999999(num);
		else
		{
			res += num1to9999(yi) + "亿";
			if (rest == 0)
				return res;
			else
			{
				if (rest < 10000000)
					return res + "零" + num1to99999999(rest);
				else
					return res+ num1to99999999(rest);
			}
		}
	}
};