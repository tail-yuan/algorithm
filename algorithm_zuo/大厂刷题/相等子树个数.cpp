//���һ���ڵ�X���������ṹ�������ṹ��ȫһ��.�ṹ������������ֵ.��ô����˵��XΪͷ�����������
//����һ�ö�������ͷ�ڵ�head����head���������ж��ٿ��������
//���:
// 1. O(n)
//�����ڵ�x,���������������,���������������,�������ṹ���������ṹ�Ƿ���ͬ,true +1
//��Խƽ��,�Ƚϴ���Խ��,����㷨Ч��Խ��.����Ƿǳ���ƽ���,��ô���Ժܿ�ĵó�false
//�����ƽ���,��������T(N/2),������Ҳ��T(N/2)
//T(N)=2*T(N/2)+O(N),����master��ʽ->T(N)=O(nlogn)
// 2.�����������ȶԵĹ��̽���ΪO(1)
// ���������ṹ��Ϣ���л�Ϊ�ַ�����Ϣstr,�پ���Hash��ʽ�õ�һ��ȷ����ֵ,
// �����ַ����೤Hash�ó���codeһ���Ƕ�����,���Աȶ�һ����O(1)
// ���������ֱ�õ�һ��ֵleftCode,rightCode,�ȶ��Ƿ����O(1)
// ������,�ټ��Ͻڵ�code,leftCode_code_rightCode,�پ���hash�õ��µ�code,�������ϴ���.
//���ֻ��Ҫ���������ֱ𷵻����ǵ��������������HashCode
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
