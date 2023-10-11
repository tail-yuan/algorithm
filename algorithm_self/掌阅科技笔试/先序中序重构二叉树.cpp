
//https://leetcode.cn/problems/construct-binary-tree-from-preorder-and-inorder-traversal/submissions/
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
class TreeNode
{
public:
    TreeNode* left;
    TreeNode* right;
    int val;
    TreeNode(int v = 0)
        :val(v)
        , left(nullptr)
        , right(nullptr)
    {}
};
class Solution
{
    unordered_map<int, int>hashMap;//<val,index>
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
    {
        for (int i = 0; i < inorder.size(); i++)
            hashMap[inorder[i]] = i;
        return func(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
    }
    TreeNode* func(vector<int>& preorder, int preStart, int preEnd, vector<int>& inorder, int inStart, int inEnd)
    {
        if (preStart > preEnd)
            return nullptr;
        int rootVal = preorder[preStart];
        int index = hashMap[rootVal];
        int leftSize = index - inStart;
        TreeNode* root = new TreeNode(rootVal);
        root->left = func(preorder, preStart + 1, preStart + leftSize, inorder, inStart, index - 1);
        root->right = func(preorder, preStart + leftSize + 1, preEnd, inorder, index + 1, inEnd);
        return root;
    }
};