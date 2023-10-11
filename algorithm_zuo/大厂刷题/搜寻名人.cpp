
//明星: 所有人都认识我,但是我不认识别人
//给定函数know(i,j),表示i位置的人是否认识j
//返回明星的编号,如果没有返回-1

//提供know(x,y)函数,返回x是否认识y,如果x认识y,那么y就是候选明星,如果x不认识y,那么y肯定不是明星候选
//得到明星候选之后,验证cand是否不认识所有人
//肯定不认识后面的人,
// 所以需要验证左侧人他是否都不认识
//是否所有人都认识cand
class Solution
{
	//给定know函数,不用我们自己实现
	bool know(int x, int y)
	{
		return true;
	}
public:
	int findCelebrity(int n)
	{
		int cand = 0;
		for (int i = 0; i < n; i++)
		{
			if (know(cand, i))
				cand = i;
		}
		//cand位置就是右侧区间确定的明星候选人
		//左侧的人明星是否都不认识
		for (int i = 0; i < cand; i++)
		{
			if (know(cand,i))
				return -1;
		}
		//所有人是否都认识cand
		for (int i = 0; i < n; i++)
		{
			if (!know(i, cand))
				return -1;
		}
		return cand;
	}
};