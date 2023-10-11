//https://leetcode.com/problems/remove-duplicate-letters/
//���: ����һ���ַ��� s��ɾ���ظ�����ĸ��ʹÿ����ĸ�����ҽ�����һ�Ρ� 
//������ȷ�����Ľ���ǰ��ֵ�˳����С�������п��ܵĽ���С�
//̰��: 
//1. ���ȶ�s�������ַ����д�Ƶͳ��,map����
//2. ����s�ַ���,û����һ���ַ�ch�ͽ���Ӧt�еĴ�Ƶ--,
//��map��ĳһ�ַ�ch�Ĵ�Ƶ--֮��Ϊ0,�˳�ѭ��.˵�������λ��index֮��,������Ҳû��ch����ַ���
//��[0,index]��ѡ���ֵ�����С���ַ�minVal��Ϊans����ʼ�ַ�,�����±���minIndex,
//��[minIndex]֮�����е�minVal��ɾ��,�õ��µ��ַ���,��ִ����������,�ܶ���ʼ�õ���С���ֵ�����Ӵ�.
//ʱ�临�Ӷ�: ÿ����һ�κ�����O(N)����Ϊ��ȷ��һ���ַ�,����һ��k����ͬ���ַ�,���ǵ���K�μ���
//O(k*n)=>o(N)
#include<iostream>
#include<string>
using namespace std;
class Solution
{
public:
    string removeDuplicateLetters(string& s)
    {
        if (s.size() < 2)
            return s;
        int hash[256] = { 0 };
        for (int i = 0; i < s.size(); i++)
            hash[s[i]]++;
        //1. �ҵ�iλ��������һ���ַ���֮��������в��ٴ���
        //2. ��¼��ʱ��С�ֵ�����ַ�λ��
        int minIndex = 0;
        for (int i = 0; i < s.size(); i++)
        {
            minIndex = s[minIndex] > s[i] ? i : minIndex;
            --hash[s[i]];
            if (hash[s[i]] == 0)
                break;
        }
        char x = s[minIndex];
        string tmp;
        string res;
        for (int i = minIndex+1; i<s.size(); i++)
        {
            if (s[i] != x)
                tmp += s[i];
        }
        return (res += x) + removeDuplicateLetters(tmp);
    }
};
int main()
{
    Solution s;
    string ret = "bcabc";
    cout << s.removeDuplicateLetters(ret) << endl;
    char x = 'a';
    cout << to_string(x) << endl;
    return 0;
}