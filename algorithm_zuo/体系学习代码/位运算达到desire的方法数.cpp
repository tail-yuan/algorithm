//给定一个只由 0(假)、1(真)、&(逻辑与)、|(逻辑或)和^(异或)五种字符组成
//的字符串express，再给定一个布尔值 desired。返回express能有多少种组合方式，可以达到desired的结果。
//【举例】
//express = "1^0|0|1"，desired = false
//只有 1 ^ ((0 | 0) | 1)和 1 ^ (0 | (0 | 1))的组合可以得到 false，返回 2。
//express = "1"，desired = false
//无组合则可以得到false，返回0

// 每一次运算在想法上都加上一层().认为每一个符号都是最后一次运算的符号,将左右两侧划分为两部分,然后再递归进行
// 如果这次选中的是& 并且desired=true,那么需要左右两侧都为TRUE,递归调用左和右区间
#include<iostream>
using namespace std;

class ExpressionNumber
{
public:
	int num1(string& str,bool desired)
	{
		if (str.size() == 0) return 0;
		if (!isValid(str))
			return 0;
		return p(str,0,str.size()-1, desired);
	}
	//正常约束:0 2 4 6 8 位置一定是操作数而不是操作符,1 3 5 7才是操作符.并且得是偶数.
	//1 & 1 | 2
	bool isValid(string& str)
	{
		if ((str.size() & 1) == 0)
			return false;
		for (int i = 0; i < str.size(); i += 2)
			if (str[i] != '1' || str[i] != '0')
				return false;
		for (int i = 1; i < str.size(); i += 2)
			if (str[i] != '&' || str[i] != '|' || str[i] != '^')
				return false;
		return true;
	}
	//返回值是左右两侧使得desired的方法数,左侧count*右侧count
	int p(string& str, int l, int r, bool desired)// l r选中的肯定都是操作数,l+1就是操作符
	{
		if (l == r)//只有一个字符0 / 1
		{
			if (str[l] == '0') return desired ? 0 : 1;
			else if (str[l] == '1') return desired ? 1 : 0;
		}
		int res = 0;
		if (desired)
		{
			for (int i = l + 1; i < r; i += 2)//枚举每一个操作符看做是最后一次运算的
			{
				switch (str[i])
				{
				case '&':
					res += p(str,l,i-1,true) * p(str,i+1,r,true);
					break;
				case '|':
					res += p(str, l, i - 1, true) * p(str,i+1,r,false);
					res += p(str, l, i - 1, false) * p(str, i + 1, r, true);
					res += p(str, l, i - 1, true) * p(str, i + 1, r, true);
					break;
				case '^':
					res += p(str,l,i-1,false) * p(str,i+1,r,true);
					res += p(str,l,i-1,true) * p(str,i+1,r,false);
					break;
				default:
					break;
				}
			}
		}
		else//desired=false
		{
			for (int i = l + 1; i < r; i += 2)//枚举每一个操作符看做是最后一次运算的
			{
				switch (str[i])
				{
				case '&':
					res += p(str, l, i - 1, false) * p(str, i + 1, r, true);
					res += p(str, l, i - 1, true) * p(str, i + 1, r, false);
					res += p(str, l, i - 1, false) * p(str, i + 1, r, false);
					break;
				case '|':
					res += p(str, l, i - 1, false) * p(str, i + 1, r, false);
					break;
				case '^':
					res += p(str, l, i - 1, false) * p(str, i + 1, r, false);
					res += p(str, l, i - 1, true) * p(str, i + 1, r, true);
					break;
				default:
					break;
				}
			}
		}
		return res;
	}
//public static int num2(String express, boolean desired) {
//	if (express == null || express.equals("")) {
//		return 0;
//	}
//	char[] exp = express.toCharArray();
//	if (!isValid(exp)) {
//		return 0;
//	}
//	int[][] t = new int[exp.length][exp.length];
//	int[][] f = new int[exp.length][exp.length];
//	t[0][0] = exp[0] == '0' ? 0 : 1;
//	f[0][0] = exp[0] == '1' ? 0 : 1;
//	for (int i = 2; i < exp.length; i += 2) {
//		t[i][i] = exp[i] == '0' ? 0 : 1;
//		f[i][i] = exp[i] == '1' ? 0 : 1;
//		for (int j = i - 2; j >= 0; j -= 2) {
//			for (int k = j; k < i; k += 2) {
//				if (exp[k + 1] == '&') {
//					t[j][i] += t[j][k] * t[k + 2][i];
//					f[j][i] += (f[j][k] + t[j][k]) * f[k + 2][i] + f[j][k] * t[k + 2][i];
//				}
//				else if (exp[k + 1] == '|') {
//					t[j][i] += (f[j][k] + t[j][k]) * t[k + 2][i] + t[j][k] * f[k + 2][i];
//					f[j][i] += f[j][k] * f[k + 2][i];
//				}
//				else {
//					t[j][i] += f[j][k] * t[k + 2][i] + t[j][k] * f[k + 2][i];
//					f[j][i] += f[j][k] * f[k + 2][i] + t[j][k] * t[k + 2][i];
//				}
//			}
//		}
//	}
//	return desired ? t[0][t.length - 1] : f[0][f.length - 1];
//}
};