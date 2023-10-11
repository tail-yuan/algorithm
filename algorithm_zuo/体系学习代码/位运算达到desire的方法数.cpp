//����һ��ֻ�� 0(��)��1(��)��&(�߼���)��|(�߼���)��^(���)�����ַ����
//���ַ���express���ٸ���һ������ֵ desired������express���ж�������Ϸ�ʽ�����Դﵽdesired�Ľ����
//��������
//express = "1^0|0|1"��desired = false
//ֻ�� 1 ^ ((0 | 0) | 1)�� 1 ^ (0 | (0 | 1))����Ͽ��Եõ� false������ 2��
//express = "1"��desired = false
//���������Եõ�false������0

// ÿһ���������뷨�϶�����һ��().��Ϊÿһ�����Ŷ������һ������ķ���,���������໮��Ϊ������,Ȼ���ٵݹ����
// ������ѡ�е���& ����desired=true,��ô��Ҫ�������඼ΪTRUE,�ݹ�������������
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
	//����Լ��:0 2 4 6 8 λ��һ���ǲ����������ǲ�����,1 3 5 7���ǲ�����.���ҵ���ż��.
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
	//����ֵ����������ʹ��desired�ķ�����,���count*�Ҳ�count
	int p(string& str, int l, int r, bool desired)// l rѡ�еĿ϶����ǲ�����,l+1���ǲ�����
	{
		if (l == r)//ֻ��һ���ַ�0 / 1
		{
			if (str[l] == '0') return desired ? 0 : 1;
			else if (str[l] == '1') return desired ? 1 : 0;
		}
		int res = 0;
		if (desired)
		{
			for (int i = l + 1; i < r; i += 2)//ö��ÿһ�����������������һ�������
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
			for (int i = l + 1; i < r; i += 2)//ö��ÿһ�����������������һ�������
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