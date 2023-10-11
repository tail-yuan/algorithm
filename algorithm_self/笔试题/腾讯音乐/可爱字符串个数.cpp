#include<iostream>
#include<vector>
#include<string>
using namespace std;

//只用red组成s字符串,规定长度为n,问有几个可爱字符串
//可爱字符串就是指是t的子序列但是s中不能有包含t的子串
class Solution
{
    int n;
    vector<string>strs;
    string t = "red";
public:
    int kawaiiStrings(int _n)
    {
        n = _n;
        string tmp = "r";
        dfs(tmp);
        const int N = 1e9 + 7;
        int count = 0;
        for (auto& s : strs)
        {
            if (isSubseq(s) && !isSubstr(s))
                count++;
        }
        return count;
    }
    void dfs(string path)
    {
        if (path.size() == n)
        {
            strs.push_back(path);
            return;
        }
        for (int i = 0; i < t.size(); i++)
        {
            dfs(path + t[i]);
        }
    }
    bool isSubstr(string& s)
    {
        return s.find(t) == string::npos ? false : true;
    }
    bool isSubseq(string& s)
    {
        int si = 0, ti = 0;
        while (si < s.size() && ti < t.size())
        {
            if (s[si] == t[ti])
                ti++;
            si++;
        }
        return ti == t.size() ? true : false;
    }
public:
    int countSubseq(string& s)
    {
        int m = t.size();
        vector<vector<int>>dp(n + 1, vector<int>(m + 1));
        //初始化: 空串可以是任意子串的子序列
        for (int j = 0; j <= m; j++)
            dp[0][j] = 1;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (s[i - 1] == t[i - 1])//当最后一个字符相同时,可以选择它可以不选择它
                    dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }
        return dp[n][m];
    }
    int countSubstr(string& s)
    {
        int count = 0; // 用于计数匹配的子串数量
        // 外循环遍历s中的所有可能子串
        for (int i = 0; i < s.length(); i++) 
        {
            // 内循环遍历以s[i]开头的所有可能子串
            for (int j = i; j < s.length(); j++) 
            {
                string substr = s.substr(i, j - i + 1); // 提取子串
                if (substr == t) {
                    // 如果子串与t相同，增加计数器
                    count++;
                }
            }
        }
        return count;
    }
};
int main()
{
    Solution s;
    cout << s.kawaiiStrings(4) << endl;
    return 0;
}