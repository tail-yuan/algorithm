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
    vector<int>f(n+1);//��iΪ��β,f[i]�����i��λ����,�ܹ���õ�����ֵ
    vector<int>g(n + 1);//��iΪ��β,g[i]�����i��λ�ò���������ֵ
    f[0] = arr[0];
    for (int i = 1; i <= n; i++)
    {
        f[i] = max(arr[i - 1] + g[i - 1],f[i-1]);
        g[i] = max(f[i - 1], g[i - 1]);
    }
    cout << max(f[n], g[n]) << endl;
}
