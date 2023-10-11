#include<iostream>
#include<deque>
#include<vector>
using namespace std;


//窗口运动是随意的
// 如何得出窗口中最大值最小值(不使用遍历的方式)
// 使用双端队列 更新策略保证头部肯定是最大值
//	R 往右走时时刻保持队列中从头到尾是从大到小的顺序
// 1. push_back()
// 2. 如果cur > deque.pop_back()=> 一直弹栈到cur<deque.pop_back(),再push_back(cur)即使为空
//	L往右走
// 1.如果队列头部是L往右走之后过期的值,就pop_front
// 2.如果不是就不用管(可能是因为push_back()时让本应该过期的值在L++之前就弹出了)

// 维护的是当窗口不变时,成为最大值的可能性.L往右走一步,头部过期,下一个成为最大值
// R++更新策略解释: cur>deque.pop_back(),cur比它大 + 比他晚过期,它没可能成为最大值了
// T(N):每个位置进出队列的次数
// 每个位置都进出各一次,划过N个数,O(N),每个数字不让第二次进,平均T(N)=O(1)
//

//本题窗口运动是固定的一起动

vector<int>getMaxOfWindow(vector<int>&arr,int w)
{
	if (arr.size() == 0 || w < 1 || arr.size() < w)
		return vector<int>();
	deque<int> qmax;
	vector<int>res(arr.size()-w+1);
	int index = 0;
	for (int i = 0; i < arr.size(); i++)
	{
		while (!qmax.empty() && arr[qmax.front()] <= arr[i])
			qmax.pop_back();
		qmax.push_back(i);
		//1. 窗口怎么移动? 当遍历到i为止时,窗口左边界应该是i-w,随着i的右移,左边界应该过期的数据下标就是i-w
		// 什么时候弹出队列头(队列头下标数据什么时候过期)呢?当 i-w==q.front()
		// 否则一定是刚被更新的数据,还没到过期的时候,也不需要弹出队列
		if (qmax.front() == i - w)
			qmax.pop_front();
		//2. 什么时刻获取队列最大值并记录,从形成窗口大小之后即数组下标到达w-1开始以后每添加一个数都需要获取
		//此时窗口的最大值,即队列头元素
		if (i >= w - 1)
			res[index++] = qmax.front();
	}
}