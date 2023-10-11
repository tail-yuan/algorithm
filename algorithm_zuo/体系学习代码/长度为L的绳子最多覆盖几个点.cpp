#include<iostream>
#include<vector>
using namespace std;
// ̰��:û�б�Ҫ�����������յ㲻�ڵ���,ѡ��һ����Ϊ�߽�
//��1. ��ĳһ����Ϊ�����Ҳ��յ���ǰ,�ҵ�left���ұߵ������arr[i]�е�λ��,�±������Ϊret.
// O(N*logN)
//��2: ���ڲ�����˼��,ѡ��index��Ϊ��߽�,�ҵ���index��߽翪ʼ��������չ���ĸ���,ȷ�������ڽڵ�������.
// O(N)
class CordCoverMaxPoint
{
public:
	//��arr[0..R]��Χ�ϣ�������>=value������λ��
	//���ֲ��� O(logN)
	int nearestIndex(vector<int>& arr, int R, int val)
	{
		int L = 0;
		int index = R;
		while (L < R)
		{
			int mid = L + ((R - L) >> 1);
			if (arr[mid] >= val)
			{
				index = mid;
				R = mid - 1;
			}
			else
				L = mid + 1;
		}
		return index;
	}
	int maxPoint(vector<int>& arr, int L)
	{
		int res = 1;
		//O(N)
		for (int i = 0; i < arr.size(); i++)
		{
			int nearest = nearestIndex(arr,i,arr[i]-L);
			res = max(res,i-nearest+1);
		}
		return res;
	}

};