#include<iostream>
#include<vector>
using namespace std;

//��������Ͻǿ�ʼ��
//��չ: ����涨��ά����ֻ��01,���ұ�֤0һ����1�����,����һ��ȫΪ0,����1
//��:���1 ����һ��?
// Ҳ�Ǵ����Ͻǿ�ʼ,��һ��һֱ������,ֱ��indexλ��,����1,��¼<����,�к�>
// ����һ��,indexλ���Ƿ�Ϊ1,�����Ƿ���������,Yes->����<����,�к�>,No->������һ��
// ֱ�����һ��,��������1���к�(�����кü�����ȸ�����)
class isContain
{
public:
	bool isContainNum(vector<vector<int>>& arr,int x)
	{
		int row = 0;
		int col = arr[0].size()-1;
		while (row < arr.size() && col >= 0)
		{
			if (x > arr[row][col])
				row++;
			else if (x < arr[row][col])
				col--;
			else
				return true;
		}
		return false;
	}
};