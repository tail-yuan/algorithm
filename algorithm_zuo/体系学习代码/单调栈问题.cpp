#include<iostream>
#include<vector>
#include<stack>
#include<list>
using namespace std;
//�ҵ�����������λ��i,arr[i]���ұ������,�����������������
// ���ظ�ֵ
// ������Ľϴ��ֵ,ѡ��ջ,Լ��ջ�׵�ջ���ǴӴ�С��˳��
// ������Ľ�С��ֵ,ѡ��ջ,Լ��ջ�׵�ջ���Ǵ�С�����˳��
// 1. �����ջ��Ԫ��С�ͽ�ջ
// 2. ���cur��ջ��Ԫ��x��,����ջ��Ԫ��x,��߱�x��������ֵ������ѹ�ŵ���,cur�������ұ�����ı������ֵ
// ���ظ�ֵ
// stack<list<int>>ѹ��ջ��Ԫ������ֵͬ���±�������,����ͬ��(�����������һ��ֵ,��Ϊ������ʱ�����push_back)

//��Сֵ
vector<vector<int, int>> getNearLessNoRepeat(vector<int>& arr)
{
	vector<vector<int, int>>res;
	stack<int>st;
	for (int i = 0; i < arr.size(); i++)
	{
		//ά�ֵ׵����Ǵ�С�����˳��
		while (!st.empty() && arr[st.top()] > arr[i])
		{
			int popIndex = st.top(); st.pop();
			int leftLessIndex = st.empty() ? -1 : st.top(); 
			res[popIndex][0] = leftLessIndex;
			res[popIndex][1] = i;
		}
		st.push(i);
	}
	//���ջ�л���Ԫ��,˵���Ǵ�С�����,û���ұ߱���С��ֵ-1
	//ѹ�ŵľ�������ı���С��ֵ
	while (!st.empty())
	{
		int popIndex = st.top(); st.pop();
		int leftLessIndex = st.empty() ? -1 : st.top();
		res[popIndex][0] = leftLessIndex;
		res[popIndex][1] = -1;
	}
	return res;
}


//��Сֵ
vector<vector<int, int>> getNearLessNoRepeat(vector<int>& arr)
{
	vector<vector<int, int>>res;
	stack<vector<int>>st;//��arr[i]ֵ��ͬ��,Ҳ�����ظ�ֵ�ŵ�ͬһ��������,������Ͷ��ٸ��ظ�ֵ
	for (int i = 0; i < arr.size(); i++)
	{
		int index = st.top()[0];
		while (!st.empty() && arr[index] > arr[i])
		{
			vector<int> popIs = st.top(); st.pop();//��������ֵ����
			int leftLessIndex = st.empty() ? -1 : st.top()[st.top().size() - 1];
			//��������ֵ����¼һ�����������Сֵ
			for (int popi : popIs)
			{
				res[popi][0] = leftLessIndex;
				res[popi][1] = i;
			}
		}
		//���������һ����ֵͬ
		if (!st.empty() && arr[st.top()[0]] == arr[i])
			st.top().push_back(i);//�����д�ŵĶ�����ֵͬ���±�
		else//����һ����ֵ,����ջΪ��
		{
			vector<int>tmp;
			tmp.push_back(i);
			st.push(tmp);
		}
		//����Ǳ�ڵ�ʣ������,һ���Ǵ�С�����
		while (!st.empty())
		{
			vector<int> popIs = st.top(); st.pop();//��������ֵ����
			int leftLessIndex = st.empty() ? -1 : st.top()[st.top().size() - 1];
			//��������ֵ����¼һ�����������Сֵ
			for (int popi : popIs)
			{
				res[popi][0] = leftLessIndex;
				res[popi][1] = -1;
			}
		}
		return res;
	}
}