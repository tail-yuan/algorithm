//https://www.bilibili.com/video/BV1NV4y1B7ZZ?p=32&spm_id_from=pageDriver&vd_source=cc945ef88574fe2db5e814c0c265a4c7
// https://leetcode.cn/problems/trapping-rain-water-ii/

//将四边数字插入到小根堆中,弹出最小值,他就是边界Max值
//弹出最小值,将他相连的还未入小跟堆的四个方位的值加入到堆中,进入时统计每点的水量,一定是以Max的内湖区域,
// sum+=max(0,Max-arr[i][j])
//弹出时更新Max值,周而复始
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class Solution
{
    class Node
    {
    public:
        int val;
        int row;
        int col;
        Node(int v,int r,int c)
            :val(v)
            ,row(r)
            ,col(c)
        {}
    };
    struct Greater
    {
        bool operator()(const Node& n1, const Node& n2)const
        {
            if (n1.val > n2.val)
                return true;
            else
                return false;
        }
    };
public:
    int trapRainWater(vector<vector<int>>& arr)
    {
        int n = arr.size(), m = arr[0].size();
        if (n == 0 || m == 0)return 0;
        vector<vector<bool>> visi(n,vector<bool>(m));
        priority_queue<Node, vector<Node>, Greater> pq;
        //添加四条边时注意四个角不要重复添加到堆中
        for (int col = 0; col < m - 1; col++) {
            visi[0][col] = true;
            pq.push( Node(arr[0][col], 0, col));
        }
        for (int row = 0; row < n - 1; row++) {
            visi[row][m - 1] = true;
            pq.push(Node(arr[row][m - 1], row, m - 1));
        }
        for (int col = m - 1; col > 0; col--) {
            visi[n - 1][col] = true;
            pq.push( Node(arr[n - 1][col], n - 1, col));
        }
        for (int row = n - 1; row > 0; row--) {
            visi[row][0] = true;
            pq.push(Node(arr[row][0], row, 0));
        }

        int maxVal = 0, sum = 0;
        while (!pq.empty())
        {
            Node cur = pq.top(); pq.pop();
            maxVal = max(maxVal, cur.val);
            int row = cur.row, col = cur.col;
            //将row col位置的上下左右插入到堆中
            if (row > 0 && !visi[row - 1][col])
            {
                sum += max(0, maxVal - arr[row - 1][col]);
                visi[row - 1][col] = true;
                pq.push(Node(arr[row-1][col],row-1,col));
            }
            if (row <n-1 && !visi[row + 1][col])
            {
                sum += max(0, maxVal - arr[row + 1][col]);
                visi[row + 1][col] = true;
                pq.push(Node(arr[row + 1][col], row + 1, col));
            }
            if (col > 0 && !visi[row ][col-1])
            {
                sum += max(0, maxVal - arr[row][col - 1]);
                visi[row][col - 1] = true;
                pq.push(Node(arr[row][col - 1], row, col-1));
            }
            if (col <m-1 && !visi[row][col + 1])
            {
                sum += max(0, maxVal - arr[row][col + 1]);
                visi[row][col + 1] = true;
                pq.push(Node(arr[row][col + 1], row, col + 1));
            }
        }
        return sum;
    }
};