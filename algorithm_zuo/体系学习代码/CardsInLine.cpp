#include<iostream>
#include<string>
#include<vector>
using namespace std;

//���˽�����,����������һ��,��ôʣ�µĲ��־�������Ϊ�����õ�
class CardsInLine
{
public:
	int win1(vector<int>& arr)
	{
		if (arr.size() == 0)
			return 0;
		return max(f(arr,0,arr.size()-1),s(arr,0,arr.size()-1));
	}
	//����,ѡiλ��,ʣ��[i+1,j]��������Ϊ����ѡ,ѡjλ��ʣ��[i,j-1]λ��,ѡ���������ֵ
	int f(vector<int>& arr, int i, int j)
	{
		if (i == j)
			return arr[i];
		return max(arr[i] + s(arr, i + 1, j), arr[j] + s(arr, i, j - 1));
	}
	//����ѡʣһ���Ļ�,����û��ѡ��,��0
	//ʣ�µľ�������ѡ���,�϶��ǽ�Сֵ
	int s(vector<int>& arr, int i, int j)
	{
		if (i == j)
			return 0;
		return min(f(arr,i+1,j),f(arr,i,j-1));
	}
};