#include<iostream>
#include<string>
using namespace std;

//N�㺺ŵ������,��Ҫ��n��Բ���ƶ�����һ����ȥ,���Ҵ���ѹС
//from end other ����ÿ���ƶ��и��ӵı�ʶ,�ǿɱ任��ɫ��
//1. ��1~i-1��Բ���ƶ���other��ȥ
//2. ����i�������ƶ���end��ȥ
//3. ת��Ŀ��:��ʱ���ǽ�other�ϵ�i-1��Բ���ƶ���end��ȥ
//4. ��СΪ������:�Ƚ�1~i-2Բ���ƶ���from��ȥ,�� ��other�ϵĵ�i-1��Բ���ƶ���end��
//�ܶ���ʼ...

void func(int i, string from, string end, string help)
{
	if (i == 1)
		cout << "Move 1 from " + from + "to " + end;
	else
	{
		func(i - 1, from, help, end);
		cout << "Move " + to_string(i) + " from " + from + " to" + end;
		func(i-1,help,end,from);
	}
}
void hanoi(int n)
{
	if (n > 0)
	{
		func(n,"left","right", "mid");//��left->right��
	}
}
