
#include<iostream>
#include<queue>
#include<vector>
using namespace std;

class getMaxValWin
{
public:
	//ʹ��˫�˶��м�¼win���������ֵ,ָ��win��С���ڲ���ÿ���ƶ�һ��,�漰���±�ֵ�Ĺ���
	vector<int> getMax(vector<int>& arr, int win)
	{
		if (arr.size() < win || win < 1)return {};
		vector<int>ret(arr.size()-win+1);
		deque<int> qmax;
		for (int i = 0; i < arr.size(); i++)
		{
			//if(qmax.empty() || qmax.back() > arr[i]) qmax.push_back(arr[i])
			// ����
			// while(!qmax.empty()|| qmax.back() <= arr[i]) qmax.pop_back();
			// qmax.push_back(arr[i]);
			// �����ٲ���
			// ->�ȸ��ܵ���,�����ٲ��� ���ܵ�Ҳ��ֱ��������ֱ�Ӳ�
			//��������������߼�һ��,��Ϊ����Ʋ���,���������ȿ���while����,�ٲ���,�������Խ�ʡ�ռ�
			while (!qmax.empty() && qmax.back() <= arr[i])
				qmax.pop_back();
			qmax.push_back(arr[i]);
			// ά��ջ������������
			if (qmax.front() == i - win)//�±��Ѿ�������
				qmax.pop_front();
			if (i >= win - 1)//�γɴ�����
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
		//	//��ʱ����ͷ���ֵ�±��Ѿ�����
		//	if (qmax.front() == i - win) //i-win+1 �����Ǵ�ʱ�Ĵ�����߽�
		//		qmax.pop_front();
		//	//��i��������ߵĹ�����,�γ�win��С����
		//	if (i >= win - 1)
		//		ret.push_back(qmax.front());
		//}
		//return ret;
	}
};