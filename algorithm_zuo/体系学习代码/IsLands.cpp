#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;
//O(N*M) 
//������ʱ��,ÿһ������һ��,�ݹ��ʱ��ÿһ����ֻ���ܱ��������Ҹ���һ��4��

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
//���ڴ��CPU
//������һ�������㷨����������?
//���������ʱ����漰��������з�,�����һ�뽻��һ��CPU,�ǿ������Ҳ������,����Ҫ��������ٺϲ�������
//��ô����infect�Ĺ����м�¼ÿһ����������һ�����Ⱦ����,�Լ������±�(�����Ǳ߽���,�ܸ�Ⱦ�ĵ�)
//������������CPU�Ĵ���֮��,�ͻ�õ�������������Ĳ��鼯���
//�ϲ�:���Ҹ�CPU����߽����
// ͨ�������и������������ܸ�Ⱦ�ĵ�,����������ǲ���ͳһ���Ͼͽ���Union����,������--
//ֱ������