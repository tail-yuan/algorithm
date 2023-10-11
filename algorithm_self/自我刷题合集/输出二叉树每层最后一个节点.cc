#include<iostream>
#include<queue>
#include<vector>
using namespace std;

//使用队列模拟层序遍历,每弹出一个节点,就将他的左右子树插入,
//队列中弹出到只有一个节点时进行输出操作=>发现不球行
//还是得使用levelSize记录每一层个数
class Node
{
    public:
    int data;
    Node* left;
    Node* right;
};

class BSTree
{
public:
    vector<int> GetLevelLastNode(Node* head)
    {
        if(head==nullptr) return ;
        vector<int>ret;
        queue<Node*> q;
        q.push(head);
        while (!q.empty())
        {
            int levelSize = q.size();
            int lastNodeVal = 0;
            for (int i = 0; i < levelSize; i++)//弹出前n个
            {
                int front = q.front(), q.pop();
                //do!
                //记录节点
                lastNodeVal = front->val;//记录的正好的最后一个
                if (front->left)
                    q.push(front->left);
                if (front->right)
                    q.push(front->right);
            }
            ret.push_back(lastNodeVal);
        }
        return ret;
    }
};