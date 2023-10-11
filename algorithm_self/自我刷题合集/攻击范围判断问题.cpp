//��Ȥ�Ƽ�������:
// A����B����,������Χ��һ����rΪ�뾶,angleΪ�Ƕȵ���������,
// ���ʹ��C++�����ж�ĳһ��λ�õ�C�Ƿ���⵽����
// Ӧ�õ��ܶ����ѧ����-֪ʶǷȱ

//�����к�����arctangent����һ�����Ǻ��������ڼ��������ֵ�ĽǶȣ�������ֵ���ڸ���ֵ��
//ͨ����ʾΪatan����ʱҲ��Ϊ�����к��������к�����
//atan2������atan��������չ�汾������������������ͨ����y��x���꣩�������������������γɵ�ֱ�������εĽǶ�
//atan2�������صĽǶȷ�Χ�Ǵ�����x�ᣨ0�ȣ���ʱ����ת�ĽǶȣ���ΧΪ[-��, ��] �� [-180��, 180��]��
//��������ǳ����ã���Ϊ�����Ը��ݸ�����y��x���꣬��ȷ�ؼ���������ڵ����ޣ���������Ӧ�ĽǶȡ�

//fmod���㸡�����ĺ���,fmod(x,y)����x����y������
//��ʾ�������У�fmod(angleC - angle / 2.0, 360)���ڼ����C��A֮��ĽǶ��빥���Ƕȷ�Χ�Ĳ�ֵ��
//��ȷ���ò�ֵ��[0, 360]�ķ�Χ�ڡ����������ж�C�Ƿ���A�Ĺ����Ƕ��ڡ�
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