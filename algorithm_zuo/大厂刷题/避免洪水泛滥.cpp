//https://leetcode.cn/problems/avoid-flood-in-the-city/
// https://www.bilibili.com/video/BV1NV4y1B7ZZ?p=78&spm_id_from=pageDriver&vd_source=cc945ef88574fe2db5e814c0c265a4c7
//��������,rains[i]>0,�����i��ʱ������,rains[i]==0,�����i�첢������,�˿��Թ���,����ѡ��ĳһ���Ӱ�ˮ����ɾ�
//��ô�뷵��һ��ans����,ans[i]�����˿����ڵ�i�콫ans[i]�ſ�ˮ���
//ans[i]=-1,��������ʲô������,��Ϊ������,��û�а취����
//���û�а취��ֹ��ˮ�ķ���,�ͷ���һ��������ans
    // �涨�������գ���ɶ : -1
    // �������գ����û�к����ɳ� : 1

//���Ѿ�����Ŀӷŵ�һ�ű���,�����������Բ���,�ҿ϶��ȳ���Щ���к����,���������������Ŀ�,�������ˮ.
//��ô֪�������,�ĸ����������Ҫ����Ŀ�? ������������϶�����,���ǲ�����
// ����ʹ��һ�ű��¼ÿ����λ�����ʱ���unordered_map<int,vector<int>>,�漰��ͷɾβ��,����ʹ��list
//set<>�����ڼ�¼û��ɵĿӵı��
//ʹ��С���Ѽ�¼�Ѿ�����Ŀ��Լ�����һ�������ʱ��,����һ�������ʱ����Ϊmap��keyֵ���������

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
            return n1.nextRain > n2.nextRain;//����С��
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
        unordered_set<int>hashSet;//��¼û��ɵĿ�λ
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
            else//���첻����øɻ�
            {
                if (pq.empty())
                    ans[i] = 1;//��Ŀ�涨
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