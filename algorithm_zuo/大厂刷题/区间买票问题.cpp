#include <iostream>
#include<vector>
#include<string>
using namespace std;
//巨人网络笔试题,仍然存在问题
int N;
vector<int>height;
string func(char opt, int begin, int end, int tickets)
{
    if (opt == 'Q')
    {
        int min_ret = 0x3f3f3f3f;
        for (int i = begin; i < end; i++)
        {
            min_ret = min(min_ret, height[i]);
        }
        return to_string(min_ret);
    }
    else if (opt == 'B')
    {
        bool flag = true;
        for (int i = begin; i < end; i++)
        {
            if (height[i] - tickets < 0)
            {
                flag = false;
                break;
            }
        }
        if (!flag)
        {
            return "Fail!";
        }
        else
        {
            for (int i = begin; i < end; i++)
            {
                height[i] -= tickets;
            }
            return "OK!";
        }
    }
    else if (opt == 'R')
    {
        bool flag = true;
        for (int i = begin; i < end; i++)
        {
            if (height[i] + tickets > N)
            {
                flag = false;
                break;
            }
        }
        if (flag)
            return "OK!";
        else
            return "Fail!";
    }
    return "";
}
int main()
{
    int M = 0, Q = 0;
    cin >> M >> N >> Q;
    height = vector<int>(M - 1, N);
    char opt;
    int begin = 0, end = 0, tickets = 0;
    while (cin >> opt)
    {
        if (opt == 'Q')
        {
            cin >> begin >> end;
            string ret = func(opt, begin, end, 0);
            cout << ret << endl;
        }
        else
        {
            cin >> begin >> end >> tickets;
            string ret = func(opt, begin, end, tickets);
            cout << ret << endl;
        }
    }
    return 0;
}
// 64 位输出请用 printf("%lld")