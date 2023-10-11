#include"head.hpp"
//来自腾讯音乐
// 给定一棵树，一共有n个点
// 每个点上没有值，请把1~n这些数字，不重复的分配到二叉树上
// 做到 : 奇数层节点的值总和 与 偶数层节点的值总和 相差不超过1
// 返回奇数层节点分配值的一个方案
// 2 <= n <= 10^5 

//1.通过二叉树深度优先遍历得到奇数层k,总数n个节点
//2.如何进行分配[1,n],选出k个给奇数层,剩下的给偶数层
	//2.1 无法使用动归,因为节点个数太多
	//2.2 奇数层的累加和sum1肯定大于前k个数字累加和,并且小于最后k个数字的累加和,否则无法实现分配
	//2.3 n如果是偶数,就是一半一半,如果是奇数,就可能存在两种分配,一多一少呗
//3. 设计一个函数generate(x,n,k)
//[1, n]其中选择k个数字, 让k个数字的累加和是x, , 返回一种方法就行

class Solution
{
public:
	//[1,n]范围数字,k是奇数层在数组中要选取的个数
	int* team(int n, int k)
	{
		int sum = (n + 1) * n / 2;
		int p1 = sum / 2;
		int p2 = (sum + 1) / 2;
		int* ans= generate(p1,n,k);
		if (ans!=nullptr && (p1 != p2))//说明n是奇数,换着再走一遍
		{
			ans = generate(p2,n,k);
		}
		return ans != nullptr ? ans : new int[n] {-1};
	}
	//[1,n]其中选择k个数字,让k个数字的累加和是x,,返回一种方法就行
	int* generate(int x, int n, int k)
	{
		//首先得到前k个数字的累加和
		int sumMink = (k + 1) * k / 2;
		//每个数字提升幅度,从自身位置搬家到最后一个空位置
		int range = n - k;
		if (x<sumMink || x>(sumMink + k * range))
		{
			return nullptr;
		}
		int addSum = x - sumMink;
		//需要向后搬家到最后的个数有几个
		int rightSize = addSum / range;
		//需要向后搬家确定位数的那个,最终到哪,就是那个
		int midIndex = (k - rightSize) + (addSum % range);
		int leftSize = k - rightSize - (addSum % range == 0 ? 0 : 1);
		int* ans = new int(k);
		//前几个不需要搬家的
		for (int i = 0; i < leftSize; i++)
		{
			ans[i] = i + 1;
		}
		//如果存在的那个
		if (addSum % range != 0)
			ans[leftSize] = midIndex;
		//搬家到最后的,最后几个值
		for (int i = k - 1, j = 0; j < rightSize;i--, j++)
		{
			ans[i] = n - j;
		}
		return ans;
	}
	void OddLevelEvenLevelSumClosed(string & args)
	{
		int n = 100;
		int k = 33;
		int* ans = team(n,k);
	}
};