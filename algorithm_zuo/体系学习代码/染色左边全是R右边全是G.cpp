#include<iostream>
#include<vector>
using namespace std;
//Ԥ����
class PaintColor
{
public:
	//O(n^2)ÿ�ε���һ��λ�ö���Ҫ����һ��
	//�Ż�:ʹ�ö���ռ��¼Ƶ�����еĲ���
	//��[0,i]λ���ж��ٸ�G->R,[i+1,N-1]�ж��ٸ�R->G
	//��������ֱ��¼,Ȼ��ֱ��ȡֵ����O(N)
	int minPaintTest(string& s)
	{
		int n = s.size();
		int ret = 0;
		for(int i=0;i<n;i++)
		{
			if (i == 0)
			{
				//arr[0...n-1]һ�����ٸ�G->R
			}
			else if (i == n - 1)
			{
				//arr[0...n-1]һ�����ٸ�R->G
			}
			else
			{
				//arr[0,i]һ�����ٸ�G->R + arr[i+1...n-1]һ�����ٸ�R->G
			}
		}
		return ret;
	}
	int minPaint(string& s)
	{
		int n = s.size();
		if (n == 0)
			return 0;
		vector<int>right(n);
		right[n - 1] = s[n - 1] == 'R' ? 1 : 0;
		for (int i = n - 2; i >= 0; i--)
			right[i] = right[i + 1] + (s[i] == 'R' ? 1 : 0);
		int res = right[0];
		int left = 0;
		for (int i = 0; i < n - 1; i++)
		{
			left += s[i] == 'G' ? 1 : 0;
			res = min(res,left+right[i+1]);
		}
		res = min(res,left+(s[n-1]=='G'?1:0));
		return res;
	}
};