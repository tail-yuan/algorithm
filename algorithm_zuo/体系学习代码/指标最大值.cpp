#include<iostream>
#include<vector>
#include<stack>
using namespace std;

//ÿһ����,�ҵ����������,�������������Сֵ,ָ��=��Сֵ*�������ۼӺ�,��ʱ�������ָ�����
//���ѡ������ָ�꼴��
//ʹ�õ���ջ,
//�ҵ����������������С���±�Ϊleft,�ҵ��ұ��������С���±�Ϊright,�����Χ[left,right]��������������
//����������������Сֵ,Ȼ�����㼴��
//T=O(N)


//[0,a)���
int GetMax(vector<int>& arr)
{
	//��������arr[i]��ʾǰi����ۼӺ�
	vector<int>sums(arr.size());
	for (int i = 1; i < arr.size(); i++)
		sums[i] = sums[i - 1] + arr[i];
	
	stack<int> st;
	int maxSum = 0;
	for (int i = 0; i < arr.size(); i++)
	{
		while (!st.empty() && arr[st.top()] >= arr[i])//iλ�õ�ֵ>ջ��
		{
			int targetIndex = st.top(); st.pop();
			//�Լ��ۼӺ�-��߽��ۼӺ�=�Լ��������ۼӺ�
			int sum = st.empty() ? sums[i - 1] : (sums[i - 1] - sums[st.top()] * arr[targetIndex]);
			maxSum = max(maxSum, sum);
		}
		st.push(i);
	}
	//˵�������������,Ҳ����û�ҵ��ұ߱���С��,�ұ߽�ֱ�Ӷ�λsize-1
	while (!st.empty())
	{
		int j = st.top(); st.pop();
		int sum = st.empty() ? sums[arr.size() - 1] : (sums[arr.size() - 1] - sums[st.top()])* arr[j];
		maxSum = max(maxSum, sum);
	}
	return maxSum;
}