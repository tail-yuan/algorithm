#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;

//ʹ�õ���ջ,ά��ջ�дӵ׵����ǴӴ�С�����
//����ʱ, while(cur>st.top()) st.pop,Ȼ�����,
//�����������ʱ,st.size()>=K,��ô��ȡջ�׵�K��Ԫ�ؾ������ֵ
//��������������ֲ���K��,˵����Ҫ���̫����,�͵��ڱ����Ĺ����мӸ����۽��ͱ�׼
//������֤�ù�K��Ԫ�����������,���㷢��st.size()+cur֮���Ԫ�����ôճ�K��ʱ
//�ͱ�ջ��,ֱ�ӷ�����Щ��������,���ٵ�ջ����Ԫ�ؾͲ�����
//����cur��ʱ���ֵ�����,ֱ�ӽ��Ͼ�����
//����̰�ķ�ʽ: ��������������ȷ��
// 
//���Ա�����������K����������,Ȼ��ȶԴ�С�õ����������
class Solution
{
public:
	string maxString(string& s, int k)
	{
		if (k <= 0 || s.size() < k)
			return "";
		int n = s.size();
		string st = "";
		int size = 0;//��sizeλ�����Ԫ��,size-1��ջ��
		for (int i = 0; i < s.size(); i++)
		{
			//����һ��,���ֺ����Ļ���,�Ϳ��Ե���.��������ͱ𵯶���
			//��������һ��,�ٵ�.������sizeλ�ò�������ձ���
			while (size > 0 && st[size-1] < s[i] && size + n - i > k)
				--size;
			if (size+ n - i == k)
				return st+ s.substr(i);
			st[size++] = s[i];
		}
		return st;
	}
};