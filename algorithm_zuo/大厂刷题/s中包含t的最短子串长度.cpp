//����: �ҵ���̰����Ӵ��ĳ���
//s �а���t�������ַ�������Ӵ�����,t���ַ���s�г��ֵ�˳������������.
//������: s���Ӵ�����Խ��,������t���ַ���Խ��
//ʹ�û�������: Ƿծ����ģ��
//��r==s.zie()ʱֹͣ,��������iλ��Ϊ��β��ģ��
//https://leetcode.com/problems/minimum-window-substring/submissions/
//��չ: �ҵ�����ַ���
#include<iostream>
using namespace std;
class Solution
{
public:
	string minWindow(string s, string t) 
	{
		if (s.size() < t.size())return "";
		int hash[256] = { 0 };
		for (char ch : t)
			hash[ch]++;
		int all = t.size();
		int l = 0, r = 0;
		int minLen = INT_MAX;
		int start = 0;
		while(r<s.size())
		{
			hash[s[r]]--;
			if (hash[s[r]] >= 0)
				all--;
			if (all == 0)//�����иû�����������ھͿ��Ի���ʱ,������С��߽�,������Ӵ�.
						//Ҳ����lλ���ַ������Ƕ໹�����,����������֮��hash[s[l]]<0
			{
				while (hash[s[l]] < 0)
					hash[s[l++]]++;
				if (minLen > r - l + 1)
				{
					minLen = r - l + 1;
					start = l;
				}
				//l++
				hash[s[l++]]++;
				all++;
			}
			r++;
		}
		return minLen==INT_MAX?"":s.substr(start, minLen);
	}
public:
	int minLength(string& s, string& t)
	{
		if (s.size() < t.size())return 0;
		//���Ƚ�t���ַ�ͳ��
		int countMap[256] = { 0 };
		for (int i = 0; i < t.size(); i++)
			countMap[t[i]]++;
		int all = t.size();
		int l = 0, r = 0;
		int minLen = INT_MAX;
		while (r != s.size())
		{
			countMap[s[r]]--;//����
			if (countMap[s[r]] > 0)
				all--;
			if (all == 0)//��������,�Ϳ�����С������
			{
				while (countMap[s[l]] < 0)//һֱ��Сl
					countMap[s[l++]]++;
				minLen = min(minLen, r - l + 1);//��С����̵�,�������Ӵ�
				//l++
				countMap[s[l]]++;
				all++;
			}
			r++;
		}
		return minLen == INT_MAX ? 0 : minLen;
	}
};