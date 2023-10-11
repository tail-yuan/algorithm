//https://leetcode.cn/problems/smallest-range-covering-elements-from-k-lists/

//题干: 
//确定一个区间,使得区间中都包含每个数组的值,选择最短的区间.如果存在两个区间长度相同,那么返回初始值小的那个
//思路:
//选择一张有序表,将每个数组的第一个元素插入有序表中,得到minVal,maxVal记录此时区间长度.
//此时选择的是以minVal为开头的,往后找到的能覆盖所有数组的最经济的区间.因为你选的都是最小值嘛
//然后尝试更新操作,弹出最小值minVal,在他所在的数组中选择下一个位置再插入到有序表中,
//重新得到新的minVal,maxVal,记录区间长度,更新ret,然后再弹出,...依此类推
//向有序表中插入值时后续需要记录他在哪个数组中,数组中的第几个位置,所以可以将他封装为一个Node,
//不用后续使用哈希表的方式
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
            //保证存在相同长度区间答案时,返回起始下标较小的
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
        int n = nums.size();//一共有多少个数组
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
            treeSet.erase(front);//一定要在插入新的之前删除,要不然会存在负数插入之后,占据头的位置导致删除错误数字
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