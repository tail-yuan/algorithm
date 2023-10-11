//��һ���̶��ռ���,�����õ�·�������������ɨ���
//�����˿���ͨ������move()��֪̽��һ���ܲ�����
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
		//�����һ��λ�ÿɴ�,ǰ��������true,���ִܵﷵ��false
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
	//dirָ���Ǵ�ʱ����������ʲô����,0 1 2 3
	//clean�������ò��ظ�����visi�е�λ��,�ѷ�����ʣ��Ķ���ɨ�ɾ���ͬʱ
	//		�ָ�ԭ��״̬
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
			// ��һ���ķ���ʵ��˳ʱ�����
			int nd = (dir + i) % 4;
			int nx = ds[nd][0] + x;
			int ny = ds[nd][1] + y;
			if (!hashSet.count(to_string(nx) + "_" + to_string(ny)) && r.move())
				clean(r, nx, ny, nd);
			r.turnRight();
		}
		//������nx,nyһȦ֮��,�����˻ص�x,yλ�ò����ֳ�ʼ����
		r.turnRight();
		r.turnRight();
		r.move();
		r.turnRight();
		r.turnRight();
	}
};