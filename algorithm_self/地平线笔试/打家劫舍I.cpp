#include <iostream>
#include<vector>
using namespace std;

int main() 
{
    int n = 0;
    cin >> n;
    vector<int>arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    vector<int>f(n+1);//以i为结尾,f[i]代表第i个位置抢,能够获得的最大价值
    vector<int>g(n + 1);//以i为结尾,g[i]代表第i个位置不抢的最大价值
    f[0] = arr[0];
    for (int i = 1; i <= n; i++)
    {
        f[i] = max(arr[i - 1] + g[i - 1],f[i-1]);
        g[i] = max(f[i - 1], g[i - 1]);
    }
    cout << max(f[n], g[n]) << endl;
}
