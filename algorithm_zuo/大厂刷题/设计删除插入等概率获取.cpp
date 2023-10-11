
//�������Ź�ϣ��,<string,index> hash1,<index,string>hash2
// �ȸ��ʻ�ȡ�ķ�ʽ,��һ�������Ŀռ���,rand()%sz����[0,sz-1]�������,�����ȸ���
//��ɾ��һ��Ԫ��ʱ������������������һ����,�����������һ��Ԫ�ز����Ǹ�������,Ȼ��sz--,��Ȼ�õ�һ��
//�����Ķ�
//https://leetcode.cn/problems/insert-delete-getrandom-o1/submissions/
#include<iostream>
#include<unordered_map>
using namespace std;
class RandomizedSet 
{
    unordered_map<int, int> hash1;//<key,index>
    unordered_map<int, int> hash2;//<index,key>
    int sz = 0;
public:
    RandomizedSet() 
    {}

    bool insert(int val) 
    {
        if (hash1.find(val) == hash1.end())//û�ҵ�
        {
            hash1.insert({val,sz});
            hash2.insert({ sz,val });
            sz++;
            return true;
        }
        return false;//�Ѿ����˾ͷ���false
    }

    bool remove(int val) 
    {
        if (hash1.find(val) != hash1.end())//�ҵ��˿���ɾ��
        {
            int delIndex = hash1[val];
            int lastIndex = --sz;
            int lastKey = hash2[lastIndex];
            hash1[lastKey] = delIndex;
            hash2[delIndex] = lastKey;
            hash1.erase(val);
            hash2.erase(lastIndex);
            return true;
        }
        return false;//û�ҵ�,����false
    }

    int getRandom() 
    {
        if (sz == 0)
            return -1;
        int randi = rand() % sz;
        return hash2[randi];
    }
};