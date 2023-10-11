#include<iostream>
#include<queue>
#include<vector>
using namespace std;
//����������׼����յ�Ǯ�Ŀ������Ƕ���
//���ջ�Ǯ���������������
//����һ���ˣ��������֮ǰ����p�ˣ�����ǮΪ0Ԫ�Ľڵ�
//��֮ǰp����ÿ����|k|Ԫ��ki=-2��B=10,
//һ���ˣ�B=8Ԫ�������ˣ�B=6Ԫ�������ˣ�B=4Ԫ
//ÿ����һ���ˣ�����֮ǰ����ÿ��kԪ
//����ÿ������һ���ˣ���԰���ӵĴ������ǣ�
//k*(p+1)+B+k*p,
//�����������Ϊ0ʱ,ֹͣ����Ϊʣ�µ��˶���������
//��ÿ����Ŀ�������ֵ�ŵ�������У������ˣ��ĸ���Ŀ��õ�Ǯ������ڶѶ�
//������Ǯ����Ŀ������������Ѿ�=0�ˣ��ٶ��˱����Ϳ�ʼʡǮ��
//������Ǯ����Ŀ������������Ȼ>0,�����Ǯ����Ŀ���õ�����Ǯ������������֮���ٷŵ������
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
		priority_queue<Game,vector<Game>,Less<Game>> heap;//���ȼ����й��������
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