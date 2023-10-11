#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//���ջ������ʱ����İ��Ż����õ����Ž�,������ల�Ŷ��ٸ�����
//1. �Ȱ��ս���ʱ������
//2. �ҵ�����ʱ��û��ʼ�Ļ���(�����)����
class Program
{
public:
	int start;
	int end;
	Program(int s=0,int e=0)
	{
		start = s;
		end = e;
	}
};
struct Greater
{
	bool operator()(const Program& p1, const Program& p2)
	{
		return p1.end < p2.end;//������
	}
};
int bestArray(vector<Program>& arr, int time)//time�Ǵ����ĳʱ�̿�ʼ����
{
	sort(arr.begin(), arr.end(), Greater());
	int res = 0;
	for (int i = 0; i < arr.size(); i++)
	{
		if (time < arr[i].start)
		{
			res++;
			time = arr[i].end;
		}
	}
	return res;
}