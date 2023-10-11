
//一组数字,产生不重复的数字对数一共是n*(n-1)/2个
//生成所有数字对之后,计算差值绝对值,排序之后找到第K个最小的数字
//O(n^2)的没有意义,应该升级为O(n*logn)
//如果直接生成差值数组,那么就已经是o(n^2)了
//将原数组排序之后,所有数字对差值最大的就是maxVal-minVal,那么所有的数值对差值大小一定在
//1~maxVal-minVal之间,寻找单调性,<=5的个数有a个,<=50的个数有b个,那么a<=b必然成立
//那么我们寻找key值,查看小于key的数字对个数一共有多少个,假如是x个,
//if x> k,说明key值靠右了,需要到minVal,key-1区间中寻找新的key值,继续二分
//else if x<k,说明需要到key+1,maxVal区间中继续二分
//https://www.bilibili.com/video/BV1NV4y1B7ZZ?t=444.8&p=71
//真实出现的数字对差值必然在1~maxVal-minVal之间,但是可能没都打中,也可能相同差值重复出现
//可以通过相邻数字记录出现小于等于key的数值对次数观察得到
//count[x] < k,count[x+1]>k ,那么所求差值就是x+1
//二分的过程中查找count[x]<=k的所有相同x中最靠右的那个x,答案就是x+1的值
//所以需要实现func()得到小于等于key值的个数有多少个,
//使用双指针不回退的方式计算得到数字对个数,实现时间复杂度为o(N)
//之前二分的时间复杂度为O(log(maxVal-minVal))
//所以总的时间复杂度为O(log(maxVal-minVal) * N)
//特殊情况,如果值都相同,差值都是0,第k小二分之后就是最后,即n个,但是应该是返回0,所以初始化为-1

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class MinKthPairMinusABS
{
public:
	//暴力的方式就是生成差值数组,排序,拿出第k个,取值时注意下标应该是k-1
	int kthAbsSub1(vector<int>& arr, int k)
	{
		int n = arr.size();
		int m = (n * (n - 1)) >> 1;
		if (m == 0 || k<1 || k>m)
			return -1;
		vector<int>count(m);
		int size = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = i + 1; j < n; j++)
			{
				count[size++] = abs(arr[i] - arr[j]);
			}
		}
		sort(count.begin(), count.end());
		return count[k - 1];
	}
public:
	int kthAbsSub2(vector<int>& arr, int k)
	{
		int n = arr.size();
		if (n < 2 || k<1 || k>((n * (n - 1)) >> 1))
			return -1;
		sort(arr.begin(), arr.end());
		// int left = 0, right = arr[n - 1] - arr[0];
		long long left = 0, right = arr[n - 1] - arr[0];
		int mid = 0;
		int rightest = -1;
		while (left <= right)
		{
			// mid = left + (right - left)/2;
			mid = (left + right) / 2;
			//func()返回数字对差值小于等于mid的数字对的个数是否<k个
			if (func(arr, mid, k))
			{
				rightest = mid;
				left = mid + 1;
			}
			else
			{
				right = mid - 1;
			}
		}
		return rightest + 1;
	}
	bool func(vector<int>& arr, int limit, int k)
	{
		int x = 0;
		for (int l = 0, r = 1; l < arr.size(); r = max(r, ++l))
		{
			while (r < arr.size() && arr[r] - arr[l] <= limit)
				r++;
			x += r - l - 1;
		}
		return x < k;
	}
};
vector<int> randArr(int n, int val)
{
	vector<int>ans(n);
	for (int i = 0; i < n; i++)
	{
		ans[i] = rand() % val;
	}
	return ans;
}
void test()
{
	int size = 100;//生成数组的大小最大是100个数字
	int value = 100;//生成的数字数值范围在1~value之间
	int testTime = 10000;
	//测试次数,发现只能跑最大40次,否则程序就会中止,报错.
	//经过gdb调试发现是在113行求解k值时出现%0错误,所以需要进行特判m的值
	MinKthPairMinusABS s;
	cout << "测试开始" << endl;
	for (int i = 0; i < testTime; i++)
	{
		int n = rand() % size + 1;
		int m = ((n * (n - 1)) / 2);
		if (m == 0)
			continue;

		int k = (rand() % m) + 1;
		vector<int>arr = randArr(n, value);
		vector<int>tmp(arr);
		int ans1 = s.kthAbsSub1(arr, k);
		int ans2 = s.kthAbsSub2(tmp, k);
		if (ans1 != ans2)
		{
			cout << "出错了" << endl;
			cout << "k:" << k << endl;
			cout << "ans1:" << ans1 << endl;
			cout << "ans2:" << ans2 << endl;
			break;
		}
	}
	cout << "测试结束" << endl;
}
//int main()
//{
//	test();
//	// system("pause");
//	return 0;
//}