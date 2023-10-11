#include"head.hpp"
//每次吃自己右边,离自己最近且比自己小的鱼,一轮可以吃多条
//就是吃到不能吃
//可存在几条鱼吃一条小鱼(但是我后面的张三如果也可以吃,就保存他吃的轮数就可)
//单调栈(小压大)
//		7 3 2 4 2 3 5 1 4 2
//栈:
//		|3,1 |
//		|4,2 |
//		|5,2 | 5吃完后续需要两轮,第一轮5 4 第二轮剩下5
//7要入栈,要吃3肯定是在一轮中3把2吃完了 7顺便把刚吃完1的3吃了,所以是7,1
//7>4 则继续吃,等4在第二轮吃完后面的之后,7顺便把4吃了,所以是7,2
//7>5 则继续吃,等5在第二轮吃完后面的之后,7刚把4吃完,7,2 5,2 ,等下一轮7再把5吃了就OK,
// 面上看起来就是7的2+1和5的2求最大值
//max(2+1,2)	max(curTurn+1,MonStack[--stackSize][1]);
//栈中有元素,并且栈顶元素比我小,那么我要消费他
//max(我的轮数+1(我吃他得费我一轮),他的轮数(在同一轮中他完事了顺便把它吃了)求最大值就是我要压栈的轮数
class Solution
{
public:
	int EatFish(vector<int>& arr)
	{
		int n = arr.size();
		//MonotonicStack/*单调栈*/
		vector<vector<int, int>>MonStack(n);
		int stackSize = 0;
		int ans = 0;
		for (int i = n - 1; i >= 0; i--)
		{
			int curTurn = 0;
			while (stackSize > 0 && MonStack[stackSize - 1][0] < arr[i])
			{
				curTurn = max(curTurn+1,MonStack[--stackSize][1]);//注意索引下标
			}
			//不能再吃了,将自己入栈
			MonStack[stackSize][0] = arr[i];
			MonStack[stackSize][1] = curTurn;
			//记录最大轮数
			ans = max(ans, curTurn);
		}
		return ans;//返回最大轮数(就是结束)
	}
};