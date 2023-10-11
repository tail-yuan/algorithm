#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
//https://leetcode.cn/problems/zi-fu-chuan-de-pai-lie-lcof/submissions/
// 递归+交换字符打印,实现空间复杂度O(1)
class Solution1 {
public:
    unordered_set<string> hashSet;
public:
    void permute(string& str, int l, int r)
    {
        if (l == r)
        {
            hashSet.insert(str);
            return;
        }
        //每次自己画图推一下就好了,记住也行
        for (int i = l; i <= r; i++) 
        {
            std::swap(str[l], str[i]);
            permute(str, l + 1, r);
            std::swap(str[l], str[i]); // 恢复原始顺序
        }
    }
    vector<string> permutation(string s)
    {
        int n = s.size();
        permute(s, 0, n - 1);
        vector<string>ans;
        for (auto e : hashSet) ans.push_back(e);
        return ans;
    }
};
// 走一个递归,visited[]表示某一个分支中那个字符用过,要求是abc 别有aaa bbb 这种
// 为了实现去重,使用unordered_set
//  <O(),O(N)>
class Solution2 
{
public:
    void permute(string & s,vector<string>& ans, string& tmp, int index, int n,vector<bool>&visited)
    {
        if (index == n)
        {
            ans.push_back(tmp);
            return;
        }
        for (int i = 0; i < n; i++)//形象点就是一条链往下走n层
        {
            if (visited[i] == 1)
                continue;
            tmp += s[i];
            visited[i] = 1;
            permute(s,ans,tmp,index+1,n,visited);
            visited[i] = 0;
            tmp.pop_back();
        }
    }
    vector<string> permutation(string s) 
    {
        int n = s.size();
        vector<string> ans;
        vector<bool> visited(n,false);
        string ret = "";
        permute(s,ans,ret,0,n,visited);
        unordered_set<string>hash_set;
        for (auto& e : ans) hash_set.insert(e);
        vector<string>str;
        for (auto& e : hash_set)str.push_back(e);
        return str;
    }
};