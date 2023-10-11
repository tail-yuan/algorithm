#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
//https://leetcode.cn/problems/zi-fu-chuan-de-pai-lie-lcof/submissions/
// �ݹ�+�����ַ���ӡ,ʵ�ֿռ临�Ӷ�O(1)
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
        //ÿ���Լ���ͼ��һ�¾ͺ���,��סҲ��
        for (int i = l; i <= r; i++) 
        {
            std::swap(str[l], str[i]);
            permute(str, l + 1, r);
            std::swap(str[l], str[i]); // �ָ�ԭʼ˳��
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
// ��һ���ݹ�,visited[]��ʾĳһ����֧���Ǹ��ַ��ù�,Ҫ����abc ����aaa bbb ����
// Ϊ��ʵ��ȥ��,ʹ��unordered_set
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
        for (int i = 0; i < n; i++)//��������һ����������n��
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