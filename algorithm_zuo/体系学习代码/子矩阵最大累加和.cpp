
//���:����һ�����;��󣬷����Ӿ��������ۼƺ�;
//����:Ҳ���������������⻭һ��m*n�ľ���,���������ۼӺ;�������.
//ѹ������
// �뷨:�����������������ۼӺ͵ķ���opt,��ô���ʵ�����о�������ı��� ����Ӧ��opt������?
// 1. ����: 0~0   һ�� ,ֱ��Ӧ��opt
//			0~1   ���� ,�������ж�Ӧ�±�����ۼ�->tmp[]����,Ӧ��opt
//			0~1~2 ���� ,�������ж�Ӧ�±�����ۼ�->tmp[]����,Ӧ��opt
//			1~1   һ�� ,...
//			1~2   ����
//			2~2   һ��
//          ......
// ÿһ�����һ��maxSum,Ȼ������������maxSum���бȽϵõ�����ֵ
//
#include<iostream>
#include<vector>
using namespace std;
class SubMatrixMaxSum
{
public:
	int maxSum(vector<vector<int>>& m)
	{
		if (m.size() == 0 || m[0].size() == 0)
			return 0;
		int maxSum = INT_MIN;
		int cur = 0;
		vector<int>tmp(m[0].size());
		for (int i = 0; i < m.size(); i++)//i��������п�ʼ����start
		{
			for (int j = i; j < m.size(); j++)//j�Ǵ�i��ʼ���µ���һ��end
			{
				cur = 0;
				for (int k = 0; k < tmp.size(); k++)//opt
				{
					tmp[k] += m[j][k];//ʵ��ѹ�������Ч��,j=0:tmp��¼�ľ͵���һ��;j=2tmp��¼�ľ����е��ۼӺ�
					cur += tmp[k];
					maxSum = max(maxSum,cur);
					cur = cur < 0 ? 0 : cur;
				}
			}
		}
		return maxSum;
	}
};