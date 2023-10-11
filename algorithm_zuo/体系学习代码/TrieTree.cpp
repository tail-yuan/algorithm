#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
//前缀树能解决的问题
//1. 以某一个字符为前缀的字符串出现了几次
//2. 某一个字符出现的次数(hashMap也可以)
class TrieNode
{
public:
	int pass;//有多少个字符串到达过这个节点,也就是有多少个字符串有这个节点上的字符
	int end;//以某一个节点为结尾的字符串的个数
	unordered_map<char, TrieNode*> next;
	//next[0]==nullptr 没有到达'a'字符的路
	//next[1]!=nullptr   有到达'b'字符的路
public:
	TrieNode()
	{
		pass = 0;
		end = 0;
	}
};
class TrieTree
{
public:
	typedef TrieNode Node;
public:
	TrieTree()
	{
		root = new Node();
	}
	//Node 节点的next数组为空,代表不能到达就新建,否则沿途的pass++,直到字符串尾巴时end++
	void insert(string& word)
	{
		if (word.size() == 0)
			return;
		//int index = 0;
		Node* cur = root;
		cur->pass++;
		for (int i = 0; i < word.size(); i++)
		{
			char index = word[i];
			if (cur->next[index] == nullptr)
				cur->next[index] = new Node();
			cur = cur->next[index];
			cur->pass++;
		}
		cur->end++;
	}
	//word出现过几次
	int search(string& word)
	{
		if (word.size() == 0)
			return 0;
		Node* cur = root;
		for (int i = 0; i < word.size(); i++)
		{
			//abc插入过,你让我查abcde,在d时已经没路往下继续了,abcde就没出现过
			if (cur->next[word[i]] == nullptr)
				return 0;
			cur = cur->next[word[i]];
		}
		return cur->end;//end的作用
	}
	//有多少个字符串是以word作为前缀出现过的
	int prefixNumber(string& word)
	{
		if (word.size() == 0)
			return 0;
		Node* cur = root;
		for (int i = 0; i < word.size(); i++)
		{
			//abc插入过,你让我查abcde,在d时已经没路往下继续了,abcde就没出现过
			if (cur->next[word[i]] == nullptr)
				return 0;
			cur = cur->next[word[i]];
		}
		return cur->pass;//pass的作用
	}
	//删除某一个字符串,沿途的pass--,最后一个节点的end--即可
	//当到某一个点时pass==0,后续的都可以删
	void deleteNode(string& word)
	{
		if (search(word) == 0)return;
		Node* cur = root;
		cur->pass--;
		for (int i = 0; i < word.size(); i++)
		{
			Node* curNext = cur->next[word[i]];
			if (--curNext->pass == 0)//cur->next这个点没路,需要将next点以及后续节点全删
			{
				//1. 将next以及后续节点删除并置空
				//需要根据next->map中的指针信息将指针指向的节点空间释放
				//遍历cur->next[]-?free
				 for (pair<char,Node*> deletePair : curNext->next)
				 {
					 free(deletePair.second);
					 deletePair.second = nullptr;
				 }
				 curNext->next.clear();//将承装curNext连接信息的容器(map)删除
				 //2. 在cur->next这条路置空代表以后走不了了
				 curNext = nullptr;
			}
			cur = cur->next[word[i]];
		}
		cur->end--;
	}
private:
	Node* root;
};
int main()
{
}