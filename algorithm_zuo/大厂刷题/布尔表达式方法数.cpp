//https://leetcode.cn/problems/boolean-evaluation-lcci/
//����һ���������ʽ��һ�������Ĳ������ result���������ʽ�� 0 (false)��1 (true)��& (AND)�� | (OR) �� ^ (XOR) ������ɡ�
//ʵ��һ������������м��ֿ�ʹ�ñ��ʽ�ó� result ֵ�����ŷ�����
//ż���±�һ����0����1,�����±�һ���������
//�������������ŵķ�ʽ�ı��������ȼ�,��������ʽ����True ����false�ķ�����.
//https://www.bilibili.com/video/BV1NV4y1B7ZZ?p=21&vd_source=cc945ef88574fe2db5e814c0c265a4c7
//���:
//��iλ�ò�����Ϊ����������Ĳ�����,��ʱ������Ϊ��������.
//if [i]==&,����õ��������ΪTrue�ķ�����a,�Ҳ�ΪTrue�ķ�����b,���巵��a*b��
//if [i]==|,���ΪTrue,a��,�Ҳ�ΪTrueb��,���Ϊ��c��,�Ҳ�Ϊ��d��.
//	���巵��a*d+b*c+d*c
//���Ը���func������Χ,func�������ط�Χ��ΪTrue����false�ķ�����
//lrλ�ñ�����0����1
//��Ϊ�ڻ��������ʱ������ظ�����,���Կ��Ը�Ϊ���仯����.
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

	//��֤���ݵ�lrλ�ö���01,�����������
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
		//������������1��������,2������
		//ö��ÿһ��������Ϊ���һ������ʱ�Ĳ�����
		//����split�仯һ����+2,��ΪҪ������һ���ַ�λ��
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