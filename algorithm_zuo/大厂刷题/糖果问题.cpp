//�����ǹ�:https://leetcode.cn/problems/candy/description/
//n ������վ��һ�š�����һ���������� ratings ��ʾÿ�����ӵ����֡�
//����Ҫ��������Ҫ�󣬸���Щ���ӷַ��ǹ���
//ÿ���������ٷ��䵽 1 ���ǹ���
//���������������ָ��ߵĺ��ӻ��ø�����ǹ���
//�����ÿ�����ӷַ��ǹ������㲢������Ҫ׼���� �����ǹ���Ŀ ��
// �ⷨһ:O(N),O(3N)
// ����left����,�����ұ���,ÿ��λ��ֻ�����Լ�ǰ����Ǹ�λ�õ�ֵ,
// ���������,���������ǹ�������++,����������.
// ����right����,��������,ÿ��λ��ֻ�����Լ�������Ǹ�ֵ,
// ���������,���������ǹ�������++.
// ��������ÿ��λ��ȡmax����ÿ����Ӧ�÷�����ǹ�����.
// �ⷨ��: ʹ�ü����������渨������leftright
// 
//��������:��ԭ����Ļ����ϣ�����һ��ԭ��:
//���ڵĺ��Ӽ��������һ�����ֵ��ǹ�������һ������������Ҫ�ֶ�����
//�ⷨ: ͬ��,�����һ���ͼ̳�,�����С��=1,����ߴ��++����left����.

#include<iostream>
#include<vector>
using namespace std;
class Solution
{
public:
    int candy(vector<int>& arr)
    {
        int n = arr.size();
        vector<int>left(n,1);
        vector<int>right(n,1);
        //����Խ�����,��index=1��ʼ
        for (int i = 1; i < n; i++)
        {
            if (arr[i] > arr[i - 1])
                left[i] = left[i - 1] + 1;
        }
        for (int i = n - 2; i >= 0; i--)
        {
            if (arr[i] > arr[i + 1])
                right[i] = right[i + 1] + 1;
        }
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += max(left[i], right[i]);
        }
        return sum;
    }
    int candy_plus(vector<int>& arr)
    {
        int n = arr.size();
        vector<int>left(n, 1);
        vector<int>right(n, 1);
        //����Խ�����,��index=1��ʼ
        for (int i = 1; i < n; i++)
        {
            if (arr[i] > arr[i - 1])
                left[i] = left[i - 1] + 1;
            else if (arr[i] == arr[i - 1])
                left[i] = left[i - 1];
        }
        for (int i = n - 2; i >= 0; i--)
        {
            if (arr[i] > arr[i + 1])
                right[i] = right[i + 1] + 1;
            else if (arr[i] == arr[i + 1])
                right[i] = right[i + 1];
        }
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += max(left[i], right[i]);
        }
        return sum;
    }
};