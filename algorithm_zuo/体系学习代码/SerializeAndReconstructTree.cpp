#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<string>
#include<list>//使用链表的进出由于vector
using namespace std;
class Node
{
public:
	string val;
	Node* left;
	Node* right;
	Node(string v="")
		:val(v)
		, left(nullptr)
		, right(nullptr)
	{}
};

string Serialize(Node* head)
{
	if (head == nullptr)
		return "#!";
	string res = head->val + "!";
	res += Serialize(head->left);
	res += Serialize(head->right);
	return res;
}
//借用strtok(char*,char*)
list<string> split(const string& str,const string& delimiter)
{
	list<string> res;
	//先将string->char*  c_str()实现的是string->const char*
	char* strs = new char[str.length() + 1]; //不要忘了
	strcpy(strs, str.c_str());

	char* d = new char[delimiter.length() + 1];
	strcpy(d, delimiter.c_str());

	char* p = strtok(strs, d);
	while (p) {
		string s = p; //分割得到的字符串转换为string类型
		res.push_back(s); //存入结果list
		p = strtok(NULL, d);
	}
	return res;
}
Node* reConPreOrder(list<string>& ans)
{
	string val = ans.front(); ans.pop_front();
	if (val == "#")
		return nullptr;
	Node* node = new Node(val);
	node->left = reConPreOrder(ans);
	node->right = reConPreOrder(ans);
	return node;
}
Node* ReConstructTree(string& str)
{
	list<string> ans = split(str, "!");
	return reConPreOrder(ans);
}
//int main()
//{
//	string str = "1#2#3#";
//	list<string> ans=split(str,"#");
//	return 0;
//}
