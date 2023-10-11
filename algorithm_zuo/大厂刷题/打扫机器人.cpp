//在一个固定空间内,求出最经济的路径将整个区域打扫完成
//机器人可以通过函数move()来探知下一步能不能走
//https://www.bilibili.com/video/BV1NV4y1B7ZZ/?p=74&spm_id_from=pageDriver&vd_source=cc945ef88574fe2db5e814c0c265a4c7

#include<iostream>
#include <vector>
#include <algorithm>
#include<string>
#include<unordered_map>
#include<unordered_set>
using namespace std;
class RobotRoomCleaner
{
public:
	class Robot
	{
	public:
		//如果下一个位置可达,前进并返回true,不能抵达返回false
		bool move() {}
		void turnLeft() {}
		void turnRight() {}
		void clean() {}
	};
public:
	unordered_set<string>hashSet;
	void cleanRoom(Robot& r)
	{
		clean(r,0,0,0);
	}
	//dir指的是此时机器人脸冲什么方向,0 1 2 3
	//clean函数作用不重复的走visi中的位置,把方向下剩余的都打扫干净的同时
	//		恢复原来状态
	int ds[4][2] = { {-1,0},{0,1},{1,0},{0,-1} };
	void clean(Robot& r, int x, int y, int dir)
	{
		r.clean();
		hashSet.insert(to_string(x)+"_"+to_string(y));
		for (int i = 0; i < 4; i++)
		{
			// d = 0 :  0 1 2 3
			// d = 1 :  1 2 3 0
			// d = 2 :  2 3 0 1
			// d = 3 :  3 0 1 2
			// 下一步的方向！实现顺时针操作
			int nd = (dir + i) % 4;
			int nx = ds[nd][0] + x;
			int ny = ds[nd][1] + y;
			if (!hashSet.count(to_string(nx) + "_" + to_string(ny)) && r.move())
				clean(r, nx, ny, nd);
			r.turnRight();
		}
		//处理完nx,ny一圈之后,别忘了回到x,y位置并保持初始方向
		r.turnRight();
		r.turnRight();
		r.move();
		r.turnRight();
		r.turnRight();
	}
};