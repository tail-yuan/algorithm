#include<iostream>
#include<queue>
#include<vector>
using namespace std;
//考虑最坏情况：准备最保险的钱的可能性是多少
//按照花钱最多的情况报名考虑
//新来一个人，考虑相比之前人数p人，再挣钱为0元的节点
//回之前p个人每个人|k|元，ki=-2，B=10,
//一个人，B=8元，两个人，B=6元，三个人，B=4元
//每新来一个人，返还之前的人每人k元
//所以每再新来一个人，公园增加的纯收入是：
//k*(p+1)+B+k*p,
//当这个纯收入为0时,停止，认为剩下的人都不报名。
//将每个项目最大消耗值放到大根堆中，再来人，哪个项目获得的钱数多就在堆顶
//当最挣钱的项目再来人收入就已经=0了，再多人报名就开始省钱了
//当最挣钱的项目再来人收入仍然>0,弹出最花钱的项目，得到花的钱数，人数增加之后再放到大堆中
class Game
{
public:
	Game(int k,int b)
		:ki(k)
		,Bi(b)
		,people(0)
	{
	}
	int Earn()
	{
		return (ki*(people+1)+Bi)+ki*people;
	}
	bool operator>(Game b)
	{
		return Earn()>b.Earn();
	}
public:
	int ki;
	int Bi;
	int people;
};
template<class T>
struct Less
{
	bool operator()(Game& g1, Game& g2)const 
	{
		return g1.Earn() > g2.Earn();
	}
};
class Solution
{
public:
	int GroupBuyTickets(int n,vector<vector<int>>&games)
	{
		priority_queue<Game,vector<Game>,Less<Game>> heap;//优先级队列构建大根堆
		for (auto& g : games)
		{
			heap.push(Game(g[0],g[1]));
		}
		int ans = 0;
		for (int i = 0; i < n; i++)
		{
			Game topGame = heap.top();
			if (topGame.Earn() <= 0)
			{
				break;
			}
			ans += topGame.Earn();
			heap.pop();
			topGame.people++;
			heap.push(topGame);
		}
		return ans;
	}
};
//template<class T>
//struct Greater
//{
//	bool operator()(T& g1, T& g2)
//	{
//		return g1.Earn() > g2.Earn();
//	}
//};
//int main()
//{
//	//priority_queue<int,vector<int>,greater<int>> heap;
//	priority_queue<Game,deque<Game>, Greater<Game>> heap;
//	Game g1(-2,1);
//	heap.push(g1);
//	cout << g1.Earn() << endl;
//	Game g2(-3, 6);
//	heap.push(g2);
//	cout << g2.Earn() << endl;
//
//	Game g3(-4, 4);
//	heap.push(g3);
//	cout << g3.Earn() << endl;
//
//	return 0;
//}