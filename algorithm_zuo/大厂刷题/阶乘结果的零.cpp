
//n阶乘之后0的个数,
//2*5=0,n的阶乘中,5因子的个数一定小于2因子的个数,
//所以转化为有多少个5因子的个数,就决定了乘积之后0的个数
//每5个数字就会出现一个5的因子,一共n/5组,至少就有n/5个
//1~25会多出来一个5的因子,26~50多出来一个5的因子,每25多出来一个,一共n/25组,
//每125个数字又会多出来一个5的因子,直到>n,n/125组
//...


class Solution 
{
public:
    int trailingZeroes(int n) 
    {
        int ans = 0;
        while (n !=0)
        {
            n /= 5;
            ans+=n;
        }
        return ans;
    }
};