#include<iostream>
#include<string>
#include<vector>
#include<stack>
using namespace std;
//从一行开始,每一行从第一列开始选中一个格子,
//只需要保证下一次选中的格子和之前选中的不冲突(不在一行,不在一列,不在一条斜线)即可
class NQueens
{
public:
	int num(int n)
	{
		if (n < 1)
			return 0;
		int* record = new int[n];//record[i]=j 记录第i行的皇后放在第j列
		return process(record,0,n);
	}
	int process(int* a, int i, int n)
	{
		//base case 从开头往后按照不冲突走,走到尾了,说明这是一种有效方法结尾,返回方法数1
		if (i == n)
			return 1;
		int res = 0;
		for (int j = 0; j < n; j++)
		{
			if (isValid(a, i, j))
			{
				a[i] = j;
				res += process(a,i+1,n);
			}
		}
		return res;
	}
	//在第i行选择,只需要关注[0,i-1]位置上是否和j冲突
	bool isValid(int* record, int i, int j)
	{
		for (int k = 0; k < i; k++)
		{
			if (j == record[k] || abs(record[k] - j) == abs(k - i))//共斜线
				return false;
		}
		return true;
	}
};
//常数时间可以优化,但是O(N!)时间复杂度是不可优化的
//不超过32皇后问题
// n皇后问题总限制设置limit后n位是1,前面全是0
//设置3个变量作为限制信息的记录,int类型有32位,位运算,1代表已经占据
// 假设是8皇后问题,我首先第一行选中的是i=5位,那么三个限制就是:
// colLimit   00001000 是colLimit|第5位为1
// leftLimit  00010000 是leftLimit|0000100,然后向左移动一位
// rightLimit 00000100 是rightLimit|0000100,然后向右移动一位
//     |之后: 00011100
//     ~之后: 11100011
// &limit之后:11100011
// 我在第二行选中第二位是1
// 之后得到的数pos,1所在位置代表可以选择,0代表不可选择
// colLimit   01001000 是colLimit|第2位为1
// leftLimit  10010000 是leftLimit|0000100,然后向左移动一位
// rightLimit 00100100 是rightLimit|0000100,然后向右移动一位
//     |之后: 11111100
//     ~之后: 00000011
// &limit之后:00000011 1就是可以放的位置 limit作用就是取反之后将前面无用的位数全部截掉
class NQueens_Plus
{
public:

	int process(int limit, int colLim, int leftLim, int rightLim)
	{
		//如果列和limit相同了,说明collim是全1,每一行取一个位置的话每一列都取1了,是一种方法返回1 
		if (limit == colLim)
			return 1;

		int pos = 0;
		int theRightestOne = 0;
		//列限制|左限制|右限制就是总位置限制,
		pos = limit & (~(colLim | leftLim | rightLim));
		int res = 0;
		while (pos != 0)
		{
			//实现有几个1循环就走几次,在每个1位置都试一次皇后
			theRightestOne = pos & (~pos + 1);//提取最右边的1
			pos = pos - theRightestOne;			//提取之后减去最右边1=>变成新的数
			//下一行选择的限制信息就是pos值
			res += process(limit,colLim | theRightestOne,
							(leftLim | theRightestOne)<<1,
							(rightLim | theRightestOne)>>1);
		}
		return res;
	}
	int num(int n)
	{
		if (n < 1 || n>32)
			return 0;
		//n皇后问题就将后n位设置为1 -1就是32位全1
		int limit = n == 32 ? -1 : (1 << n) - 1;
		return process(limit,0,0,0);
	}
};