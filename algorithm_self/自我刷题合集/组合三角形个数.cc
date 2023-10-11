class Solution 
{
public:
// 暴力方式:遍历的方式然后进行判断是否构成三角形,O(N^3)
// a<b<c时,如果a+b>c那么一定可以构成三角形,前提先进行排序
// 排序之后就可以利用单调性进行优化(一些比较没有必要出现,就可以省略)
// 优化:
// [2,2,3,4,5,9,10] 选中最大值c=10,在10前面区间中,a=2,b=9,
// a+b>c,那么[3...5]和9配合就肯定都可以,使用双指针选中,
// 所以ret+=right-left,然后right--,b=5,
// a=2,b=5,a+b<10,无法构成三角形,那么2和[2...4]肯定也构成不了,所以left++,放弃这个a=2
// 之后选中c=9,继续上述过程...
// =>O(N^2)
    int triangleNumber(vector<int>& nums) 
    {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int ret=0;
        for(int i=n-1;i>=2;i--)
        {
            int left=0,right=i-1;
            while(left<right)
            {
                if(nums[left]+nums[right] > nums[i])
                {
                    ret+=right-left;
                    right--;
                }
                else
                {
                    left++;
                }
            }
        }
        return ret;
    }
};