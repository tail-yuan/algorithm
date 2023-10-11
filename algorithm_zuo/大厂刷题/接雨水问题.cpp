//https://leetcode.cn/problems/trapping-rain-water/

//���:
//ֻרע��iλ���ܴ�ż���ˮ
//[0,i-1]�������ֵ��left, [i+1,n-1]�������ֵ��right
//��ôiλ���ܴ��ˮ�����ֵһ���ܹ��ǵ�min(left,right),���㲻֪����Զ��λ��left����right���㶵��
//��Ȼ�����˼�ȥarr[i].
//���left,right���ֵ��û�Լ�����,˵��iλ�ô洢ˮ��0
//����������ǰi-1�����ֵ�Ƕ���,i+1~n-1���ֵ�Ƕ���

//˫ָ�뷽ʽ
// https://www.bilibili.com/video/BV1NV4y1B7ZZ?t=534.5&p=31
//0λ�ú�n-1λ��û����,�϶���0
//l=1,r=n-1,leftMax,rightMax,����leftmax>rightmax
//���ȸ�����ͷ��ָ��λ��ˮ��,��Ϊ������ֵ�϶�>=leftMax,�Ҳ��Ѿ�ȷ����,����[i]λ�þ���rightMax-[i]
//����֮���Ǹ���rightMax
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int trap(vector<int>& arr)
    {
        int n = arr.size();
        if (n < 2)return 0;
        int l = 1, r = n - 2;
        int leftMax = arr[0], rightMax = arr[n - 1];
        int sum = 0;
        while (l <= r)
        {
            if (leftMax <= rightMax)
            {
                sum += max(0, leftMax - arr[l]);
                leftMax = max(leftMax, arr[l++]);
            }
            else
            {
                sum += max(0, rightMax - arr[r]);
                rightMax = max(rightMax, arr[r--]);
            }
        }
        return sum;
    }
    int trap1(vector<int>& arr) 
    {
        int n = arr.size();
        vector<int>leftArr(n);
        vector<int>rightArr(n);
        for (int i = 0, l = arr[0]; i < n; i++)
        {
            leftArr[i] = max(l, arr[i]);
            if (l < arr[i])
                l = arr[i];
        }
        for (int i = n - 1, r = arr[n - 1]; i >= 0; i--)
        {
            rightArr[i] = max(r, arr[i]);
            if (r < arr[i])
                r = arr[i];
        }

        int sum = 0;
        for (int i = 1; i < n - 1; i++)
        {
            sum += max(0, min(leftArr[i], rightArr[i]) - arr[i]);
        }
        return sum;
    }
};