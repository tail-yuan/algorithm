
#include<iostream>
#include<queue>
#include<vector>
using namespace std;

class getMaxValWin
{
public:
	//使用双端队列记录win窗口下最大值,指定win大小窗口并且每次移动一个,涉及到下标值的过期
	vector<int> getMax(vector<int>& arr, int win)
	{
		if (arr.size() < win || win < 1)return {};
		vector<int>ret(arr.size()-win+1);
		deque<int> qmax;
		for (int i = 0; i < arr.size(); i++)
		{
			//if(qmax.empty() || qmax.back() > arr[i]) qmax.push_back(arr[i])
			// 插入
			// while(!qmax.empty()|| qmax.back() <= arr[i]) qmax.pop_back();
			// qmax.push_back(arr[i]);
			// 弹完再插入
			// ->先搞能弹的,弹完再插入 不能弹也可直接走下面直接插
			//上述代码和下面逻辑一样,因为都设计插入,所以我们先考虑while弹出,再插入,这样可以节省空间
			while (!qmax.empty() && qmax.back() <= arr[i])
				qmax.pop_back();
			qmax.push_back(arr[i]);
			// 维持栈顶是最大完成了
			if (qmax.front() == i - win)//下标已经过期了
				qmax.pop_front();
			if (i >= win - 1)//形成窗口了
				ret.push_back(qmax.front());
		}
		return ret;

		//if (arr.size() < win || win < 1)return {};
		//deque<int> qmax;
		//vector<int>ret(arr.size() - win + 1);
		//int index = 0;
		//for (int i = 0; i < arr.size(); i++)
		//{
		//	while (!qmax.empty() && arr[i] >= qmax.back())
		//	{
		//		qmax.pop_back();
		//	}
		//	qmax.push_back(arr[i]);
		//	//此时队列头最大值下标已经过期
		//	if (qmax.front() == i - win) //i-win+1 正好是此时的窗口左边界
		//		qmax.pop_front();
		//	//在i逐个往后走的过程中,形成win大小窗口
		//	if (i >= win - 1)
		//		ret.push_back(qmax.front());
		//}
		//return ret;
	}
};