//���:
//�������鳤��Ϊn,���ֶ��ڷ�Χ[0,n-1]�ϳ���,����������������Ϊ�����������С��������
//�±�ѭ���: 
//val:  [4,2,3,1,0]
//index: 0 1 2 3 4
//[0]=4,cur=4, curӦ�õ���[4]λ��,��[4]=0����,cur=0Ӧ�õ�0λ��,�γɱջ�,����
//[1]=2,cur=2Ӧ�õ���[2]λ��,��[2]=3����,cur=3,Ӧ�õ���[3]λ��,��[3]=1����
//cur=1,Ӧ�õ���[1]λ��,�γɱջ�,����
//��ô�����һ����·����k���ڵ�,��ôӦ�ý���k-1��
//���еĻ�֮��һ����û�н�����,�����a����,��ô���ٽ�����������n-a
//���[i]λ�ò���i,�������λ�ÿ�ʼ�±�ѭ���
//Ϊ�˽�������ʽ����ʵ��,��iλ�ú�[i]λ��ֱ�ӽ���,�ظ�����,ֱ��[i]==i.
//��һ�����ϵ��ƶ��������Ϊ����iλ�ò���.
//val:  [4,2,3,1,0]
//index: 0 1 2 3 4
//[0]=4,ֱ��swap(arr[0],arr[4]),��4��[4]λ��,����[0]==0,����,��һ��λ��
//[1]=2,ֱ��swap(arr[1],arr[2]),��2��[2]λ��,����[1]==3,
//ֱ��swap(arr[1],arr[3]),��3��[3]λ��,����[1]==1,����,��һ��λ��,
//����[i]==i,end;ֱ��ͳ�ƽ�����������

#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;
class Solution
{
public:
	int minSwap(vector<int>& arr)
	{
		int ans = 0;
		for (int i = 0; i < arr.size(); i++)
		{
			while (i != arr[i])
			{
				swap(arr[i], arr[arr[i]]);
				ans++;
			}
		}
		return ans;
	}
public:
	int minSwap_1(vector<int>& arr)
	{
		return process(arr, 0);
	}
	int process(vector<int>& arr, int times)
	{
		int n = arr.size();
		//����Ѿ�����,˵�������ɹ�,����times
		bool isSorted = true;
		for(int i=0;i<n-1;i++)
		{
			if (arr[i] > arr[i - 1])
			{
				isSorted = false;
				break;
			}
		}
		if (isSorted)
			return times;
		//��ʱ����ʱ�����
		if (times >= n - 1)
			return INT_MAX;
		int ans = INT_MAX;
		for (int i = 0; i < n; i++)
		{
			for (int j = i + 1; j < n; j++)
			{
				swap(arr[i], arr[j]);
				ans = min(ans, process(arr, times + 1));
				swap(arr[i], arr[j]);//�ָ��ֳ�,������һ����֧
			}
		}
		return ans;
	}
public:
	//����������ɢ��: 
	//[45,81,6] -> [1,2,0],ת�������������Ӧλ���±�
	void func(vector<int>& arr)
	{
		vector<int>copy(arr);
		sort(copy.begin(), copy.end());
		unordered_map<int, int> hashMap;//<key,newIndex>
		for (int i = 0; i < arr.size(); i++)
			hashMap[copy[i]] = i;
		//��arr
		for (int i = 0; i < arr.size(); i++)
			arr[i] = hashMap[arr[i]];
	}

};
//���Զ�����,��Ҫ��ʱ�临�Ӷ�,ֻҪ��֤��ȫ��ȷ,��ô�ͱ�������������,��һ����֧,
//�����������з�֧,�϶���һ������С��������,�ҵ�������
//����λ�ûص��Լ�λ��,�����κ��Ż��Ľ���,n-1�ν�����Ȼ�ܹ�����
//���Գ��Ա�����ʽ���н���ʱ,��������֧�Ѿ���������>n-1��,˵�������֧ʱ���

