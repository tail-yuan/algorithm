
//题干:给定一个整型矩阵，返回子矩阵的最大累计和;
//题意:也就是在数组中任意画一个m*n的矩阵,这个矩阵的累加和就是最大的.
//压缩数组
// 想法:借用求解子数组最大累加和的方法opt,那么如何实现所有矩阵情况的遍历 并且应用opt方法呢?
// 1. 遍历: 0~0   一行 ,直接应用opt
//			0~1   两行 ,将两行中对应下标进行累加->tmp[]数组,应用opt
//			0~1~2 三行 ,将三行中对应下标进行累加->tmp[]数组,应用opt
//			1~1   一行 ,...
//			1~2   两行
//			2~2   一行
//          ......
// 每一次求得一个maxSum,然后对所有情况的maxSum进行比较得到最大的值
//
#include<iostream>
#include<vector>
using namespace std;
class SubMatrixMaxSum
{
public:
	int maxSum(vector<vector<int>>& m)
	{
		if (m.size() == 0 || m[0].size() == 0)
			return 0;
		int maxSum = INT_MIN;
		int cur = 0;
		vector<int>tmp(m[0].size());
		for (int i = 0; i < m.size(); i++)//i代表从哪行开始向下start
		{
			for (int j = i; j < m.size(); j++)//j是从i开始向下到哪一行end
			{
				cur = 0;
				for (int k = 0; k < tmp.size(); k++)//opt
				{
					tmp[k] += m[j][k];//实现压缩数组的效果,j=0:tmp记录的就单独一行;j=2tmp记录的就两行的累加和
					cur += tmp[k];
					maxSum = max(maxSum,cur);
					cur = cur < 0 ? 0 : cur;
				}
			}
		}
		return maxSum;
	}
};