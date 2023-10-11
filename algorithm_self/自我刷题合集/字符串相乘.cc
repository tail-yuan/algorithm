class Solution 
{
public:
//转化为整数,涉及到int类型越界
//所以使用容器存储,那么开大空间呢?
//100*100 =10000,1000*1000-1000000=>4位数*4位数不大于4+4,
//所以开辟m+n大小空间,涉及到进位数学操作都是从最后一位开始向前,也就是将乘积从后往前放
//进位如何解决?
//num1的最后一位和num2的j[0,n]每一位运算结果放在i+j+1位置,然后将m行累加得到每一个位置的值
//然后整体调整,从后往前将/10累加到在i-1位置,相当于进位了,%10->[i]
//注意判断首位是否为0
    string multiply(string num1, string num2) 
    {
        if(num1=="0" || num2=="0")
            return "0";
        int m=num1.size(),n=num2.size();
        vector<int>arr(m+n);
        for(int i=m-1;i>=0;i--)
        {
            int x=num1[i]-'0';
            for(int j=n-1;j>=0;j--)
            {
                int y=num2[j]-'0';
                arr[i+j+1] += x*y;
            }
        }
        for(int i=m+n-1;i>0;i--)//注意下标有-1,所以是>0
        {
            arr[i-1] += arr[i]/10;
            arr[i]=arr[i]%10;
        }
        string ret="";
        for(int i= arr[0]==0?1:0;i<m+n;i++)
        {
            ret+=to_string(arr[i]);
        }
        return ret;
    }
};