#include<iostream>
using namespace std;

//i:当前是第几层
//n:一共几层,也就是对折几次
//down:true->凹(左孩子) false->凸(右孩子)
void printProcess(int i, int n, bool down)
{
	if (i > n)
		return;
	printProcess(i+1,n,true);
	cout << down ? "凹 " : "凸 ";
	printProcess(i+1,n,false);
}
void paperFolding(int n)
{
	printProcess(1,n,true);
}