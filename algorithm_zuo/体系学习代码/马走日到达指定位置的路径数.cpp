#include<iostream>
#include<vector>
using namespace std;
class HorseJump
{
public:
	//默认是从(0,0)位置一开始跳
	int getWays(int x, int y, int step)
	{
		return process1(x,y,step);
	}
	int process1(int x,int y,int step)
	{
		if (x < 0 || x>8 || y < 0 || y>9)//象棋9行10列
			return 0;
		if (step == 0)
			return (x == 0 && y == 0) ? 1 : 0;//还有step=0步,目标值是(0,0)不用跳,就可1
		else
		{
			//走到(x,y)的八个方位时,就可以一步直接到达
			//从目标位置往回找,不同方向来,路径肯定不同
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

	//目标值是step高度层的某一个位置的值
	//step只和他下一层的有关,那么我们可以动step=0的第一层推出第二层...
	//同一层之间是没有依赖关系的,所以xy怎么循环次序调换都无所谓
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