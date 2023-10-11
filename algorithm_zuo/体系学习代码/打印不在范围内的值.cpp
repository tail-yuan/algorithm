//给定一个整数数组A，长度为n，有 1 <= A[i] <= n，且对于[1,n]的整数，其中部分整数会重复出现而部分不会出现。
//实现算法找到[1, n]中所有未出现在A中的整数。
//提示：尝试实现O(n)的时间复杂度和O(1)的空间复杂度（返回值不计入空间复杂度）。
//输入描述：
//一行数字，全部为整数，空格分隔
//A0 A1 A2 A3... 输出描述：
//一行数字，全部为整数，空格分隔R0 R1 R2 R3... 示例1:
//输入
//1 3 4 3
//输出
//2
// 
//思路:就是实现下标为i的位置之上必须是i+1这个值,如果i位置不是i+1,就说明i+1就是缺失的那个值

#include<iostream>
#include<vector>
using namespace std;


class printNumNoInArray
{
public:
	void printNumberNoInArray(vector<int>& arr)
	{
		if (arr.size() == 0)
			return;
		for (auto e : arr)
		{
			modify(e,arr);//让e放到e-1的位置上去
		}
		for (int i = 0; i < arr.size(); i++)
			if (arr[i] != i + 1)
				cout << i+1 << endl;
	}
	void modify(int value, vector<int>& arr)
	{
		while (arr[value - 1] != value)
		{
			int tmp = arr[value - 1];
			arr[value - 1] = value;
			value = tmp;
		}
	}

};