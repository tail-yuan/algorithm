#include<iostream>
#include<deque>
#include<vector>
using namespace std;


//�����˶��������
// ��εó����������ֵ��Сֵ(��ʹ�ñ����ķ�ʽ)
// ʹ��˫�˶��� ���²��Ա�֤ͷ���϶������ֵ
//	R ������ʱʱ�̱��ֶ����д�ͷ��β�ǴӴ�С��˳��
// 1. push_back()
// 2. ���cur > deque.pop_back()=> һֱ��ջ��cur<deque.pop_back(),��push_back(cur)��ʹΪ��
//	L������
// 1.�������ͷ����L������֮����ڵ�ֵ,��pop_front
// 2.������ǾͲ��ù�(��������Ϊpush_back()ʱ�ñ�Ӧ�ù��ڵ�ֵ��L++֮ǰ�͵�����)

// ά�����ǵ����ڲ���ʱ,��Ϊ���ֵ�Ŀ�����.L������һ��,ͷ������,��һ����Ϊ���ֵ
// R++���²��Խ���: cur>deque.pop_back(),cur������ + ���������,��û���ܳ�Ϊ���ֵ��
// T(N):ÿ��λ�ý������еĴ���
// ÿ��λ�ö�������һ��,����N����,O(N),ÿ�����ֲ��õڶ��ν�,ƽ��T(N)=O(1)
//

//���ⴰ���˶��ǹ̶���һ��

vector<int>getMaxOfWindow(vector<int>&arr,int w)
{
	if (arr.size() == 0 || w < 1 || arr.size() < w)
		return vector<int>();
	deque<int> qmax;
	vector<int>res(arr.size()-w+1);
	int index = 0;
	for (int i = 0; i < arr.size(); i++)
	{
		while (!qmax.empty() && arr[qmax.front()] <= arr[i])
			qmax.pop_back();
		qmax.push_back(i);
		//1. ������ô�ƶ�? ��������iΪֹʱ,������߽�Ӧ����i-w,����i������,��߽�Ӧ�ù��ڵ������±����i-w
		// ʲôʱ�򵯳�����ͷ(����ͷ�±�����ʲôʱ�����)��?�� i-w==q.front()
		// ����һ���Ǹձ����µ�����,��û�����ڵ�ʱ��,Ҳ����Ҫ��������
		if (qmax.front() == i - w)
			qmax.pop_front();
		//2. ʲôʱ�̻�ȡ�������ֵ����¼,���γɴ��ڴ�С֮�������±굽��w-1��ʼ�Ժ�ÿ���һ��������Ҫ��ȡ
		//��ʱ���ڵ����ֵ,������ͷԪ��
		if (i >= w - 1)
			res[index++] = qmax.front();
	}
}