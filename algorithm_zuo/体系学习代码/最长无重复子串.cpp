//��һ���ַ������ҵ�û���ظ��ַ��Ӵ�����ĳ��ȡ�
//���磺
//abcabcbbû���ظ��ַ�����Ӵ���abc������Ϊ3
//bbbbb������b������Ϊ1
//pwwkew������wke��������3
//Ҫ�󣺴𰸱������Ӵ���"pwke" ��һ�����ַ����е�����һ�����ַ�����

//�����Ӵ�����,��Ķ�����iλ��Ϊ��β....
//��iλ��Ϊ��β,����ǰ�������Ӵ�����->dp[i]
//dp[i-1]��¼���Ǵ�i-1λ����ǰ����Զ���ظ��Ӵ�,Ҳ����˵��i-dp[i]λ�ó������ظ��ַ�
// 1. iλ���ַ���dp[i]���������в��ظ�,��ô��Զֻ�ܺ�dp[i-1]+1
// 2. iλ���ַ���dp[i]�������������ظ�,��ô�ҵ��ظ���λ��j,dp[i]= i-j
//��1: dp[i-1]=5 
// a b c d e  a  ?
//       j   i-1 i		1.��� ?=h,dp[i]=dp[i-1]+1  2. ���?=d,dp[i]=i-j
//��:��������,һ����i�ַ��ϴγ��ֵ�λ��,һ����i-1��һ�γ��ֵ�λ��,�Ǹ����Ǹ�������������
#include<iostream>
#include<vector>
using namespace std;
class LongestNoRepeatSubstring
{
public:
	int maxUnique(string& str)
	{
		if (str.size() == 0)
			return 0;
		vector<int>hashMap(256,-1);//��¼ĳһ���ַ��ϴγ��ֵ�λ��
		int ret = 0;
		int pre = -1;
		int cur = 0;
		for (int i = 0; i < str.size(); i++)
		{
			pre = max(pre, hashMap[i]);
			cur = i - pre;
			ret = max(ret, cur);
			hashMap[str[i]] = i;
		}
	/*	for (int i = 0; i < str.size(); i++)
		{
			pre = max(pre,hashMap[i]);
			int cur = i - pre;
			ret = max(ret, cur);
			hashMap[str[i]] = i;
		}*/
		return ret;
	}
};