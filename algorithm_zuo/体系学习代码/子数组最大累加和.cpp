
//题干:分记录为[1,1,-1,-10,11,4,-6,9,20,-10,-2],那么该条帖子曾经到达过的最高分数为
//11 + 4 + (-6) + 9 + 20 = 38。请实现一段代码，输入为帖子近期的打分记录，输出为当前帖子得到的最高分数。

//1. 先走一遍算法规定(由假设的答案的性质,为了寻找假设的答案所做出的最好的行为)
// 例子: 3,2,-1,4,-9,4,-2,3,4,-2,6
// steps: cur=0,maxSum=INT_MIN 
//		  cur+=arr[i] maxSum=max(maxSum,cur),有没有让maxSum变大
//        if cur<0 then cur=0 
//		  else cur=cur
// result=13
//2. 方法是假设答案法
// 假设得到最大值的连续子数组是所有连续子数组中 累加和最大 && 长度最长的,即[i,j]区间
//  i-1 [i,j] j+1 
// 那么必然满足两个性质,
// (1) 任意end 属于[i,j] ,累加和[i,end]必然>=0;如果到end点造成累加和<0了,那就不是我假设的答案区间
// (2) 累加和[?...i-1]必然<0; 如果>=0,为什么不和[i,j]区间连起来? 也就不是我假设的最长区间和最大区间
// 所以cur 必然是以0的姿态开始累加i位置的值,在累加[i,j]位置的值过程中,max时刻都在关注着这段区间的累加和大小
// 一旦超过了之前区间的累加和设置的max值,他就会更新自身,代表是[i,j]区间的累加和
// 
// 3. 由方法推操作有哪些
// (1) cur<0 then cur=0
// (2) cur>=0  then cur不变,继续去累加可能是想要的[i,j] 的值
// (3) max时刻记录是否让max值更大了
//
#include<iostream>
#include<vector>
using namespace std;
class SubArrayMaxSum
{
public:
	int getMaxSum(vector<int>& arr)
	{
		int maxSum = INT_MIN;
		int cur = 0;
		for (int i = 0; i < arr.size(); i++)
		{
			cur += arr[i];
			maxSum = max(maxSum, cur);
			cur = cur < 0 ? 0 : cur;
			//if (cur < 0) cur = 0;
			//else cur=cur;
		}
		return maxSum;
	}
};