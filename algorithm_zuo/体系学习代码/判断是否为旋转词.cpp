#include<iostream>
#include<vector>
using namespace std;
//���:
//���һ���ַ���Ϊstr�����ַ���strǰ������Ĳ���Ų�������γɵ��ַ�����
//��str����ת�ʡ�����str = "12345"��str����ת����"12345"��"23451"��
//"34512"��"45123"��"51234"�����������ַ���a��b�����ж�a��b�Ƿ�Ϊ��ת�ʡ�
//���磺
//a = "cdab"��b = "abcd"������true��
//a = "1ab2"��b = "ab12"������false��
//a = "2ab1"��b = "ab12"������true��

// 1. �ж��ַ��������Ƿ���ͬ
// 2. �����ͬ,a=a+a,Ȼ���ж�b�Ƿ���a���Ӵ�(KMP�㷨),����Ǿ�����ת��
// ����n���������ַ�������Ϊ��ת��
class isRotation
{
public:
	bool isTrue(string& str1, string& str2)
	{
		if (str1.size() != str2.size())
			return false;
		string tmp = str1 + str1;
		return getIndexOf(tmp,str2)!=-1;
	}
	//��ȡiλ��֮ǰ,���(ǰ׺=��׺)ֵ,����next[i]�м�¼
	vector<int>getNextArr(string& str)
	{
		if (str.size() == 1)
			return {-1};
		vector<int>next(str.size());
		next[0] = -1;//0ǰ��û��ĸ.-1
		next[1] = 0;
		int i = 2;
		int cn = 0;
		//1. cnλ��,ǰ׺�ַ�������һ��λ�ú͵�i���ַ��Ƚ�
		//2. ��Ϊ�±��ֵ��һ�Ĺ�ϵ,cn��ֱ�ӱ�ʾ����
		while (i < next.size())
		{
			if (str[i - 1] == str[cn])
				next[i++] = ++cn;
			else if (cn > 0)//������ǰ��
				cn = next[cn];
			else
				next[i++] = 0;
		}
		return next;
	}
	//KMP ��ȡ��str1�е���ʼλ��
	int getIndexOf(string& str1, string& str2)
	{
		if (str1.size() == 0 || str2.size() > str1.size())
			return -1;
		int i1 = 0, i2 = 0;
		vector<int>next = getNextArr(str2);
		while (i1 < str1.size() && i2 < str2.size())
		{
			if (str1[i1] == str2[i2])
			{
				i1++;
				i2++;
			}
			else if (next[i2 == -1])
				i1++;
			else
				i2 = next[i2];
		}
		return i2 == str2.size() ? i1 - i2 : -1;//��-�̵õ���ʼ�±�
	}
};
