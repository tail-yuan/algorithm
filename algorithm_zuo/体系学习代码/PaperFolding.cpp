#include<iostream>
using namespace std;

//i:��ǰ�ǵڼ���
//n:һ������,Ҳ���Ƕ��ۼ���
//down:true->��(����) false->͹(�Һ���)
void printProcess(int i, int n, bool down)
{
	if (i > n)
		return;
	printProcess(i+1,n,true);
	cout << down ? "�� " : "͹ ";
	printProcess(i+1,n,false);
}
void paperFolding(int n)
{
	printProcess(1,n,true);
}