#include"head.hpp"
//第find位置之前缺失的整数数目是>k的,记录find位置
//不够,就在右区间遍历
//够,就一直向左更新最小区间.
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) 
    {
        int l = 0;
        int r = arr.size() - 1;
        int find = arr.size();
        while (l <= r)
        {
            int mid = (l + r) / 2;
            if (arr[mid] - (mid + 1) >= k)
            {
                find = mid;
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        int preVal = find == 0 ? 0 : arr[find - 1];
        int under = preVal - find;
        return preVal + (k-under);
    }
};