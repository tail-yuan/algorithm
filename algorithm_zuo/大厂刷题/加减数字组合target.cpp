
//����һ������arr���������ÿ������֮ǰ����+���ߵ��Ǳ����������ֶ������ٸ���һ����target��
//����������target�ķ������Ƕ���?ÿһ�ַ���������õ����е��������

#include<iostream>
#include<vector>
using namespace std;
//������:û����һ���ڵ㶼��Ҫ���Ǵ�����indexλ�õ�������+����-
//ÿ���ڵ㶼������targetֵ,��ʱҪ��¼count.�������Ҫ��ÿһ���������õ�,��ô����϶���Ҷ�ӽڵ���
class Solution
{
	int count;
	int aim;
	int n;
public:
	int getWays(int target, vector<int>& arr)
	{
		aim = target;
		n = arr.size();
		dfs(arr, 0,0);
		return count;
	}
	void dfs(vector<int>& arr, int index,int path)
	{
		if (index == n)
		{
			if (path == aim)
				count++;
			return;
		}
		dfs(arr, index + 1, path + arr[index]);
		dfs(arr, index + 1, path - arr[index]);
	}
};