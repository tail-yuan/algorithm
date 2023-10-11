//https://www.bilibili.com/video/BV1NV4y1B7ZZ?p=28&vd_source=cc945ef88574fe2db5e814c0c265a4c7
//https://leetcode.cn/problems/shortest-bridge/submissions/
// 矩阵中有两片1,求解让两片1连接起来的最短路径是多长,最短要打通多少个单位?
// 在广播的过程中将另一片1认为都是0,
//每一片1都作为一个中心,采用BFS,可以获取一层一层的数据,进行标记,广播到所有位置,
//  辅助数组tmp[i][j]代表这个位置到达中心的层数即距离.
//另一片1也作为一个中心,采用BFS,理论获取一层层数据,实际用辅助数组tmp2进行标记距离.
//辅助数组中每一片1自己到自己的距离,即自己中心的层数标记为1, //1
//最后遍历两个辅助数组对应位置,找到min_path= tmp1[i][j]+tmp2[i][j]最小值的点就是最短路径中间点,
//最短路径就是min_path-3,因为存在算重复的部分,因为是两层交点处.
//最后减去3即为答案.

//将二维数组变为一维数组, index=i*列数+j;目的是用最简单的数组结构记录下标.否则得需要queue和Info记录i,j
//在常数时间优化
	//	infect函数作用: 作用就是找到每一片岛的所有的1,返回多少个1
	// 从i,j位置感染出去,把每一个1的坐标放到curs数组中,curs[index++]=i*M+j
	// record[index]=1,记录i,j位置这个1到自己这个岛在二维矩阵中的距离是1.//1
	// 到最后,curs数组中记录着这个岛所有的1的下标,个数就是index的值
// 
	//bfs函数作用是根据curs[i],将下一层点放入nexts数组中,records数组来辅助实现下一层的查找.
	//record[i]=1,代表岛屿中心1点距离自己为1,recors[i]=a,代表i位置再原始二维矩阵距离中心的层数是a
	// recors[i]=0,代表未被开发的点,更新为records[i]=L
	// 那么如何在一维数组中根据下标关系查找二维矩阵中的上下左右位置?
	//curs[i]=a,代表为1的点转化为一维之后的下标为a,a=i*n+j,
	//1. a代表的元素在原始二维矩阵第一行: a/n==0;最后一行: a/n==m-1
	//2. a代表的元素在原始二维矩阵第一列: a%n==0;最后一列: a%n==n-1
	// a/n!=0,不在第一行,他的上就是 a-n ; 不在最后一行,他的下就是a+n
	// a%n!=0,不在第一列,他的左就是a-1; 不在最后一列,他的右就是a=1
#include<iostream>
#include<vector>
using namespace std;
class Solution
{
	int n, m;//m为行,n为列
	int all;
public:
	int shortestBridge(vector<vector<int>>& grid)
	{
		m = grid.size(), n = grid[0].size();
		all = n * m;
		vector<int>curs(all);
		vector<int>nexts(all);//下级队列
		vector<vector<int>>records(2, vector<int>(all));//两片1
		int isLands = 0;
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (grid[i][j] == 1)
				{
					//1. 得到这个岛所有的1,个数queueSize和下标在curs数组中
					int queueSize = infect(grid, i, j, curs, 0, records[isLands]);
					int L = 1;
					//2. 从每一个curs[i]bfs广播找到下一层的所有点,并将他们的records[p]=2
					while (queueSize != 0)
					{
						L++;
						queueSize = bfs(L, curs, queueSize, nexts, records[isLands]);
						//3. 交换curs和nexts,始终实现curs->nexts,交替找到下一层
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