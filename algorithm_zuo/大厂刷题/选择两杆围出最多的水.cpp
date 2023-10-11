#include<iostream>
#include<vector>
using namespace std;
//https://leetcode.cn/problems/container-with-most-water/submissions/
//������ʽ:O(N^2)
//��������ָ��left,right,ö��leftΪ��߽�,rightΪ�ұ߽�.
//ö����һȦ��,left++,right���˵�left+1��������ö��.
//�ܷ���right ������,left++,
// if [left]>[right],��ô�߶�����right���е���.
// ���䳤�ȼ�С,��ΪľͰЧӦ,����[left+1]>[right]
//����[left+1]<[right],���ᵼ�³˻���С,���õ���ˮ����С.
// ��˵���ߵ���һ��left����ȫû�б�Ҫ��ǰ��.
// if[left]<[right],��ô�߶�����left���е���.
// [left+1]<r: 1. [left+1]<[left],h��С,V��С 2. [left+1]>[left]�п��ܸ���V
// [left+1]>r: ��ʱh��right�е�,���п��ܽ��и���V�ϴ�ֵ��.
//���ϲ���˵��,�����߽�,�ĸ�ֵ��С,����������ʱ�����ƶ�.�ſ��ܸ������ֵ
//�Ϳ��Ż�Ϊ��βָ����㷨,�ĸ�ֵ��С,����ǰ�ƶ�Ѱ��ϴ�V�ĸ���.
class Solution
{
public:
	int maxArea(vector<int>& arr)
	{
		int left = 0, right = arr.size() - 1;
		int ret = INT_MIN;
		while (left < right)
		{
			int tmp_v = (right - left) * min(arr[left], arr[right]);
			ret = max(ret, tmp_v);
			if (arr[left] < arr[right])
				left++;
			else
				right--;
		}
		return ret;
	}
};