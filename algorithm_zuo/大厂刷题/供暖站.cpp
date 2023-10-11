//https://www.bilibili.com/video/BV1NV4y1B7ZZ?p=70&vd_source=cc945ef88574fe2db5e814c0c265a4c7
// https://leetcode.cn/problems/heaters/
//��ůվ
//�����������������,
//�����Ļ��Ƚ�i��i+1λ���ĸ�������,���i+1������,��ôiλ�üȲ��Ǵ�ʱ���ݵ����ѡ��,Ҳ����֮�����з��ݵ����ѡ��
//���iλ���Ǻ��ʵ�,��ôѡ��iλ��,��Ϊ��ʱ���ݵ����ѡ��.
//����Ѱ���ܹ�ʵ��indexλ�÷��ݹ�ů�Ĺ�ůվ����̵İ뾶,��¼
//Ȼ�����ÿ����ѹ�ůվ�Ͷ�Ӧ���ݵ����뾶
//������������ůվ����ĳ�����ݵľ�����ͬʱ,����ѡ����һ��,Ҳ���Բ�ѡ��
//��Ϊ��ѡ����һ���Ļ�,�����������һ��λ����С�뾶ʱ,Ҳ�ᱻѡ��
//���Ǵ�����ͬ��¯�����ظ�λ�õĻ�,����������ظ�ѡ��λ��.���Ե���
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution 
{
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) 
    {
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        int ans = 0;
        int j = 0;
        for (int i = 0; i < houses.size(); i++)
        {
            while (!best(houses, heaters, i, j))
                j++;
            ans = max(ans, abs(houses[i] - heaters[j]));
        }
        return ans;
    }
    bool best(vector<int>& houses, vector<int>& heaters, int i, int j)
    {
        return j == heaters.size() - 1 || 
            abs(houses[i] - heaters[j]) < abs(houses[i] - heaters[j+1]);
                                    //< ���� ��ȵ�ʱ�򷵻�false,Ҳ������һ��λ��
    }
};