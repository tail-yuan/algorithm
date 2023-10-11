//https://leetcode.cn/problems/kth-smallest-element-in-a-sorted-matrix/?utm_source=LCUS&utm_medium=ip_redirect&utm_campaign=transfer2china
//����ǰ����ÿһ������,ÿһ������.
// 
//���:
//1. ����ҵ�С��K������һ���ж��ٸ�?
// �����Ͻ�Ԫ��x�Ƚ�,if k<x: x������, if k>x: ��Ϊһ���������,��඼��kС,�ռ����ٸ�,Ȼ��������
// 
//2. ����ҵ���ӽ�K������?
// ͬ��,��������ʱ˵����ʱ��k>x,��¼x. �����и���x�����ֵ,����С��K,����.
//3. ���: ����ҵ���KС������,��ô���䷶Χ��minVal(0,0) ~maxVal(n-1,m-1),ʹ�ö��ֵķ�ʽ,ͳ�Ʊ�MidС��
//�����ж��ٸ�sum,��K�Ƚ�.if sum<K,˵��mid��������,else ������.
// -------�����׺��Եľ���:
//�����ҵ���k'����ʱ�����ôչ�K��,�����ھ����п���û��k',��ô������ӽ�k'������
//���յõ����.
//T(N): ���O(n+m) ���ִ�����O(log(maxVal-minVal))
#include<iostream>
#include<vector>
using namespace std;
class Solution
{
    class Info
    {
    public:
        int near;
        int num;
        Info(int ne, int nu)
            :near(ne)
            , num(nu)
        {}
    };
    int n;
    int m;
public:
    int kthSmallest(vector<vector<int>>& arr, int k)
    {
        n = arr.size(), m = arr[0].size();
        int left = arr[0][0], right = arr[n - 1][m - 1];
        int ans = 0;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            //���ʱҪ��<=mid�����ֺ�<=mid�����ֵĸ���
            Info info = noMoreNum(arr, mid);
            if (info.num < k)
                left = mid + 1;
            else
            {
                ans = info.near;
                right = mid - 1;
            }
        }
        return ans;
    }
    Info noMoreNum(vector<vector<int>>& arr, int val)
    {
        int near = INT_MIN;
        int count = 0;
        int i = 0, j = m - 1;
        while (i < n && j >= 0)
        {
            int x = arr[i][j];
            if (x > val)
                  j--;
            else
            {
                count += j + 1;
                near = max(x, near);//ʱ�̼�¼��ӽ�val��������ɶ
                i++;
            }
        }
        return Info(near,count);
    }
};