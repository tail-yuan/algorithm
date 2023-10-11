#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
//ǰ׺���ܽ��������
//1. ��ĳһ���ַ�Ϊǰ׺���ַ��������˼���
//2. ĳһ���ַ����ֵĴ���(hashMapҲ����)
class TrieNode
{
public:
	int pass;//�ж��ٸ��ַ������������ڵ�,Ҳ�����ж��ٸ��ַ���������ڵ��ϵ��ַ�
	int end;//��ĳһ���ڵ�Ϊ��β���ַ����ĸ���
	unordered_map<char, TrieNode*> next;
	//next[0]==nullptr û�е���'a'�ַ���·
	//next[1]!=nullptr   �е���'b'�ַ���·
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
	//Node �ڵ��next����Ϊ��,�����ܵ�����½�,������;��pass++,ֱ���ַ���β��ʱend++
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
	//word���ֹ�����
	int search(string& word)
	{
		if (word.size() == 0)
			return 0;
		Node* cur = root;
		for (int i = 0; i < word.size(); i++)
		{
			//abc�����,�����Ҳ�abcde,��dʱ�Ѿ�û·���¼�����,abcde��û���ֹ�
			if (cur->next[word[i]] == nullptr)
				return 0;
			cur = cur->next[word[i]];
		}
		return cur->end;//end������
	}
	//�ж��ٸ��ַ�������word��Ϊǰ׺���ֹ���
	int prefixNumber(string& word)
	{
		if (word.size() == 0)
			return 0;
		Node* cur = root;
		for (int i = 0; i < word.size(); i++)
		{
			//abc�����,�����Ҳ�abcde,��dʱ�Ѿ�û·���¼�����,abcde��û���ֹ�
			if (cur->next[word[i]] == nullptr)
				return 0;
			cur = cur->next[word[i]];
		}
		return cur->pass;//pass������
	}
	//ɾ��ĳһ���ַ���,��;��pass--,���һ���ڵ��end--����
	//����ĳһ����ʱpass==0,�����Ķ�����ɾ
	void deleteNode(string& word)
	{
		if (search(word) == 0)return;
		Node* cur = root;
		cur->pass--;
		for (int i = 0; i < word.size(); i++)
		{
			Node* curNext = cur->next[word[i]];
			if (--curNext->pass == 0)//cur->next�����û·,��Ҫ��next���Լ������ڵ�ȫɾ
			{
				//1. ��next�Լ������ڵ�ɾ�����ÿ�
				//��Ҫ����next->map�е�ָ����Ϣ��ָ��ָ��Ľڵ�ռ��ͷ�
				//����cur->next[]-?free
				 for (pair<char,Node*> deletePair : curNext->next)
				 {
					 free(deletePair.second);
					 deletePair.second = nullptr;
				 }
				 curNext->next.clear();//����װcurNext������Ϣ������(map)ɾ��
				 //2. ��cur->next����·�ÿմ����Ժ��߲�����
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