//掌趣科技笔试题:
// A面向B攻击,攻击范围是一个以r为半径,angle为角度的扇形区域,
// 如何使用C++语言判断某一个位置的C是否会遭到攻击
// 应用到很多的数学函数-知识欠缺

//反正切函数（arctangent）是一个三角函数，用于计算给定数值的角度，其正切值等于该数值。
//通常表示为atan，有时也称为反正切函数或逆切函数。
//atan2函数是atan函数的扩展版本，它接受两个参数（通常是y和x坐标），并返回这两个坐标形成的直角三角形的角度
//atan2函数返回的角度范围是从正向x轴（0度）逆时针旋转的角度，范围为[-π, π] 或 [-180°, 180°]。
//这个函数非常有用，因为它可以根据给定的y和x坐标，正确地计算出点所在的象限，并返回相应的角度。

//fmod计算浮点数的函数,fmod(x,y)计算x除以y的余数
//在示例代码中，fmod(angleC - angle / 2.0, 360)用于计算点C与A之间的角度与攻击角度范围的差值，
//并确保该差值在[0, 360]的范围内。这样可以判断C是否在A的攻击角度内。
#include<iostream>
#include<cmath>

#define M_PI 3.14159265358979323846
using namespace std;
class Attack
{
public:
	bool isUnderAttack(int ax, int ay, int r, int angle, int cx, int cy)
	{
		double dis = sqrt(pow(ax-cx,2)+pow(ay-cy,2));
		if (dis <= r)
		{
			double angleC = atan2(cy-ay,cx-ax)* 180/ M_PI;
			double diff = fmod(angleC-angle/2.0,360);
			if (diff < 0)
				diff += 360;
			if (diff <= angle)
				return true;
		}
		return false;
	}
};