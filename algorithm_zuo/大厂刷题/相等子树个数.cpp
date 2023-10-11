//如果一个节点X，它左树结构和右树结构完全一样.结构包括个数和数值.那么我们说以X为头的树是相等树
//给定一棵二叉树的头节点head返回head整棵树上有多少棵相等子树
//题解:
// 1. O(n)
//遇到节点x,左子树相等树个数,右子树相等树个数,左子树结构和右子树结构是否相同,true +1
//树越平衡,比较次数越多,这个算法效率越差.如果是非常不平衡的,那么可以很快的得出false
//如果是平衡的,左子树走T(N/2),右子树也是T(N/2)
//T(N)=2*T(N/2)+O(N),根据master公式->T(N)=O(nlogn)
// 2.将左右子树比对的过程降低为O(1)
// 将二叉树结构信息序列化为字符串信息str,再经过Hash方式得到一个确定的值,
// 无论字符串多长Hash得出的code一定是定长的,所以比对一定是O(1)
// 左右子树分别得到一个值leftCode,rightCode,比对是否相等O(1)
// 如果相等,再加上节点code,leftCode_code_rightCode,再经过hash得到新的code,继续向上传递.
//这回只需要左右子树分别返回他们的相等子树个数和HashCode
#include<iostream>
using namespace std;
class Node
{
public:
	int val;
	Node* left;
	Node* right;
};
class Solution
{
public:
	int sameNumber(Node* head)
	{
		if (head == nullptr)
			return 0;
		return sameNumber(head->left) + sameNumber(head->right) +
			isSame(head->left, head->right) ? 1 : 0;
	}
	bool isSame(Node* x, Node* y)
	{
		if (x == nullptr&&y != nullptr)return false;
		if (x != nullptr&&y == nullptr)return false;
		if (x == nullptr && y == nullptr)return true;
		return x->val == y->val && isSame(x->left, y->left) && isSame(x->right, y->right);
	}
};

void test()
{}
//#include "openssl/sha.h"
//std::string sha256(const std::string& input) 
//{
//	unsigned char hash[SHA256_DIGEST_LENGTH];
//	SHA256_CTX sha256;
//	SHA256_Init(&sha256);
//	SHA256_Update(&sha256, input.c_str(), input.length());
//	SHA256_Final(hash, &sha256);
//
//	std::stringstream ss;
//	for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
//		ss << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(hash[i]);
//	}
//
//	return ss.str();
//}
//
//int main() {
//	std::string input = "Hello, Hashing!";
//	std::string hash = sha256(input);
//	std::cout << "Input: " << input << std::endl;
//	std::cout << "SHA-256 Hash: " << hash << std::endl;
//	return 0;
//}
