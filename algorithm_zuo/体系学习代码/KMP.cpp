#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;
//M < N ����T=O(N)
class KMP
{
public:
	//O(M)
	vector<int> getNextArr(string& str)
	{
		vector<int>next(str.size());
		next[0] = -1;
		next[1] = 0;
		if (str.size() == 1)
			return next;
		int i = 2;
		int cn = 0;
		//1. ������cnλ�õ�ֵ(ǰ׺����һ��λ��)�͵�i���ַ��Ƚ�
		//2. ǰ׺�ĳ����Ƕ���
		while (i < next.size())
		{
			if (str[i - 1] == str[cn])
				next[i++] = ++cn;//������i��λ��(�±�i-1)=cn+1,��һ��λ��i+1(�±�i)���ϻ�ʹ��iλ�õ�ֵ
			else if (cn > 0)//cn������ǰ��
				cn = next[cn];
			else//û����ǰ����
				next[i++] = 0;
		}
		return next;
	}
	int getIndexOf(string& str1, string& str2)
	{
		if (str1.size() == 0 || str2.size()>str1.size())
			return -1;
		int i1 = 0;
		int i2 = 0;
		vector<int> next = getNextArr(str2);//O(M)
		//O(N)
		while (i1 < str1.size() && i2 < str2.size())
		{
			if (str1[i1] == str2[i2])
			{
				i1++;
				i2++;
			}
			else if (next[i2] == -1)// i2==0,�޷�����ǰ��
				i1++;
			else//��������ȵ�λ����,����ǰ��
				i2 = next[i2];
		}
		//ֻҪ��i2����ѭ��˵����ƥ��ɹ���
		//ֻ��i1����,˵�����ɹ�
		return i2 == str2.size() ? i1 - i2 : -1;
	}
};