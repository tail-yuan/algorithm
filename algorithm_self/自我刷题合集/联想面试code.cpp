#include<iostream>
#include<vector>
using namespace std;
vector<string> mySplit(string& str)
{
	vector<string>ans;
	char* tmp = new char[str.size() + 1];
	strcpy(tmp, str.c_str());
	char* cur = strtok(tmp, ".");
	while (cur != nullptr)
	{
		ans.push_back(cur);
		cur = strtok(NULL, ".");
	}
	delete[]tmp;
	return ans;
}
class Node
{
public:
	int val;
	Node* next;
};
Node* reverseList(Node* head)
{
	if (head == nullptr || head->next == nullptr)
		return head;
	Node* prev = nullptr;
	Node* cur = head;
	Node* next = nullptr;
	while (cur != nullptr)
	{
		next = cur->next;
		cur->next = prev;
		prev = cur;
		cur = next;
	}
	return prev;
}
//int main()
//{
//	return 0;
//}