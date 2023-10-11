#include<iostream>
#include<vector>
using namespace std;
//https://leetcode.cn/problems/longest-palindromic-substring/description/
//中间向两边判断,直到不满足时更新res长度
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
            extendFromCenter(s,i,i);//ABA型
            extendFromCenter(s, i, i + 1);//ABBA型
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
        //出来是因为越界left [left+1,right-1]right 想要的空间的长度是right-1 -(left+1)+1=right-left-1
        if (right - left - 1 > res.size())
            res = str.substr(left+1,right-left-1);
    }
};
//如果字符串回文,那么去掉左右两个字符之后依然回文=>动归 
// i==j,true;只有一个字符
// j-i<=2,s[i]==s[j]?true:false;有两个or三个字符
// s[i]==s[j]&&f(i+1,j-1)==true ? true:false
//所以i的更新需要右边的值,j的更新需要左边的值,进而确定循环方向i从右往左,j从左往右

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
class Solution1 {//暴力方法,两层循环外加上判断是否回文,O(N^3)
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