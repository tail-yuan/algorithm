#include"head.hpp"
//ѡ��һ��ͬѧ,����ͬѧ����-1,��֤����Ϊ����,������������
// ���԰������
// ţţ�������׶�԰�ˣ���ʦ����ѧϰ����
// ��ʦ������5�����֣���ÿ�β�������ѡ�����е�4�����ּ�1
// ��һ֮������ֲ���С��0����Ϊ�׶�԰��ţţ��û�нӴ�������
// ����ţţ��֪�����Լ������Խ��ж��ٴ������Ĳ���
// ��չ��������leetcode 2141�������������ԭʼ����ͷǳ�����
// leetcode�������� : https://leetcode.com/problems/maximum-running-time-of-n-computers/

// ��ظ���¥��������
// ��ع���ʱ�������޵�,�ǿ���ȷ�������[0,�ۼӺ�(����һ�����Թ���)]
// ���Կ���ʹ�ö��ִ𰸷�,����targetʱ��,�����ܲ�����ɹ���
// ���ض������������ֵ,�����ʱ������
// 
// ʵ�ֺ���,�������,��¥,��׼Ӧ��֧�Ź����ٷ���,����boolֵ�����ܷ�����
// ���x���ֵ>Ŀ��ֵtarget,���Լ����ŵ�һ��¥,�������л�¥��
// ���x���ֵ<Ŀ��ֵtarget,��Ƭ����ܷ��ʣ��¥�㹩��
    // �����Ƭ����ۼӺ�>¥����*target,��һ����������¥����targetʱ��
    //(�л�����������,������ô�������ܺ�����)
    //https://image-1309381344.cos.ap-nanjing.myqcloud.com/img/image-20230521182626061.png

class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) 
    {
        sort(batteries.begin(),batteries.end());
        int size = batteries.size();
        //�����¼ǰi�����ֵ��ۼӺ�
        vector<long>sums(size);
        sums[0] = batteries[0];
        for (int i = 1; i < size; i++)
        {
            sums[i] = sums[i - 1] + batteries[i];
        }
        long l = 0;
        long m = 0;
        long r = sums[size - 1] / n;

        long ans = -1;
        while (l <= r)
        {
            m = (l + r) / 2;
            if (ok(batteries, sums, m, n))
            {
                ans = m;
                l = m + 1;
            }
            else
            {
                r = m - 1;
            }
        }
        return ans;
    }
    bool ok(vector<int>& arr, vector<long>& sums, long time, int num)
    {
        int l = 0;
        int m = 0;
        int r = arr.size() - 1;
        int left = arr.size();
        while (l <= r)
        {
            m = (l + r) / 2;
            if (arr[m] >= time)
            {
                left = m;
                r = m - 1;
            }
            else
            {
                l = m + 1;
            }
        }
        num -= arr.size() - left;
        long rest = left == 0 ? 0 : sums[left - 1];
        return time * (long)num <= rest;
    }
};