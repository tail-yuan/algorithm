//https://www.bilibili.com/video/BV1NV4y1B7ZZ?p=28&vd_source=cc945ef88574fe2db5e814c0c265a4c7
//https://leetcode.cn/problems/shortest-bridge/submissions/
// ����������Ƭ1,�������Ƭ1�������������·���Ƕ೤,���Ҫ��ͨ���ٸ���λ?
// �ڹ㲥�Ĺ����н���һƬ1��Ϊ����0,
//ÿһƬ1����Ϊһ������,����BFS,���Ի�ȡһ��һ�������,���б��,�㲥������λ��,
//  ��������tmp[i][j]�������λ�õ������ĵĲ���������.
//��һƬ1Ҳ��Ϊһ������,����BFS,���ۻ�ȡһ�������,ʵ���ø�������tmp2���б�Ǿ���.
//����������ÿһƬ1�Լ����Լ��ľ���,���Լ����ĵĲ������Ϊ1, //1
//�������������������Ӧλ��,�ҵ�min_path= tmp1[i][j]+tmp2[i][j]��Сֵ�ĵ�������·���м��,
//���·������min_path-3,��Ϊ�������ظ��Ĳ���,��Ϊ�����㽻�㴦.
//����ȥ3��Ϊ��.

//����ά�����Ϊһά����, index=i*����+j;Ŀ��������򵥵�����ṹ��¼�±�.�������Ҫqueue��Info��¼i,j
//�ڳ���ʱ���Ż�
	//	infect��������: ���þ����ҵ�ÿһƬ�������е�1,���ض��ٸ�1
	// ��i,jλ�ø�Ⱦ��ȥ,��ÿһ��1������ŵ�curs������,curs[index++]=i*M+j
	// record[index]=1,��¼i,jλ�����1���Լ�������ڶ�ά�����еľ�����1.//1
	// �����,curs�����м�¼����������е�1���±�,��������index��ֵ
// 
	//bfs���������Ǹ���curs[i],����һ������nexts������,records����������ʵ����һ��Ĳ���.
	//record[i]=1,����������1������Լ�Ϊ1,recors[i]=a,����iλ����ԭʼ��ά����������ĵĲ�����a
	// recors[i]=0,����δ�������ĵ�,����Ϊrecords[i]=L
	// ��ô�����һά�����и����±��ϵ���Ҷ�ά�����е���������λ��?
	//curs[i]=a,����Ϊ1�ĵ�ת��Ϊһά֮����±�Ϊa,a=i*n+j,
	//1. a�����Ԫ����ԭʼ��ά�����һ��: a/n==0;���һ��: a/n==m-1
	//2. a�����Ԫ����ԭʼ��ά�����һ��: a%n==0;���һ��: a%n==n-1
	// a/n!=0,���ڵ�һ��,�����Ͼ��� a-n ; �������һ��,�����¾���a+n
	// a%n!=0,���ڵ�һ��,���������a-1; �������һ��,�����Ҿ���a=1
#include<iostream>
#include<vector>
using namespace std;
class Solution
{
	int n, m;//mΪ��,nΪ��
	int all;
public:
	int shortestBridge(vector<vector<int>>& grid)
	{
		m = grid.size(), n = grid[0].size();
		all = n * m;
		vector<int>curs(all);
		vector<int>nexts(all);//�¼�����
		vector<vector<int>>records(2, vector<int>(all));//��Ƭ1
		int isLands = 0;
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (grid[i][j] == 1)
				{
					//1. �õ���������е�1,����queueSize���±���curs������
					int queueSize = infect(grid, i, j, curs, 0, records[isLands]);
					int L = 1;
					//2. ��ÿһ��curs[i]bfs�㲥�ҵ���һ������е�,�������ǵ�records[p]=2
					while (queueSize != 0)
					{
						L++;
						queueSize = bfs(L, curs, queueSize, nexts, records[isLands]);
						//3. ����curs��nexts,ʼ��ʵ��curs->nexts,�����ҵ���һ��
						swap(curs, nexts);
					}
					isLands++;
				}
			}
		}
		int ans=INT_MAX;
		for (int i = 0; i < all; i++)
			ans = min(ans, records[0][i] + records[1][i]);
		return ans-3;
	}

	int bfs(int L, vector<int>& curs, int qs, vector<int>& nexts, vector<int>& record)
	{
		int nexti = 0;
		for (int i = 0; i < qs; i++)
		{
			int a = curs[i];
			int up = a < n ? -1 : a - n;
			int down = a + n >= all ? -1 : a + n;
			int left = a % n == 0 ? -1 : a - 1;
			int right = a % n == n - 1 ? -1 : a + 1;
			if (up != -1 && record[up] == 0)
			{
				record[up] = L;
				nexts[nexti++] = up;
			}
			if (down != -1 && record[down] == 0)
			{
				record[down] = L;
				nexts[nexti++] = down;
			}
			if (left != -1 && record[left] == 0)
			{
				record[left] = L;
				nexts[nexti++] = left;
			}
			if (right != -1 && record[right] == 0)
			{
				record[right] = L;
				nexts[nexti++] = right;
			}
		}
		return nexti;
	}
	int infect(vector<vector<int>>& grid, int i, int j, vector<int>& curs, int index, vector<int>& record)
	{
		if (i < 0 || i == m || j < 0 || j == n || grid[i][j] != 1)
			return index;
		grid[i][j] = 2;//
		int p = i * n + j;
		record[p] = 1;
		curs[index++] = p;
		index = infect(grid, i - 1, j,  curs, index, record);
		index = infect(grid, i + 1, j,  curs, index, record);
		index = infect(grid, i, j - 1,  curs, index, record);
		index = infect(grid, i, j + 1,  curs, index, record);
		return index;
	}
};