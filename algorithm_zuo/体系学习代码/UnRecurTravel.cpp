#include<iostream>
#include<stack>
using namespace std;
class Node
{
public:
	int val;
	Node* left;
	Node* right;
};
//�κεݹ鶼�ܸĳɷǵݹ�,ֻ�������Լ�ʹ��ջģ��ϵͳ����ѹջ

//1. ���ڵ�ѹջ
//2 .����ջ��Ԫ��,��ӡֵ
//3. ��ѹ�ҽڵ���ѹ��ڵ�
//4. �ܶ���ʼ
void preOrderUnRecur(Node* head)
{
	if (head == nullptr)return;

	stack<Node*>st;
	st.push(head);
	while (!st.empty())
	{
		Node* topNode = st.top();
		st.pop();
		cout << topNode->val << " ";
		if (topNode->right)
			st.push(topNode->right);
		if (topNode->left)
			st.push(topNode->left);
	}
	cout << endl;
}

//�������:ʹ������ջ,st1 st2
//1. ѹջst1 ����ջ��Ԫ��->st2
//2. ��ѹ����ѹ��->st1
//3. �ܶ���ʼ
// �ռ�˳����ͷ����,�ô�ӡʱ����ӡ,��ӡ����ջ��,��������ͷ������
void postOrderUnRecur(Node* head)
{
	if (head == nullptr)return;
	stack<Node* >st1;
	stack<Node* >st2;
	st1.push(head);
	while (!st1.empty())
	{
		Node* topNode = st1.top();
		st1.pop();
		st2.push(topNode);
		if (topNode->left)
			st1.push(topNode->left);
		if (topNode->right)
			st1.push(topNode->right);
	}
	//��ӡ
	while (!st2.empty())
	{
		cout << st2.top()->val << " ";
		st2.pop();
	}
	cout << endl;
}

//�������
//1. �Ƚ�ÿһ��������������߽�ѹ��ջ��
//2. ���ε�ջʱdo��ӡ
//3. ��ѹ��ڵ��������ڵ�(���������Ϊ��,�ͼ�����ջ)
//4. �ܶ���ʼ
//����һ���ڵ�,ֻҪ����߽�,ȫ��ѹ��ջ��
//ջ���ܻ���ֿ�ʱ��û�н����нڵ���ջ,����+head==nullptr,���������Ķ����˾ʹ��������
void inOrderUnRecur(Node* head)
{
	if (head == nullptr)
		return;
	stack<Node*>st;
	while (!st.empty()||head!=nullptr)
	{
		if (head)//ֻҪ����߽�,ȫ��ѹ��ջ��
		{
			st.push(head);
			head = head->left;
		}
		else//headΪ����,��ʼ��ջ+do thing + ���ҽڵ�
		{
			head = st.top(); st.pop();
			cout << head->val << " ";
			head = head->right;
		}
	}
}