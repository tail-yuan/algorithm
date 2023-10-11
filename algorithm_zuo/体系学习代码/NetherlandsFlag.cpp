#include<iostream>
#include<vector>
using namespace std;
class NetherlandsFlag
{
public:
	//1. [i]<num [i]��less�����ұߵ����ֽ���,less��������,i++
	//2. [i]>num [i]��more������ߵ����ֽ���,more��������,i����,��Ϊ��ʱiλ��ֵ�Ǹս���������,����֪����ɶֵ
	//3. [i]==num[i],i++����,������������
	//��̬�۲����less��������==�������Ҽ�ѹ��������ӽ�more����,��֮��Ȼ.
	//�����?�����������(��)��ֵ��[i](<num)����,Ȼ��i++,ʵ�ֵ�,��֮��Ȼ.
	pair<int,int> partition(vector<int>& arr,int l,int r,int p)
	{
		int less = l-1;
		int more = r + 1;
		while (l<more)
		{
			if (arr[l] < p)
			{
				swap(arr[l], arr[less + 1]);
				less++;
				l++;
			}
			else if (arr[l] > p)
			{
				swap(arr[l], arr[more - 1]);
				more--;
			}
			else
			{
				l++;
			}
		}
		return std::make_pair(less+1,more-1);//�����м�=�������߽���ұ߽�
	}
};