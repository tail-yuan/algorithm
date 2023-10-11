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
//任何递归都能改成非递归,只不过是自己使用栈模拟系统函数压栈

//1. 将节点压栈
//2 .弹出栈顶元素,打印值
//3. 先压右节点再压左节点
//4. 周而复始
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

//后序遍历:使用两个栈,st1 st2
//1. 压栈st1 弹出栈顶元素->st2
//2. 先压左再压右->st1
//3. 周而复始
// 收集顺序是头左右,该打印时不打印,打印辅助栈中,就是左右头即后序
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
	//打印
	while (!st2.empty())
	{
		cout << st2.top()->val << " ";
		st2.pop();
	}
	cout << endl;
}

//中序遍历
//1. 先将每一个子树的整个左边界压入栈中
//2. 依次弹栈时do打印
//3. 再压入节点右子树节点(如果右子树为空,就继续弹栈)
//4. 周而复始
//来到一个节点,只要有左边界,全部压入栈中
//栈可能会出现空时还没有将所有节点入栈,条件+head==nullptr,代表遇到的都空了就代表完成了
void inOrderUnRecur(Node* head)
{
	if (head == nullptr)
		return;
	stack<Node*>st;
	while (!st.empty()||head!=nullptr)
	{
		if (head)//只要有左边界,全部压入栈中
		{
			st.push(head);
			head = head->left;
		}
		else//head为空了,开始弹栈+do thing + 走右节点
		{
			head = st.top(); st.pop();
			cout << head->val << " ";
			head = head->right;
		}
	}
}