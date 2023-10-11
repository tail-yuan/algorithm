//https://leetcode.cn/problems/avoid-flood-in-the-city/
// https://www.bilibili.com/video/BV1NV4y1B7ZZ?p=78&spm_id_from=pageDriver&vd_source=cc945ef88574fe2db5e814c0c265a4c7
//给定数组,rains[i]>0,代表第i天时会下雨,rains[i]==0,代表第i天并不下雨,人可以工作,可以选择将某一个坑把水都抽干净
//那么请返回一个ans数组,ans[i]代表人可以在第i天将ans[i]号坑水抽干
//ans[i]=-1,代表这天什么都不做,因为下雨了,人没有办法工作
//如果没有办法阻止洪水的发生,就返回一个空数组ans
    // 规定，下雨日，干啥 : -1
    // 不下雨日，如果没有湖泊可抽 : 1

//将已经下雨的坑放到一张表当中,如果我这天可以操作,我肯定先抽这些坑中后面的,离我最近并且下雨的坑,来避免洪水.
//怎么知道后面的,哪个离我最近的要下雨的坑? 遍历后面区间肯定可行,但是不够好
// 首先使用一张表记录每个坑位下雨的时间表unordered_map<int,vector<int>>,涉及到头删尾插,可以使用list
//set<>表用于记录没抽干的坑的编号
//使用小跟堆记录已经下雨的坑以及他下一次下雨的时间,以下一次下雨的时间作为map的key值建立这个堆

#include<iostream>
#include<vector>
#include<list>
#include<unordered_map>
#include<unordered_set>
#include<queue>
using namespace std;

class Solution
{
public:
    class Node
    {
    public:
        int lake;
        int nextRain;
        Node(int l, int n)
            :lake(l)
            , nextRain(n)
        {}
    };
    struct Greater
    {
        bool operator()(const Node& n1, const Node& n2)
        {
            return n1.nextRain > n2.nextRain;//建立小堆
        }
    };
    vector<int> avoidFlood(vector<int>& nums)
    {
        int n = nums.size();
        vector<int>ans(n);
        unordered_map<int, list<int>>hashMap;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] != 0)
            {
                if (!hashMap.count(nums[i]))
                    hashMap.insert({ nums[i],list<int>() });
                hashMap[nums[i]].push_back(i);
            }
        }
        unordered_set<int>hashSet;//记录没抽干的坑位
        priority_queue<Node, vector<Node>, Greater>pq;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] != 0)
            {
                if (hashSet.count(nums[i]) != 0)
                    return {};
                hashSet.insert(nums[i]);
                hashMap[nums[i]].pop_front();
                if (!hashMap[nums[i]].empty())
                    pq.push(Node(nums[i],hashMap[nums[i]].front()));
                ans[i] = -1;
            }
            else//今天不下雨得干活
            {
                if (pq.empty())
                    ans[i] = 1;//题目规定
                else
                {
                    Node cur = pq.top();
                    pq.pop();
                    hashSet.erase(cur.lake);
                    ans[i] = cur.lake;
                }
            }
        }
        return ans;
    }
};