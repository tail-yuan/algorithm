#include"head.hpp"
//������Ѷ����
// ����һ������һ����n����
// ÿ������û��ֵ�����1~n��Щ���֣����ظ��ķ��䵽��������
// ���� : ������ڵ��ֵ�ܺ� �� ż����ڵ��ֵ�ܺ� ������1
// ����������ڵ����ֵ��һ������
// 2 <= n <= 10^5 

//1.ͨ��������������ȱ����õ�������k,����n���ڵ�
//2.��ν��з���[1,n],ѡ��k����������,ʣ�µĸ�ż����
	//2.1 �޷�ʹ�ö���,��Ϊ�ڵ����̫��
	//2.2 ��������ۼӺ�sum1�϶�����ǰk�������ۼӺ�,����С�����k�����ֵ��ۼӺ�,�����޷�ʵ�ַ���
	//2.3 n�����ż��,����һ��һ��,���������,�Ϳ��ܴ������ַ���,һ��һ����
//3. ���һ������generate(x,n,k)
//[1, n]����ѡ��k������, ��k�����ֵ��ۼӺ���x, , ����һ�ַ�������

class Solution
{
public:
	//[1,n]��Χ����,k����������������Ҫѡȡ�ĸ���
	int* team(int n, int k)
	{
		int sum = (n + 1) * n / 2;
		int p1 = sum / 2;
		int p2 = (sum + 1) / 2;
		int* ans= generate(p1,n,k);
		if (ans!=nullptr && (p1 != p2))//˵��n������,��������һ��
		{
			ans = generate(p2,n,k);
		}
		return ans != nullptr ? ans : new int[n] {-1};
	}
	//[1,n]����ѡ��k������,��k�����ֵ��ۼӺ���x,,����һ�ַ�������
	int* generate(int x, int n, int k)
	{
		//���ȵõ�ǰk�����ֵ��ۼӺ�
		int sumMink = (k + 1) * k / 2;
		//ÿ��������������,������λ�ð�ҵ����һ����λ��
		int range = n - k;
		if (x<sumMink || x>(sumMink + k * range))
		{
			return nullptr;
		}
		int addSum = x - sumMink;
		//��Ҫ����ҵ����ĸ����м���
		int rightSize = addSum / range;
		//��Ҫ�����ȷ��λ�����Ǹ�,���յ���,�����Ǹ�
		int midIndex = (k - rightSize) + (addSum % range);
		int leftSize = k - rightSize - (addSum % range == 0 ? 0 : 1);
		int* ans = new int(k);
		//ǰ��������Ҫ��ҵ�
		for (int i = 0; i < leftSize; i++)
		{
			ans[i] = i + 1;
		}
		//������ڵ��Ǹ�
		if (addSum % range != 0)
			ans[leftSize] = midIndex;
		//��ҵ�����,��󼸸�ֵ
		for (int i = k - 1, j = 0; j < rightSize;i--, j++)
		{
			ans[i] = n - j;
		}
		return ans;
	}
	void OddLevelEvenLevelSumClosed(string & args)
	{
		int n = 100;
		int k = 33;
		int* ans = team(n,k);
	}
};