#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
//找到连续奇数和等于nNum的个数
class Solution2
{
public:
    int Calc(int n)
    {
        unordered_map<int, int>hashMap;//<preSum,index>
        int prev = 0;
        for (int i = 1; i < n; i += 2)
        {
            prev = prev + i;
            hashMap[prev] = i;
        }
        int l = 1, r = l;
        int sum = 0;
        int count = 0;
        while (r < n)
        {
            sum += r;
            if (sum == n)
            {
                count++;
            }
            while (l<r && sum > n)
            {
                sum -= l;
                if (sum == n)
                    count++;
                l += 2;
            }
            r += 2;
        }
        return count;
    }
};

class Solution1
{
public:
    int Calc(int n)
    {
        int count = 0;
        for (int i = 1; i < n; i += 2)
        {
            int sum = i;
            for (int j = i + 2; j < n; j += 2)
            {
                if (sum < n)
                    sum += j;
                else if (sum == n)
                {
                    count++;
                    break;
                }
                else
                    break;
            }
        }
        return count;
    }
};
//
//int main()
//{
//    Solution2 s;
//    for (int i = 1; i < 50; i++)
//        cout << i << " " << s.Calc(i) << endl;
//    return 0;
//}