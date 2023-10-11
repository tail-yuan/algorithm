#include<iostream>
#include<vector>
using namespace std;

//经典从左上角开始找
//拓展: 如果规定二维数组只有01,并且保证0一定在1的左边,可能一行全为0,或者1
//问:最多1 是哪一行?
// 也是从左上角开始,第一行一直往左走,直到index位置,不是1,记录<个数,行号>
// 看下一行,index位置是否为1,并且是否还能往左走,Yes->更新<个数,行号>,No->继续下一行
// 直到最后一行,返回最多的1的行号(可能有好几个相等个数的)
class isContain
{
public:
	bool isContainNum(vector<vector<int>>& arr,int x)
	{
		int row = 0;
		int col = arr[0].size()-1;
		while (row < arr.size() && col >= 0)
		{
			if (x > arr[row][col])
				row++;
			else if (x < arr[row][col])
				col--;
			else
				return true;
		}
		return false;
	}
};