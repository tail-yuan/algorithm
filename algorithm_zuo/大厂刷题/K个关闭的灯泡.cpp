//������������nums,nums[i]��ʾ�ڵ�i+1Сʱ��nums[i]�ŵ��ݵ���,���ұ�֤����nums�����ظ�ֵ
//Ҳ���ǲ����ظ��ĵ���ͬһ������,
//����ʱ��,���ʱ�̱�֤������������֮�����K�������ǲ�����,
//��,����������������ʱ����ʲôʱ��?

//answer1:
//���Ƚ�ԭ��������ת��Ϊarr,arr[i]�����i+1�ŵ�����arr[i]ʱ�̱�����,��Ϊ��֤�˵��ݲ��ظ�
//https://www.bilibili.com/video/BV1NV4y1B7ZZ?t=776.5&p=77
//��arr������,����abλ��ʱ����������,�м���K������,�γɵĴ���,
//��ôa��b�ĵ��ݵ�����ʱ���е����ֵӦ��<�м䴰���е���ʱ�����Сֵ,���ܱ�֤��������
//�� max(a,b)<min([a+1,b-1]),ȡ���ߵ���ʱ�����ֵ��Ϊ�˱�֤�����ƶ���,��С��������Сֵ,��Ϊ��
//��֤�м�ĵ�����һʱ�̶��ǲ�����.
//��¼��������Сֵ����,ʹ��˫ָ��̶����ڴ�Сk��������,����¼����������ʱ��,���ȡ��Сֵ����
//O(N)����,������Ҫ������������¼������Сֵ

//answer2: �����ø������м�¼������Сֵ
//1. ����ת��
//2. left,right,�м���K������,��֤[left+1,right-1]������ÿһ��λ��Mid�ĵ���ʱ���Ƿ񶼴���max([left],[right])
//	2.1 ��������ڴ�ʱ˵����leftΪ��ͷ�����������������,��¼��,max([left],[right]),
//		Ȼ������ƶ�,ֻҪ[left+1,right-1]�����ǿ��Ե�,��ô��Ȼ��> max([left],[right]),��ô��left+1Ϊ��ͷ��
//		K��������ɵ�����һ���ǲ������,Ϊʲô?��Ϊ�м����һ����ȻС��[left+1]�ĵ��ݲ���������,����
//		left=mid,ֱ��������ʱrightλ��,right=left+k
//	2.2 �������midλ�ò�����,left=mid,right=left+k
//����ָ�붼������,O(N)�㶨



#include<iostream>
#include<vector>
using namespace std;
class Solution
{
public:
	int KEmptySlots1(vector<int>& nums, int k)
	{
		int n = nums.size();
		vector<int>arr(n);
		for (int i = 0; i < n; i++)
			arr[nums[i] - 1] = i+1;
		int ans = INT_MAX;
		if (k == 0)//���0������,��ô����Ᵽ֤�����ڵ��ݶ�������ʱ����С�ļ���
		{
			for (int i = 1; i < n; i++)
				ans = min(ans, max(arr[i - 1], arr[i]));
		}
		else
		{
			vector<int>minq(n);//��������
			int l = 0, r = -1;
			//Ԥ��������������,ǰK��Ԫ�ص���Сֵ���м�¼
			for (int i = 1; i < n && i < k; ++i)
			{
				while (l <= r && arr[minq[r]] >= arr[i])
					r--;
				minq[++r] = i;
			}
			//�Ժ�ָ��rΪ��ֹ��������,��Ϊ��Ҫ��֤���ڵĴ���
			for (int i = 1, j = k; j < n - 1; i++, j++)
			{
				while (l <= r && arr[minq[r]] >= arr[j])
					r--;
				minq[++r] = j;
				int cur = max(arr[i-1], arr[j+1]);
				if (arr[minq[l]] > cur)
					ans = min(ans, cur);
				if (minq[l] == i)//��Сֵ���ڴ���
					l++;
			}
		}
		return ans == INT_MAX ? -1 : ans;
	}
public:
	int KEmptySlots2(vector<int>& nums, int k)
	{
		int n = nums.size();
		vector<int>arr(n);
		for (int i = 0; i < n; i++)
			arr[nums[i] - 1] = i + 1;
		int ans = INT_MAX;
		for (int left = 0, mid = 1, right = k + 1; right < n; mid++)
		{
			// ��ָ֤��mid,����ע����mid++
			// mid ��Զ����leftײ�ϵģ�
			// 1) mid��left��right�м���֤��ʱ��ûͨ����
			// 2) mid��ײ��right��ʱ��

			if (arr[mid] > max(arr[left], arr[right]))
			{
				//�������������֤
			}
			else// (arr[mid] <= max(arr[left], arr[right]))
			{
				if (mid == right)//mid��֤�Ѿ�ײ�������βright��,��֤ͨ��,��¼��
				{
					int cur = max(arr[left], arr[right]);
					ans = min(ans, cur);
					left = mid;
					right = mid + k+1;
				}
				else//��֤��ͨ��,left����,
				{
					left = mid;
					right = mid + k + 1;
				}
			}
		}
		return ans == INT_MAX ? -1 : ans;
	}
public:
	int KEmptySlots2_(vector<int>& nums, int k)
	{
		int n = nums.size();
		vector<int>arr(n);
		for (int i = 0; i < n; i++)
			arr[nums[i] - 1] = i + 1;
		int ans = INT_MAX;
		for (int left = 0, mid = 1, right = k + 1; right < n; mid++)
		{
			if (arr[mid] <= max(arr[left], arr[right]))
			{
				if (mid == right)//mid��֤�Ѿ�ײ�������βright��,��֤ͨ��,��¼��
				{
					int cur = max(arr[left], arr[right]);
					ans = min(ans, cur);				
				}
				left = mid;
				right = mid + k + 1;
			}
		}
		return ans == INT_MAX ? -1 : ans;
	}
};