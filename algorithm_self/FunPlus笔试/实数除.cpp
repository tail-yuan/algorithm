#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//我使用了double数据类型来存储实数。你也可以使用float，但double通常提供更高的精度。
//在C++中，如果你使用整数进行除法，结果也会是整数。
// 也就是说，10 / 3 将返回 3，而不是 3.33333。
// 要获得一个浮点结果，你需要确保至少一个操作数是浮点数（就像上面的例子中的10.0 / 3.0）。

//如果除数（分母）是0，你的程序将进入未定义行为，
// 可能会导致程序崩溃或其他不可预测的结果。
// 因此，执行除法操作之前检查除数是否为0总是一个好习惯。
// 
//计算机无法存储分数,只能存储约定小数位数的小数作为你的分数的值,因为除不尽就是除不尽,不可能都存下
double func(double a, double b) 
{
    if (b == 0) 
    {
        return -1;
    }
    return a/ b;
}
int main()
{
    int a = 2, b = 3, c = 1;
    cout << func(a, b) << endl;//
    cout << func(c, func(a, b)) << endl;//1.5
    return 0;
}