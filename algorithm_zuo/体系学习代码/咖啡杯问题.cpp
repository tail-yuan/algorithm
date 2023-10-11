#include<iostream>
#include<vector>
#include<queue>
using namespace std;
//1. index��ŵĿ��Ȼ����һ�����ȵ�ʱ��
//2. n����Ҫ��
//3. ϴ���ӵĻ���ϴ��һ����������ʱ��
//4. ���Ӳ�ϴ,��Ȼ�ӷ���ʱ��
// �õ�����,�������
//������Щ�˺���+���Ӹɾ�,������Ҫ�೤ʱ��?

// �ȿ�������ôѡ��̨����?���Ż�������,�ĸ������Ƚ���-----̰��
// ͬ��,С����ά��time+cost <time/*timeʱ�̻�������*/,cost/*�ݿ�������ʱ��*/> ���ĸ�������һ������
// ����tmp��¼ÿ���˿ɻ�ȡ�����ȵ�ʱ��
// �����Ѷ�������Ŀɻ�û�����ʱ��,->tmp[i]
// ������֮��,��<time+cost,cost>����->С����
// �ֵ���һ���˻�ȡ...

// ��Ϊ�ȿ���ʱ�����,�õ����ȵ�ʱ����ǿ�ʼϴ��ʱ��------�����ݹ�->����
// Ҳ������tmp�����˳��ѡ��ϴ�����?
// 1. ϴ���Ȼ��� 2. �ӷ�
// �����ұ����ݹ� index�±걭��ʼϴ, washline ���ĸ�ʱ����п�
// zuo()�������Ҫϴ��[index...N-1]�������ٵ�ʱ��,����������������ʱ��

class CoffeCup
{
public:
	class Machine
	{
	public:
		int timePoint;
		int workTime;
		Machine(int t, int w)
			:timePoint(t)
			, workTime(w)
		{}
	};
	struct Greater
	{
		bool operator()(Machine& m1, Machine& m2)
		{
			return (m1.timePoint + m1.workTime) - (m2.timePoint + m2.workTime);
		}
	};
	int getMin(vector<int>&arr,int n,int a,int b)
	{
		priority_queue<Machine, vector<Machine>, Greater()>heap;//С��
		for (int i = 0; i < arr.size(); i++)
			heap.push(Machine(0,arr[i]));
		vector<int>drink(n);
		for (int i = 0; i < n; i++)
		{
			Machine cur = heap.top();
			heap.pop();
			cur.timePoint += cur.workTime;
			drink[i] = cur.timePoint;//��ȡ�����ȵ�ʱ��(���Կ�ʼϴ��ʱ��)
			heap.push(cur);
		}
		return zuo(drink,a,b,0,0);
	}
	int zuo(vector<int>& drink, int a, int b, int index, int washLine)
	{
		//��ʣ���һ��ʱ����ѡ��
		if(index==drink.size()-1)
			return min(max(washLine, drink[index]) + a, drink[index] + b);
		//				  ��������ʱ���,ĳ��Ҫϴ��ʱ��� ȡ��ֵ����˼�������������߱�
		//                ѡϴ����ѡ�ӷ�ʱ��С���Ǹ�
		//��ʣ��ֹһ������
		//1. ��ѡ����ϴ
		int wash = max(drink[index], washLine) + a;
		//   ϴ��������п��ȵ�ʱ���,��Ȼ��ѡ�˻���ϴ,��ô����ľ͵����ҵ�Ӱ��,Ҳ��������ϴ��֮��������п�ϴ����,��washʱ����
		int next1 = zuo(drink,a,b,index+1,wash);
		//��ϴ��ʱ���     ����ȫϴ��ʱ���  max����ʹ�������ֶ�����,Ҳ��������ѡ���¶�ϴ���ʱ���p1
		int p1 = max(wash,next1);

		//2. ��ѡ�ӷ�
		int dry = drink[index] + b;
		//   ϴ��������п��ȵ�ʱ���,��Ȼ��ûѡ�˻���ϴ,
		//��ô����ľͲ����ҵ�Ӱ��,Ҳ���������ھͿ���,��washLineʱ����
		int next2 = zuo(drink,a,b,index+1,washLine);
		int p2 = max(dry,next2);

		return  min(p1,p2);
	}
	// 1. index [0,n-1] washLine [0,sum]sum�����б��Ӷ��û���ϴ����ʱ��
	//	  [3,    19,                   33,37,100] 
	//    �ֵ�19�Ǹ���ʱ3+aʱ����ȡ��ϴ����,ϴ���ʱ���b=max(19+a/*�ҵ��Ⱥ���+ϴ��ʱ���*/,3+a+a/*ϴ��������ʱ���*/)
	//    �ֵ�33ʱ,��bʱ����ȡ��ϴ����,c = max(b+a,33+a)
	//	  ...�õ�washLine ���ֵ   
	//    drink[n-1]+n*a����n��a ʱ��,ֻҪ�ռ俪���㹻���� -> drink[index] + (index + 1) * a;
	// 2. dp[n][ drink[n-1]+n*a]  
	// 3. return dp[0][0]����������


	int getMinDP(vector<int>& arr, int n, int a, int b)
	{
		priority_queue<Machine, vector<Machine>, Greater()>heap;//С��
		for (int i = 0; i < arr.size(); i++)
			heap.push(Machine(0, arr[i]));
		vector<int>drink(n);
		for (int i = 0; i < n; i++)
		{
			Machine cur = heap.top();
			heap.pop();
			cur.timePoint += cur.workTime;
			drink[i] = cur.timePoint;//��ȡ�����ȵ�ʱ��(���Կ�ʼϴ��ʱ��)
			heap.push(cur);
		}
		vector<vector<int>> dp(n, vector<int>(drink[n - 1] + n * a));
		for(int i=0;i<dp[0].size();i++)
			dp[n-1][i]= min(max(i, drink[n-1]) + a, drink[n-1] + b);
		for (int index = n - 2; index >= 0; index--)
		{
			int washLine = drink[index] + (index + 1) * a;
			for (int col = 0; col <washLine; col++)
			{
				int wash = max(drink[index], washLine) + a;//ʹ�û���ϴӦ����ת��λ��
				dp[index][col] = min(max(wash, dp[index + 1][wash]), max(drink[index] + b, dp[index][col]));
			}
		}
		return dp[0][0];
	}
};