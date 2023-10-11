#include<iostream>
#include<string>
using namespace std;

//N层汉诺塔问题,想要把n个圆盘移动到另一个上去,并且大不能压小
//from end other 代表每次移动中杆子的标识,是可变换角色的
//1. 将1~i-1个圆盘移动到other上去
//2. 将第i个最大的移动到end上去
//3. 转换目标:此时就是将other上的i-1个圆盘移动到end上去
//4. 缩小为子问题:先将1~i-2圆盘移动到from上去,再 将other上的第i-1个圆盘移动到end上
//周而复始...

void func(int i, string from, string end, string help)
{
	if (i == 1)
		cout << "Move 1 from " + from + "to " + end;
	else
	{
		func(i - 1, from, help, end);
		cout << "Move " + to_string(i) + " from " + from + " to" + end;
		func(i-1,help,end,from);
	}
}
void hanoi(int n)
{
	if (n > 0)
	{
		func(n,"left","right", "mid");//将left->right上
	}
}
