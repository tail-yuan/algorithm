//由空地和墙组成的迷宫中有一个球。球可以向上(u)下(d)左()右(r) 四个方向滚动但在遇到墙壁前不会停止滚动。
//当球停下时可以选择下一个方向。迷宫中还有一个洞当球运动经过洞时，就会掉进洞里
//给定球的起始位置，目的地和迷宫，找出让球以最短距离掉进洞里的路径。
//距离的定义是球从起始位置(不包括)到目的地(包括)经过的空地个数。
//通过u d"和r输出球的移动方向。
//由于可能有多条最短路径，请输出字典序最小的路径。
//如果球无法进入洞，输出"impossible"
//迷宫由一个0和1的二维数组表示。1表示墙壁0表示空地。
//你可以假定迷宫的边缘都是墙壁。起始位置和目的地的坐标通过行号和列号给出。

//一个宽度优先遍历,没撞到墙继续沿着来的方向一个一个格子走下去,模拟撞到墙才能分裂
//需要记录来到x,y点时的来源方向,
//https://www.bilibili.com/video/BV1NV4y1B7ZZ?t=1539.2&p=72
//不是一个位置不能重复进入,而是从某一个方向到达某一个位置不能重复
//bool visi[row][col][direction];
//
#include<iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;
class TheMazeIII
{
	vector<vector<vector<bool>>>visi;
	int n, m;
public:
	class Node
	{
	public:
		int row, col;
		int dir;// 0123分别代表上下左右,4代表此时无方向
		string path;
		Node(int r, int c, int d, string p)
			:row(r)
			, col(c)
			, dir(d)
			, path(p)
		{}
	};
	//二维数组代表迷宫,一维数组告知ball和hole各自的二维坐标
	string findShortestWay(vector<vector<int>>& maze, vector<int>& ball, vector<int>& hole)
	{
		n = maze.size(), m = maze[0].size();
		vector<Node>q1(n * m);//记录当前层所有节点
		vector<Node>q2(n * m);//记录拓展出来的下一层的所有节点
		visi = vector<vector<vector<bool>>>(n, vector<vector<bool>>(n, vector<bool>(4)));
		int s1 = 0, s2 = 0;//记录个数
		s1 = spread(maze, Node(ball[0], ball[1], 4, ""), q1, s1);
		while (s1 != 0)
		{
			for (int i = 0; i < s1; i++)
			{
				Node cur = q1[i];
				if (hole[0] == cur.row && hole[1] == cur.col)
					return cur.path;
				s2 = spread(maze, cur, q2, s2);
			}
			//空间复用,往下递推,更新q2即下一层
			swap(q1, q2);
			s1 = s2;
			s2 = 0;
		}
		return "impossible";
	}
	int to[5][2] = { {0,-1},{-1,0},{0,1},{1,0} ,{0,0} };//如果dir=4代表无方向
	vector<string>re = { "d","l","r","u" };
	int spread(vector<vector<int>>& maze, Node cur, vector<Node>& q, int s)
	{
		int d = cur.dir;
		int r = cur.row + to[d][0];
		int c = cur.col + to[d][1];
		//需要向4个方向进行分裂
		if (d == 4 || r < 0 || r == n || c < 0 || c == m || maze[r][c] != 0)
		{
			for (int i = 0; i < 4; i++)
			{
				if (i != d)//不往回走
				{
					r = cur.row + to[i][0];
					c = cur.col + to[i][1];
					if (r >= 0 && r < n && c >= 0 && c < m && maze[r][c] == 0 && !visi[r][c][d])
					{
						visi[r][c][d] = true;
						Node next = Node(r, c, i, cur.path + re[i]);//1
						q[s++] = next;
					}
				}
			}
		}
		else//继续沿着dir往下走
		{
			if (!visi[r][c][d])
			{
				visi[r][c][d] = true;
				q[s++] = Node(r, c, d, cur.path);//1
			}
		}
		return s;
	}
};
//1. 
//因为题目要求小球做出一次决策之后,直到撞到墙才停下来,再做一次决策
//所以还是按照原来方向来的,就不需要将opt记录.如果是撞到墙了,需要记录下一次决策
