#include<iostream>
#include<vector>
using namespace std;
//https://leetcode.cn/problems/longest-palindromic-substring/description/
//�м��������ж�,ֱ��������ʱ����res����
// <O(n^2),O(1)>
class Solution3
{
public:
    string res;
    string longestPalindrome(string s)
    {
        res = s.substr(0,1);
        for (int i = 0; i < s.size(); i++)
        {
            extendFromCenter(s,i,i);//ABA��
            extendFromCenter(s, i, i + 1);//ABBA��
        }
        return res;
    }
    void extendFromCenter(string& str,int left,int right)
    {
        while (left >= 0 && right < str.size() && str[left] == str[right])
        {
            left--;
            right++;
        }
        //��������ΪԽ��left [left+1,right-1]right ��Ҫ�Ŀռ�ĳ�����right-1 -(left+1)+1=right-left-1
        if (right - left - 1 > res.size())
            res = str.substr(left+1,right-left-1);
    }
};
//����ַ�������,��ôȥ�����������ַ�֮����Ȼ����=>���� 
// i==j,true;ֻ��һ���ַ�
// j-i<=2,s[i]==s[j]?true:false;������or�����ַ�
// s[i]==s[j]&&f(i+1,j-1)==true ? true:false
//����i�ĸ�����Ҫ�ұߵ�ֵ,j�ĸ�����Ҫ��ߵ�ֵ,����ȷ��ѭ������i��������,j��������

class Solution2 //<O(n^2),O(n^2)>
{
public:
    string longestPalindrome(string s)
    {
        string res = s.substr(0,1);
        int n = s.size();
        vector<vector<bool>>dp(n,vector<bool>(n,false));
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (i == j) dp[i][j] = true;
                else if (j - i <= 2) dp[i][j] = s[i] == s[j] ? true : false;
                else
                    dp[i][j] = s[i] == s[j] && dp[i + 1][j - 1];
                if (dp[i][j] && j - i + 1 > res.size())
                    res = s.substr(i,j - i + 1);
            }
        }
        return res;
    }
};
class Solution1 {//��������,����ѭ��������ж��Ƿ����,O(N^3)
public:
    string longestPalindrome(string s)
    {
        string res = s.substr(0, 1);// <pos len>
        for (int i = 0; i < s.size(); i++)
        {
            for (int j = i + 1; j < s.size(); j++)
            {
                if (j - i + 1 > res.size() && isPalindrome(s, i, j))
                {
                    res = s.substr(i, j - i + 1);
                }
            }
        }
        return res;
    }
    bool isPalindrome(string& str, int left, int right)
    {
        while (left <= right)
        {
            if (str[left] != str[right])
                return false;
            left++;
            right--;
        }
        return true;
    }
};