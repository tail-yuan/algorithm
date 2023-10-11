#include<iostream>
#include<vector>
using namespace std;
class HorseJump
{
public:
	//Ĭ���Ǵ�(0,0)λ��һ��ʼ��
	int getWays(int x, int y, int step)
	{
		return process1(x,y,step);
	}
	int process1(int x,int y,int step)
	{
		if (x < 0 || x>8 || y < 0 || y>9)//����9��10��
			return 0;
		if (step == 0)
			return (x == 0 && y == 0) ? 1 : 0;//����step=0��,Ŀ��ֵ��(0,0)������,�Ϳ�1
		else
		{
			//�ߵ�(x,y)�İ˸���λʱ,�Ϳ���һ��ֱ�ӵ���
			//��Ŀ��λ��������,��ͬ������,·���϶���ͬ
			return process1(x-1,y+2,step-1);
				+  process1(x-2,y+1,step-1);
				+  process1(x-1,y-2,step-1);
				+  process1(x-2,y-1,step-1);
				+  process1(x+1,y+2,step-1);
				+  process1(x+1,y-2,step-1);
				+  process1(x+2,y+1,step-1);
				+  process1(x+2,y-1,step-1);
		}
	}

	//Ŀ��ֵ��step�߶Ȳ��ĳһ��λ�õ�ֵ
	//stepֻ������һ����й�,��ô���ǿ��Զ�step=0�ĵ�һ���Ƴ��ڶ���...
	//ͬһ��֮����û��������ϵ��,����xy��ôѭ���������������ν
	int getWays1(int x, int y, int step)
	{
		if (x < 0 || x>8 || y < 0 || y>9)
			return 0;
		vector<vector<vector<int> > > dp(9, vector<vector<int> >(10, vector<int>(step+1)));
		dp[0][0][0] = 1;
		for (int h = 1; h <= step; h++)
		{
			for (int r = 0; r < 9; r++)
			{
				for (int c = 0; c < 10; c++)
				{
					dp[r][c][h] = getValue(dp,r+1,c+2,h-1);
					dp[r][c][h] = getValue(dp,r+1,c-2,h-1);
					dp[r][c][h] = getValue(dp, r + 2, c + 1, h - 1);
					dp[r][c][h] = getValue(dp, r + 2, c - 1, h - 1);

					dp[r][c][h] = getValue(dp, r - 1, c + 2, h - 1);
					dp[r][c][h] = getValue(dp, r - 1, c - 2, h - 1);
					dp[r][c][h] = getValue(dp, r - 2, c + 1, h - 1);
					dp[r][c][h] = getValue(dp, r - 2, c - 1, h - 1);
				}
			}
		}
		return dp[x][y][step];
	}
	int getValue(vector<vector<vector<int> > >& dp, int x, int y, int h)
	{
		if (x < 0 || x>8 || y < 0 || y>9)
			return 0;
		return dp[x][y][h];	
	}
};