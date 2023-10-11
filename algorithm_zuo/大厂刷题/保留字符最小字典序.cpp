//https://leetcode.com/problems/remove-duplicate-letters/
//题干: 给定一个字符串 s，删除重复的字母，使每个字母出现且仅出现一次。 
//您必须确保您的结果是按字典顺序最小的在所有可能的结果中。
//贪心: 
//1. 首先对s的所有字符进行词频统计,map表中
//2. 遍历s字符串,没遇到一个字符ch就将对应t中的词频--,
//当map中某一字符ch的词频--之后为0,退出循环.说明在这个位置index之后,后面再也没有ch这个字符了
//在[0,index]中选择字典序最小的字符minVal作为ans的起始字符,他的下标是minIndex,
//在[minIndex]之后将所有的minVal都删除,得到新的字符串,再执行上述操作,周而复始得到最小的字典序的子串.
//时间复杂度: 每调用一次函数走O(N)就是为了确定一个字符,假如一共k个不同的字符,就是调用K次即可
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
        //1. 找到i位置让其中一个字符在之后的区间中不再存在
        //2. 记录此时最小字典序的字符位置
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