#include<iostream>
using namespace std;
//题干: 字符串中只有. 和X 两种字符,X 代表的是墙,要想将所有的点全部点亮,至少要多少个灯.每个灯只能影响左中右三个位置
//思路: 1. 如果i位置是X,不需要灯,index++
//		2. 如果i位置是.,肯定要放灯,index的变化范围决定放灯在哪里
//			2.1 如果i+1位置是X,那么在i位置就放灯,index+=2
//			2.2 如果i+1位置是.就在i+1位置放灯,贪心的想法,i+1位置就可以影响i i+1 i+2 三个位置,影响范围更靠后,index+=3
//当来到i位置时,一定保证之前的灯不会影响到i位置(不要考虑自己这个位置是否已经被照亮).index下标范围控制
class LightPoints
{
public:
	int getMin(string& str)
	{
		if (str.size() == 0)return 0;
		int ans = 0;
		int index = 0;
		while (index < str.size())
		{
			if (str[index] == 'X') index++;
			else
			{
				ans++;
				if (index + 1 == str.size())break;
				else
				{
					if (str[index + 1] == 'X') index += 2;
					else if (str[index + 1] == '.') index += 3;//贪心,在i+1位置放灯,决定最少灯数
				}
			}
		}
		return ans;
	}
};