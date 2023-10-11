//���:
//����һ������arr������ÿ���˵�����ֵ��
//�ٸ���һ���Ǹ���k���������������ֵ����Ϊk��
//��ô���Դ���һ�����һ�ֱ���ֻ�������˷���������ͬʱ�ж��ٳ�����
//���:
//�����ķ�ʽ���ҵ����е�����ȫ����,Ȼ��ֱ���֤ÿһ������,�������������ܷ����K,ans++.
// 
//̰��:�Ƚ����Ź���С��ֵ,������С��ֵ.Ѱ�Ҷ���һ�����Ҳ�
// ʹ��ͬ��˫ָ��,Ҳ���ǻ�������.����Ҫ���õ�����,������Ҫ������һ��.
//left right;���[right]-[left]>k,left++;���[right]-[left]<k,right++
//���[right]-[left]==0,��¼��������,left++,right++.Ϊ�˱������ѡ���ص�,rightλ��count++֮��
//���һ��,�����Ѿ�ѡ����,����left��������ѡ��.
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution
{
public:
	int maxPairNumber(vector<int>& arr, int k)
	{
		if (k < 0 || arr.size() < 2)
			return 0;
		sort(arr.begin(), arr.end());
		int left = 0, right = 0;
		int n = arr.size();
		int ans = 0;
		vector<bool>used(n,false);
		while (right < n)
		{
			if (used[left])//left����ĵ��Ѿ��ù���
				left++;
			else if (left >= right)//������left==right����ֻ��һ����,û�����ű���.���ߴ��ڲ�����
				right++;
			else
			{
				if (arr[right] - arr[left] == k)
				{
					ans++;
					used[right] = true;
					left++, right++;
				}
				else if (arr[right] - arr[left] < k) right++;
				else if (arr[right] - arr[left] > k) left++;
			}
		}
		return ans;
	}

	//ȫ������ʾ
	int maxPairNum(vector<int>& arr, int k)
	{
		if (k < 0 || arr.size() < 2)return 0;
		return process(arr,0,k);
	}
	int process(vector<int>& arr, int index, int k)
	{
		int ans = 0;
		if (index == arr.size())
		{
			//�������
			for (int i = 1; i < arr.size(); i += 2)
			{
				if (arr[i] - arr[i - 1] == k)
					ans++;
			}
		}
		else
		{
			for (int r = index; r < arr.size(); r++)
			{
				swap(arr[r], arr[index]);
				ans = max(ans, process(arr, index + 1, k));
				swap(arr[r], arr[index]);
			}
		}
		return ans;
	}
};