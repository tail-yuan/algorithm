//�ɿյغ�ǽ��ɵ��Թ�����һ�������������(u)��(d)��()��(r) �ĸ����������������ǽ��ǰ����ֹͣ������
//����ͣ��ʱ����ѡ����һ�������Թ��л���һ���������˶�������ʱ���ͻ��������
//���������ʼλ�ã�Ŀ�ĵغ��Թ����ҳ���������̾�����������·����
//����Ķ����������ʼλ��(������)��Ŀ�ĵ�(����)�����Ŀյظ�����
//ͨ��u d"��r�������ƶ�����
//���ڿ����ж������·����������ֵ�����С��·����
//������޷����붴�����"impossible"
//�Թ���һ��0��1�Ķ�ά�����ʾ��1��ʾǽ��0��ʾ�յء�
//����Լٶ��Թ��ı�Ե����ǽ�ڡ���ʼλ�ú�Ŀ�ĵص�����ͨ���кź��кŸ�����

//һ��������ȱ���,ûײ��ǽ�����������ķ���һ��һ����������ȥ,ģ��ײ��ǽ���ܷ���
//��Ҫ��¼����x,y��ʱ����Դ����,
//https://www.bilibili.com/video/BV1NV4y1B7ZZ?t=1539.2&p=72
//����һ��λ�ò����ظ�����,���Ǵ�ĳһ�����򵽴�ĳһ��λ�ò����ظ�
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
		int dir;// 0123�ֱ������������,4�����ʱ�޷���
		string path;
		Node(int r, int c, int d, string p)
			:row(r)
			, col(c)
			, dir(d)
			, path(p)
		{}
	};
	//��ά��������Թ�,һά�����֪ball��hole���ԵĶ�ά����
	string findShortestWay(vector<vector<int>>& maze, vector<int>& ball, vector<int>& hole)
	{
		n = maze.size(), m = maze[0].size();
		vector<Node>q1(n * m);//��¼��ǰ�����нڵ�
		vector<Node>q2(n * m);//��¼��չ��������һ������нڵ�
		visi = vector<vector<vector<bool>>>(n, vector<vector<bool>>(n, vector<bool>(4)));
		int s1 = 0, s2 = 0;//��¼����
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
			//�ռ临��,���µ���,����q2����һ��
			swap(q1, q2);
			s1 = s2;
			s2 = 0;
		}
		return "impossible";
	}
	int to[5][2] = { {0,-1},{-1,0},{0,1},{1,0} ,{0,0} };//���dir=4�����޷���
	vector<string>re = { "d","l","r","u" };
	int spread(vector<vector<int>>& maze, Node cur, vector<Node>& q, int s)
	{
		int d = cur.dir;
		int r = cur.row + to[d][0];
		int c = cur.col + to[d][1];
		//��Ҫ��4��������з���
		if (d == 4 || r < 0 || r == n || c < 0 || c == m || maze[r][c] != 0)
		{
			for (int i = 0; i < 4; i++)
			{
				if (i != d)//��������
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
		else//��������dir������
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
//��Ϊ��ĿҪ��С������һ�ξ���֮��,ֱ��ײ��ǽ��ͣ����,����һ�ξ���
//���Ի��ǰ���ԭ����������,�Ͳ���Ҫ��opt��¼.�����ײ��ǽ��,��Ҫ��¼��һ�ξ���
