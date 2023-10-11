//��һ������Ϊ n �İ��ϸ��������е��������� nums ����ʵ�� search ����֮ǰ��
//��ĳ���±� k �Ͻ�����ת��ʹ�����Ϊ[nums[k], nums[k + 1], ....., nums[nums.length - 1], nums[0], nums[1], ......., nums[k - 1]]��
//������ת������� nums ��һ������ target ��
//������� target �Ƿ������ nums �����в��������±꣨��0��ʼ������������������뷵�� - 1��
//
//���ݷ�Χ��
//Ҫ�󣺿ռ临�Ӷ�  ��ʱ�临�Ӷ�
//
//���磬����[0, 2, 4, 6, 8, 10]���±�3����ת֮���Ϊ[6, 8, 10, 0, 2, 4], 
//������targetΪ10ʱ��10���±���2��targetΪ3ʱ��nums�����в�����3�����Է��� - 1
//��Ȼ���Կ���ʹ��hashMap<key,index>����,<O(N),O(N)>
#include<iostream>
#include<vector>
using namespace std;
//��ת֮�����������������,
//ʹ�õ�����,ʹ�ö��ֲ���<O(logN),O(1)>
class RotateArrFindIndex
{
public:
	int search(vector<int>& nums, int target)
	{
		int left = 0, right = nums.size() - 1;
		while (left <= right)
		{
			int mid = left + (right - left) / 2;
			if (nums[mid] == target)
				return mid;
			if (nums[left] < nums[mid])// mid���������������
			{
				if (nums[left] < target && target < nums[mid])
					right = mid - 1;
				else
					left = mid + 1;
			}
			else//mid�����ұ���������
			{
				if (nums[mid] < target && target < nums[right])
					left = mid + 1;
				else
					right = mid - 1;
			}
		}
		return -1;
	}
};