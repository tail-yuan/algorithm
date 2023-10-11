
//运用两张哈希表,<string,index> hash1,<index,string>hash2
// 等概率获取的方式,在一个连续的空间中,rand()%sz生成[0,sz-1]的随机数,做到等概率
//当删除一个元素时会在连续的区间中有一个洞,那我们用最后一个元素补充那个洞就行,然后sz--,仍然得到一个
//连续的洞
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
        if (hash1.find(val) == hash1.end())//没找到
        {
            hash1.insert({val,sz});
            hash2.insert({ sz,val });
            sz++;
            return true;
        }
        return false;//已经有了就返回false
    }

    bool remove(int val) 
    {
        if (hash1.find(val) != hash1.end())//找到了可以删除
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
        return false;//没找到,返回false
    }

    int getRandom() 
    {
        if (sz == 0)
            return -1;
        int randi = rand() % sz;
        return hash2[randi];
    }
};