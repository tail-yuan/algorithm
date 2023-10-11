class Solution 
{
public:
//选出两个边界算出体积,暴力方式是O(N^2),也就是选出一个边之后枚举其他为另一个边进行计算,需要优化->将没有必要的枚举过程省略掉
//[6,2,5,4] 选6和4,体积为v1,h=4,就没有必要选<2,4>(必然减小)<5,4>(h=4,w减小),所以体积都减小
//所以,记录两个值体积后,没有必要再以较小值为边界之一进行枚举其他值了
//O(N)
    int maxArea(vector<int>& height) 
    {
        int left=0,right=height.size()-1,ret=0;
        while(left<right)
        {
            int v=min(height[left],height[right])*(right-left);
            ret=max(ret,v);
            if(height[left]>height[right])
                right--;
            else
                left++;
        }
        return ret;
    }
};