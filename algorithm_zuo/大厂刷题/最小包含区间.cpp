//https://leetcode.cn/problems/smallest-range-covering-elements-from-k-lists/

//���: 
//ȷ��һ������,ʹ�������ж�����ÿ�������ֵ,ѡ����̵�����.��������������䳤����ͬ,��ô���س�ʼֵС���Ǹ�
//˼·:
//ѡ��һ�������,��ÿ������ĵ�һ��Ԫ�ز����������,�õ�minVal,maxVal��¼��ʱ���䳤��.
//��ʱѡ�������minValΪ��ͷ��,�����ҵ����ܸ��������������õ�����.��Ϊ��ѡ�Ķ�����Сֵ��
//Ȼ���Ը��²���,������СֵminVal,�������ڵ�������ѡ����һ��λ���ٲ��뵽�������,
//���µõ��µ�minVal,maxVal,��¼���䳤��,����ret,Ȼ���ٵ���,...��������
//��������в���ֵʱ������Ҫ��¼�����ĸ�������,�����еĵڼ���λ��,���Կ��Խ�����װΪһ��Node,
//���ú���ʹ�ù�ϣ��ķ�ʽ
#include<iostream>
#include<vector>
#include<set>
using namespace std;
class Solution
{
    class Node
    {
    public:
        int val;
        int arrId;
        int index;
    public:
        Node(int v, int a, int i)
            :val(v)
            , arrId(a)
            , index(i)
        {}
    };
    struct Less
    {
        bool operator()(const Node& n1, const Node& n2)const
        {
            //��֤������ͬ���������ʱ,������ʼ�±��С��
            bool flag = false;
            if (n1.val < n2.val)
                flag=true;
            else if (n1.val == n2.val)
            {
                if (n1.arrId < n2.arrId)
                    flag = true;
            }
            return flag;
        }
    };
public:
    vector<int> smallestRange(vector<vector<int>>& nums)
    {
        int n = nums.size();//һ���ж��ٸ�����
        set<Node,Less> treeSet;
        for (int i = 0; i < n; i++)
        {
            treeSet.insert(Node(nums[i][0],i,0));
        }
        bool isSet = false;
        int a = 0, b = 0;
        while (treeSet.size() == n)
        {
            auto minNode = treeSet.begin();
            auto maxNode = --treeSet.end();
            if (!isSet || (maxNode->val - minNode->val < b - a))
            {
                isSet = true;
                a = minNode->val;
                b = maxNode->val;
            }
            auto front = treeSet.begin();
            int arrId = front->arrId;
            int index = front->index + 1;
            treeSet.erase(front);//һ��Ҫ�ڲ����µ�֮ǰɾ��,Ҫ��Ȼ����ڸ�������֮��,ռ��ͷ��λ�õ���ɾ����������
            if (index != nums[arrId].size())
                treeSet.insert(Node(nums[arrId][index],arrId,index));
        }
        return { a,b };
    }
};

//int main()
//{
//    Solution s;
//    vector<vector<int>> nums1{{4, 10, 15, 24, 26}, { 0,9,12,20 }, { 5,18,22,30 }};
//    vector<vector<int>> nums{{1,2,3}, { 1,2,3 }, { 1,2,3 }};
//    auto ret=s.smallestRange(nums);
//    cout << ret[0] << " " << ret[1];
//    return 0;
//}