#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//��Ч���Ŵ���ɾ�����ٵ����ŵõ���Ч���Ŵ�,������������ֵ��ͬ����Ч�����ַ���
//����: ()((())) ) ��һ��),
//1. ����ɾ���ڶ����ַ�),-> ( ((())) )
//2. ����ɾ�������ĸ�)������һ��,���õ�����ֵ��ͬ��->()((()))
//�ⷨһ: ����֦�ռ����н��֮���ٹ���
//�ⷨ��: ��֦,���������ֱ�ӿ���,Ч�ʸ���.
// 
//����: �ж������ַ�����Ч,[i]=(,count++,[i]=),count--;
// ��ֻרע��ɾ��)ʱ,�������Ҵ���: 
//		if count<0,return false; if count>=0,˵��ÿ��)����(����ƥ��
//������count<0ʱ,˵��)����,����Ҫɾ��֮ǰ������һ��),��ʵ����ѡ������һ��(�ı�ƥ�����
//����ƥ���µ�). ɾ��)ʱ,�����������),ֻ��Ҫɾ��һ��)����,��Ϊ�õ��Ľ����һ����.
//ֻ���м����(��),ɾ�����в�ͬ�Ľ������.��Ϊѡ�е����µ�(�͸ճ��ֵ�)ƥ��.
// 
//������Ҫ��������i,j ����f(i,j)����
//i�����������,count.j �Ǳ�ʾ����ɾ����λ��.f(i,j)
//�ڵ�[i]ʱ����count<0,˵����[0,i]֮���jλ�ø�ɾ��)��,
//ɾ��һ��֮��,������ַ�����ǰ�����Ǹ���ɾ��λ��,�±����·ֲ�����ijλ����֮ǰû���ʵ�λ��
//�ٵ���f(i,j),��iλ��������,j����һ������ɾ����λ��
// 
//	����ʵ��:
//�����һ�����Ϸ�λ��[i]ʱ,ɾ��֮��,fֱ��return ��,Ҳ����˵������ôɾ��ͨ�������Ӻ����ķ�ʽ��¼��.
//  
//  ����ôɾ��? j��deleteIndex��ʼ,С�ڵ���iλ��.
//ɾ��һ��jλ��֮��,�����ַ�����ǰ����,�����Ӻ���f(i,j),������һ��ݹ�,
//�ٽ��в���,������һ���µ�iʹ��count<0
//���ڴ�j��ʼ������,Ѱ��ɾ��һ��),�����ַ�����ǰ����...
// ֱ���ٵ����Ӻ���ʱ,����iλ�ô���Խ��λ��(��Ϊ�ַ���һֱ��ǰ����)
//��ʱ�ҵ�һ���Ϸ��ַ���.Ȼ�����Ϸ���,����һ���j+1λ�ó���ɾ��,Ȼ���ٵ����Ӻ���,��������.

//ע��: ������һ��jɾ��֮��,���Դ�j+1λ��ɾ��ʱ,���ܲ���j+1λ��,��ΪΪ��ȥ��,
// �����ѡ��Ĳ���,Ҳ���ǲ���������)ɾ��.
//�����ռ�����һ���ǲ�һ������Ч�����ַ���.
//���񽲽���Ƶ:ͼ������
//https://www.bilibili.com/video/BV1NV4y1B7ZZ?p=17&spm_id_from=pageDriver&vd_source=cc945ef88574fe2db5e814c0c265a4c7
//https://leetcode.cn/problems/remove-invalid-parentheses/submissions/?utm_source=LCUS&utm_medium=ip_redirect&utm_campaign=transfer2china
class Solution
{
	vector<string>ans;
public:
	vector<string> removeInvalidParentheses(string& str)
	{
		remove(str, 0, 0, {'(',')'});
	}
	void remove(string& s, int checki, int deletei,pair<char,char>par)
	{
		int count = 0;
		for (int i = checki; i < s.size(); i++)
		{
			if (s[i] == par.second)
				count--;
			else if (s[i] == par.first)
				count++;
			if (count < 0)
			{
				for (int j = deletei; j <= i; j++)
				{
					if (s[j] == par.second && (j == deletei || s[j - 1] != par.second))
					{
						string newStr = s.substr(0, j) + s.substr(j + 1);
						remove(newStr,i,j,par);
					}
				}
				return;
			}
		}
		//ѭ������,��ʱ���е������Ŷ����������Ŷ�,��ô����һ��,ȥѰ��ɾ��(
		reverse(s.begin(),s.end());
		if (par.first == '(')
			remove(s, 0, 0, { ')','(' });
		else//��ֹһֱת����
			ans.push_back(s);
	}
};