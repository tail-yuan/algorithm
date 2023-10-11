#include"head.hpp"
//ÿ�γ��Լ��ұ�,���Լ�����ұ��Լ�С����,һ�ֿ��ԳԶ���
//���ǳԵ����ܳ�
//�ɴ��ڼ������һ��С��(�����Һ�����������Ҳ���Գ�,�ͱ������Ե������Ϳ�)
//����ջ(Сѹ��)
//		7 3 2 4 2 3 5 1 4 2
//ջ:
//		|3,1 |
//		|4,2 |
//		|5,2 | 5���������Ҫ����,��һ��5 4 �ڶ���ʣ��5
//7Ҫ��ջ,Ҫ��3�϶�����һ����3��2������ 7˳��Ѹճ���1��3����,������7,1
//7>4 �������,��4�ڵڶ��ֳ�������֮��,7˳���4����,������7,2
//7>5 �������,��5�ڵڶ��ֳ�������֮��,7�հ�4����,7,2 5,2 ,����һ��7�ٰ�5���˾�OK,
// ���Ͽ���������7��2+1��5��2�����ֵ
//max(2+1,2)	max(curTurn+1,MonStack[--stackSize][1]);
//ջ����Ԫ��,����ջ��Ԫ�ر���С,��ô��Ҫ������
//max(�ҵ�����+1(�ҳ����÷���һ��),��������(��ͬһ������������˳���������)�����ֵ������Ҫѹջ������
class Solution
{
public:
	int EatFish(vector<int>& arr)
	{
		int n = arr.size();
		//MonotonicStack/*����ջ*/
		vector<vector<int, int>>MonStack(n);
		int stackSize = 0;
		int ans = 0;
		for (int i = n - 1; i >= 0; i--)
		{
			int curTurn = 0;
			while (stackSize > 0 && MonStack[stackSize - 1][0] < arr[i])
			{
				curTurn = max(curTurn+1,MonStack[--stackSize][1]);//ע�������±�
			}
			//�����ٳ���,���Լ���ջ
			MonStack[stackSize][0] = arr[i];
			MonStack[stackSize][1] = curTurn;
			//��¼�������
			ans = max(ans, curTurn);
		}
		return ans;//�����������(���ǽ���)
	}
};