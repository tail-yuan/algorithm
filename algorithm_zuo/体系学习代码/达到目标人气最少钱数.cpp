//CC������һ��������ϲ��һλŮֱ��Kiki���裬ƽʱ�;����������ޡ�����˽�ġ����CCֱ��ƽ̨�ھ���
//����֮�������������������һ��ʼ��Ů�����ĳ�ʼ����ֵΪstart�� �ܹ�������һ��������Ҫ�պôﵽend��
//�������������������Ŀ��Բ�ȡ�ķ����У�
//a.���� ����x C�ң����� + 2
//b.���� ����y C�ң����� * 2
//c.˽�� ����z C�ң����� - 2
//���� end Զ����start��endΪż���� ��дһ�����������������һ�£����ٻ��Ѷ���C�Ҿ��ܰ���������
//Kiki�������պôﵽend���Ӷ��ܹ�������һ�֣�
//����������
//��һ������5�����ݣ��ֱ�Ϊ��x y z start end��ÿ�������Կո�ֿ���
//���У�0��x, y, z����10000�� 0��start, end����1000000
//���������
//��Ҫ���ѵ�����C�ҡ�
//ʾ��1 :
//����
//3 100 1 2 6
//���
//6
// �����ܵݹ��ǿ����ܲ����,������Ҫ1. ���ƽ����ȥ���Ƶݹ�,�����ܹ�����.2. ��ҵ���з��ֲ�����Ҫ�ݹ��������Ϊbase case
//1. ����ֻ�����+2����,�ܹ���Ҫ���Ѷ���Ǯ? ((end-start)/2 )*add,����Ǯ�����ٳ��������û��Ҫ��
//2. ���ݹ�ͨ�����ַ�ʽ����������ֵ����Ѿ���end�Ķ�����,Ȼ�������¼�,���·��û�б�Ҫ��
//3. ҵ��:������ֵС��0ʱ�Ϳ��Է�����
//��������֮��,�ݹ鷶Χ�϶�����һ���̶���Χ,һ��������
#include<iostream>
using namespace std;
class Solution
{
public:
	int getCoinsMin(int add, int times, int del, int start, int end)
	{
		if (start > end)return -1;

		return process(0,end,add,times,del,start,end*2,((end-start)/2)*add);
	}
	//preMoney:֮ǰ�Ѿ�ʹ�õ���Ǯ��
	int process(int preMoney, int aim,
		int add, int times, int del,
		int cur,//ĳһ���ݹ鵱ǰ������ֵ
		int limitAim, int limitCoins)
	{
		if (preMoney > limitCoins)
			return INT_MAX;
		if(cur>limitAim )
			return INT_MAX;
		if(cur<0)
			return INT_MAX;
		if (cur == aim)
			return preMoney;
		int ret = INT_MAX;
		int p1 = process(preMoney+add,aim,add,times,del,cur+2,limitAim,limitCoins);
		ret = min(ret, p1);
		int p2 = process(preMoney +times, aim, add, times, del, cur * 2, limitAim, limitCoins);
		ret = min(ret, p2);
		int p3 = process(preMoney +del, aim, add, times, del, cur - 2, limitAim, limitCoins);
		ret = min(ret, p3);
		return ret;
	}
};