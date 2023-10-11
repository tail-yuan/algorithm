//����һ���ַ������͵�����arr��Ʃ�磺
//String[] arr = { "b\\cst", "d\\", "a\\d\\e", "a\\b\\c" };
//�����Щ·�����̺���Ŀ¼�ṹ������������Ŀ¼ֱ�����ڸ�Ŀ¼���棬���ȸ�Ŀ¼
//���ҽ����񣬾������� :
//a
//  b
//    c
//  d
//    e
//b
//  cst
//d
//ͬһ������Ҫ����ĸ˳�����У������ҡ�

//����ǰ׺��+������ȱ������ƴ�ӡ
//                null
//1.     a                b          d
//2.   b  d                cst
//3.  c    e
//�ڶ������4�ո��ӡһ��,������ͼ��8�ո񼴿���ɶ��ƴ�ӡ
//����ǰ׺��:����е�Ŀ��ڵ��·,�͸���,û�о��½�
#include<iostream>
#include<map>
#include<vector>
using namespace std;
class GetFolderTree
{
public:
	class Node
	{
	public:
		string name;
		map<string, Node*> nextArr;
	public:
		Node(string s = "null")
			:name(s)
		{}
	};
	void print(vector<string>& floderArr)
	{
		if (floderArr.size() == 0)
			return;
		Node* head = getFolderTree(floderArr);
		printHead(head, 0);
	}
	void printHead(Node* head, int level)
	{
		if (level != 0)
			cout << get2space(level) << head->name << endl;
		//��ȡ�ڶ����ֵ
		//Node* tmp = head->nextArr[head->name];
		auto it = head->nextArr.begin();
		while (it!=head->nextArr.end())
		{
			printHead(it->second,level+1);
			it++;
		}
	}
	string get2space(int n)
	{
		string res = "";
		for (int i = 1; i < n; i++)
			res += " ";
		return res;
	}
	/*template<typename T>
	void printHead(T* head, int level)*/
	//void printHead(Node* head, int level) ���Node* δʶ���ʶ��������.1. ʹ��typename���߱����������ұ���ͨ��,�������ͻᲹ��2. ��Node����������ǰ��
	/*class Node
	{
	public:
		string name;
		map<string, Node*> nextArr;
	public:
		Node(string s = "null")
			:name(s)
		{}
	};*/
	Node* getFolderTree(vector<string>& floderArr)
	{
		Node* head = new Node();
		for (string& folderPath : floderArr)
		{
			//����Ŀ¼�и��,��һ��dirĿ¼���ָһ��������
			vector<string> paths = mySplit(folderPath, "\\");
			//��head��ʼ���¹�����
			Node* cur = head;
			for (int i = 0; i < paths.size(); i++)
			{
				//û�о��½�
				if (cur->nextArr.find(paths[i]) == cur->nextArr.end())
					cur->nextArr.insert({ paths[i],new Node(paths[i]) });
				//�о͸��ýڵ�Ȼ�����������
				cur = cur->nextArr[paths[i]];
			}
			//���һ��·������
		}
		return head;
	}
	//ͨ��strtok����ʵ��C++��string��split()����
//strtokΪC�����е��ַ����ָ����������������:
//	ԭ�ͣ�char* strtok(char* str, const char* delimiters);
//	���ܣ��ָ��ַ���str��delimitersΪָ���ķָ���������ж����
//		˵����strtokֻ�ܽ���C�����ַ����������string���ͣ�����ʹ��c_str��������ת����
//		strtok()�������ַ����ָ��һ����Ƭ�Ρ�����sָ�����ָ���ַ���������delim��Ϊ�ָ��ַ�����
//		��strtok()�ڲ���s���ַ����з��ֵ�����delim�ķָ��ַ�ʱ ��Ὣ���ַ���Ϊ\0 �ַ���
//		�ڵ�һ�ε���ʱ��strtok()����������s�ַ���������ĵ����򽫲���s���ó�NULL��
//		ÿ�ε��óɹ��򷵻ر��ָ��Ƭ�ε�ָ�롣
	vector<string> mySplit(string& str, string&& pattern)
	{
		char* tmp_str = new char[str.size() + 1];
		strcpy(tmp_str, str.c_str());
		vector<string>res;
		char* tmp = strtok(tmp_str, pattern.c_str());
		while (tmp != nullptr)
		{
			res.push_back(std::string(tmp));
			tmp = strtok(NULL, pattern.c_str());
		}
		delete[] tmp_str;
		return res;
	}
};