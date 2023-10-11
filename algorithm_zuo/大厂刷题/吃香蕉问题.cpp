
//�����涨ʱ��T,�ڹ涨ʱ����,�������㽶����ʱ�趨��һ��Сʱ���㽶����С�ٶ�k

//�Ե��ٶ�Խ��,���ѵ�ʱ���ԽС,������
//����ٶȶ�Ӧ����С��ʱ��,����趨�㽶�����ֵΪ�Ե��ٶ�k,
//���е��ٶȾͶ���1~maxVal֮��,ʹ�ö��ֲ��ҵķ�ʽ,�鿴midλ������Ϊ�ٶ�����Ҫ��ʱ���Ƿ�<=T
//�ҵ��������������ұߵ��ٶ�ֵ��Ϊ��
#include<iostream>
#include<vector>
using namespace std;
class Solution
{
public:
    int minEatingSpeed(vector<int>& piles, int h)
    {
        int l = 1;
        int r = 0;
        for (auto e : piles)
            r = max(e, r);
        int ans = 0;
        while (l <= r)
        {
            int mid = l + ((r - l) >> 1);
            if (hours(piles, mid) <= h)
            {
                ans = mid;
                r = mid - 1;
            }
            else
                l = mid + 1;
        }
        return ans;
    }
    //��Ϊ���ʣ��ʱ��,�ϷϾ�Ъ��,����ʱ�����㽶����/�ٶ�����ȡ��
    //������ʽ�Ƶ�֮��a/b����ȡ���Ĺ�ʽ���� (a+b-1)/b
    long hours(vector<int>& nums, int speed)
    {
        long ans = 0;
        int offset = speed - 1;
        for (auto e : nums)
        {
            ans += (e + offset) / speed;
        }
        return ans;
    }
};