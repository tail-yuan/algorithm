#include<iostream>
#include<vector>
#include<string>
using namespace std;

//ֻ��red���s�ַ���,�涨����Ϊn,���м����ɰ��ַ���
//�ɰ��ַ�������ָ��t�������е���s�в����а���t���Ӵ�
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
        //��ʼ��: �մ������������Ӵ���������
        for (int j = 0; j <= m; j++)
            dp[0][j] = 1;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (s[i - 1] == t[i - 1])//�����һ���ַ���ͬʱ,����ѡ�������Բ�ѡ����
                    dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }
        return dp[n][m];
    }
    int countSubstr(string& s)
    {
        int count = 0; // ���ڼ���ƥ����Ӵ�����
        // ��ѭ������s�е����п����Ӵ�
        for (int i = 0; i < s.length(); i++) 
        {
            // ��ѭ��������s[i]��ͷ�����п����Ӵ�
            for (int j = i; j < s.length(); j++) 
            {
                string substr = s.substr(i, j - i + 1); // ��ȡ�Ӵ�
                if (substr == t) {
                    // ����Ӵ���t��ͬ�����Ӽ�����
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