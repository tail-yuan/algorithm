//��һ��������,ֻ����01��������,1���������
//��Ҫ�����ǽ����е��˻�۵�һ�㿪��ʱ��������С�����Ƕ���
//ÿ����ֻ�ܺ��Ż���������,����ÿ��һ�����Ӹ����Ĵ�����1


//���:
//��Ϊֻ������������,ȷ�ϵ�ĳһλ��ת��Ϊȷ�ϵ�ĳһ��,ĳһ��,�����һ�������������С���۵�
//�ȿ�����,�ҵ���������1��۵�ĳһ��ʱ����С����ʱ����,
//�ٿ�����,�ҵ��������л�۵�ĳһ��ʱ����С���۵���,���㼴����
//������ͳ���ƶ���1�ĸ���
// 
//��ô��β�����������һ����? ���ҵĹ�����ʵ�����ų��Ĺ���,
//���ǿ��Լ���ȫ�ƶ���x�д�����sumx,ȫ�ƶ�������һ�д�����sumy,���sumx>sumy,�ȿ���
//�ų�x�п϶���������.
// 
//˼���˽�,��ô��ô���������ϵ�1,ȫ���ƶ���x�м��������?
//x�н������Ϊ��������������,�ϲ������е��ۼӵ�1�ĸ���up,�²������е��ۼ�1�ĸ�����down
//���������ƶ���xֻ��Ҫ,up+down��ÿ���ƶ�ʱ��Ҫ���ϵ�ֵ
//https://www.bilibili.com/video/BV1NV4y1B7ZZ?t=578.4&p=66

#include<iostream>
#include<vector>
using namespace std;
class Solution
{
public:
	int BestMeetingPoint(vector<vector<int>>& arr)
	{
		int n = arr.size();
		int m = arr[0].size();
		vector<int>iOnes(n);
		vector<int>jOnes(m);
		//ͳ��i��,j�зֱ���ٸ�1
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (arr[i][j] == 1)
				{
					iOnes[i]++;
					jOnes[j]++;
				}
			}
		}
		int total = 0;
		int i = 0;
		int j = n - 1;
		int iRest = 0, jRest = 0;
		while (i < j)
		{
			if (iOnes[i] + iRest <= iOnes[j] + jRest)
			{
				total += iOnes[i] + iRest;
				iRest += iOnes[i++];
			}
			else
			{
				total += iOnes[j] + jRest;
				jRest += iOnes[j--];
			}
		}
		i = 0; j = m - 1;
		iRest = 0, jRest = 0;
		while (i < j)
		{
			if (jOnes[i] + iRest <= jOnes[j] + jRest)
			{
				total += jOnes[i] + iRest;
				iRest += jOnes[i++];
			}
			else
			{
				total += jOnes[j] + jRest;
				jRest+=jOnes[j--];
			}
		}
		return total;
	}
};