#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;
//O(N*M) 
//遍历的时候,每一个点碰一次,递归的时候每一个点只可能被上下左右各自一次4次

void infect(vector<vector<int>>& arr, int i, int j, int n, int m)
{
	if (i<0 || i>=n || j<0 || j>=m || arr[i][j] != 1)
		return;
	arr[i][j] = 2;
	infect(arr,i+1,j,n,m);
	infect(arr,i-1,j,n,m);
	infect(arr,i,j+1,n,m);
	infect(arr,i,j-1,n,m);
}
int countIslands(vector<vector<int>>& arr)
{
	if (arr.size() == 0)
		return 0;
	int n = arr.size();
	int m = arr[0].size();
	int res = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (arr[i][j] == 1)
			{
				res++;
				infect(arr,i,j,n,m);
			}
		}
	}
}
//多内存多CPU
//如何设计一个并行算法解决这个问题?
//分配任务的时候就涉及到数组的切分,将左侧一半交给一个CPU,是看不到右侧情况的,就需要考虑如何再合并的问题
//那么就在infect的过程中记录每一个点是由哪一个点感染来的,以及他的下标(尤其是边界点的,受感染的点)
//这样经过两个CPU的处理之后,就会得到至少两个岛屿的并查集情况
//合并:再找个CPU处理边界情况
// 通过遍历切割线左右两侧受感染的点,如果相连但是不在统一集合就进行Union操作,集合数--
//直到结束