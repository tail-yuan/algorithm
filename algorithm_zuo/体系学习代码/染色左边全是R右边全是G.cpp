#include<iostream>
#include<vector>
using namespace std;
//预处理
class PaintColor
{
public:
	//O(n^2)每次到达一个位置都需要遍历一遍
	//优化:使用额外空间记录频繁进行的操作
	//即[0,i]位置有多少个G->R,[i+1,N-1]有多少个R->G
	//两个数组分别记录,然后直接取值即可O(N)
	int minPaintTest(string& s)
	{
		int n = s.size();
		int ret = 0;
		for(int i=0;i<n;i++)
		{
			if (i == 0)
			{
				//arr[0...n-1]一共多少个G->R
			}
			else if (i == n - 1)
			{
				//arr[0...n-1]一共多少个R->G
			}
			else
			{
				//arr[0,i]一共多少个G->R + arr[i+1...n-1]一共多少个R->G
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