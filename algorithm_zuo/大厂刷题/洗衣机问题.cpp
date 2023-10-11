
//https://leetcode.cn/problems/super-washing-machines/?utm_source=LCUS&utm_medium=ip_redirect&utm_campaign=transfer2china
//ϴ�»�����:ֻרע��ĳһ��λ��i,�Ե����о�������
//1. ����iλ�������Ҫa���·����ܴﵽƽ��,�Ҳ��b���·��ﵽƽ��
//��ô����Ҫ��b�������b��,���� count=max(abs(a),abs(b))
//��iλ�þ��������ֲ��ܰ���,���ǲ���Ҫ�����·�
//2. ���iλ����฻ԣa,�Ҳ�Ҳ��ԣb,˵��Ҫ��iλ������·�,��������һ�߿϶���ʣ,����
//��ΪҪ��ͣ������Ҳ��count=max(a,b)
//3. ���iλ�����Ƿa,�Ҳ�Ƿb,��ôҪcount=a+b
//���㴦��,ʹ��������iλ����ಿ���ۼӺ�,
//���ÿ��λ�õ�����,��ô����϶���������������,��Ϊ��Ҫ��������λ����Ҫ����
#include<iostream>
#include<vector>
using namespace std;

class Solution
{
public:
    int findMinMoves(vector<int>& nums)
    {
        int n = nums.size();
        if (n == 0)return 0;
        int sum = 0;
        for (auto e : nums)
            sum += e;
        if (sum % n != 0) return -1;
        int avg = sum / n;
        int leftSum = 0, ans = 0;
        for (int i = 0; i < n; i++)
        {
            int leftRest = leftSum - i * avg;
            int rightRest = (sum - leftSum - nums[i]) - (n - i - 1) * avg;
            if (leftRest < 0 && rightRest < 0)
                ans = max(ans, abs(leftRest) + abs(rightRest));
            else
                ans = max(ans, max(abs(leftRest), abs(rightRest)));
            leftSum += nums[i];
        }
        return ans;
    }
};
