//CCֱ������Ӫ������֯�˺ܶ���Ӫ���ÿ�����Ҫ����һ����ʱ����룬����ÿ��
//����һ������ɵõ�һ���Ľ������������Դ�������ʼ����һ����ʼ������
//Ҫ��������μ���ϣ�ע�⣺���һ���������룩���֮�����һ����������
//ϵ�������ڻ�������������ڸ������еĻʱ����������ϵ���Լ��������޵�ʱ�䣬
//����������������޵�ʱ���ڣ��ܻ�õ���������Լ���Ҫ������ʱ����
//����������
//��һ����������N��D����ʾ��N����D��ʾ�����ʱ����0��N����1000��0��D����10000��
//�ӵڶ��п�ʼ��N + 1�У�ÿ������һ�������Ϣ�����е�һ���ʾ��ǰ���Ҫ���ѵ�ʱ��t���ڶ����ʾ���Ի�
//�õĽ���a��֮����N�����ݣ���ʾ��ǰ����������������ϵ��1��ʾ��������0��ʾ��������ÿ�������ÿո�
//�ֿ���
// ����
//8 10
//3 2000 0 1 1 0 0 0 0 0     A ����ڵ���B��C����
//3 4000 0 0 0 1 1 0 0 0
//2 2500 0 0 0 1 0 0 0 0
//1 1600 0 0 0 0 1 1 1 0
//4 3800 0 0 0 0 0 0 0 1
//2 2600 0 0 0 0 0 0 0 1
//4 4000 0 0 0 0 0 0 0 1
//3 3500 0 0 0 0 0 0 0 0

//��������������������A��T���ÿո�ָA��ʾ����õ��������T��ʾ����Ҫ��ʱ����
//���11700 9
// 
// 
// 
//˼·: 
// ע��:����ѡ���κ�һ���ڵ㿪ʼ������,�������һ��������,Ҳ����ÿ��·���Ľ�β����end�ڵ�
// 1. ��Ȼ����Ҫ�������һ������,��ô�ʹ����һ������ʼ��ǰ��,�������ڶ����ڵ���<����,����>���и���,
//	  Ȼ����������ǰ�ҵ����������ڵ�...
// 2. ÿ���ڵ㶼ά��һ�ű�,��¼��ͬ·����,ÿ��·������һ��<����,����>��¼,�����ű��������map,����������,����������,����ɾ��
//	  ̰��˼·: �Ҽ�Ȼ���ø��ٵ�������ȡ���õ�����,����ΪʲôҪ�������?
// ��ÿ���ڵ������ݸ���֮��,���нڵ����������ϴ,Ȼ��������б�����,Ҳ�������нڵ㻥��
// Ϊʲô��ֱ��ʹ��һ�ű�,�ʼ�ͻ���?��Ϊĳһ���ܲ�Ľڵ�֮ǰ������һ����ţ�Ƶĵ�,�����ɾ�˾��Ҳ���֮ǰ����
// 3. �����еı��������,ά��������,����������������;
//	  Ȼ�����ÿ�������Լ�������day,�ҵ�<=day����������Լ�����.

#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
#include<map>
using namespace std;
class getMaxRevenue
{
public:
	vector<int> getMax(int allTime, vector<int>& revenue, vector<int>& times, vector<vector<int>>& depend)
	{
		int size = revenue.size();
		//�����������ݾ���ͼ����ÿ���ڵ���һ�������ڵ�ŵ�vector<>��
		//1. ������������Ҫ�����һ���ڵ���ǰ��,�������Ǽ�¼ÿ���ڵ����һ���ڵ�����Щ
		unordered_map<int, vector<int>> parents;
		int end = -1;	//��¼���һ���ڵ���
		for (int i = 0; i < depend.size(); i++)
		{
			bool rowAllZero = true;
			for (int j = 0; j < depend[0].size(); j++)
			{
				if (depend[i][j] == 1)
				{
					parents[j].push_back(i);
					rowAllZero = false;
				}
			}
			if (rowAllZero)//û���ӵĿ϶������һ���ڵ�
				end = i;
		}
		//2. ÿһ������ά��һ�������,<cost����,����>,<cost����,����>...����·��(����ά��)����
		//map<int, int> signleNoderevenue;
		//typedef map<int, int>::iterator it;
		//unordered_map<int, it> nodeCostRevenue;//<�ڵ���,reveue��>

		unordered_map<int, map<int, int>> nodeCostRevenue;//<�ڵ���,reveue�������>
		nodeCostRevenue[end].insert(make_pair(times[end], revenue[end]));

		list<int> lt;
		lt.push_back(end);
		while (!lt.empty())
		{
			int cur = lt.front(); lt.pop_front();
			for (int last : parents[cur])//����ǰһ���ڵ�ı�,ǰһ���ڵ��кܶ����
			{
				for (auto node_map : nodeCostRevenue[cur])//ʹ��cur�ڵ�ֵ������parent�ڵ�
				{
					int lastCost = node_map.first + times[last];
					int lastRevenue = node_map.second + revenue[last];
					//ÿ���ڵ�ά��һ�������<����,����>,���Ƶ�����,������������,�����ϸ����
					map<int, int> lastMap;	
					//ʵ��floorkey()
					int key = -1;
					auto it = lastMap.lower_bound(lastCost);
					//if (it == lastMap.begin()) return it->first; --it; return it->first; �ҵ�С�ڵ�����������Ǹ���
					if (it == lastMap.begin()) key = it->first;
					else --it, key = it->first;
					if (it != lastMap.end() || lastMap[key]< lastRevenue)
						lastMap.insert({lastCost,lastRevenue});
				}
				lt.push_front(last);//����·������,����ʹ����������ǰһ���ڵ�ı�
			}
		}
		//3. �����нڵ��������������,���Ƶ�����,������������,�����ϸ����
		map<int, int> allMap;
		for (auto curMapIt : nodeCostRevenue)
		{
			for (auto entry : curMapIt.second)
			{
				int costTime = entry.first;
				int cur_revenue = entry.second;
				int key = -1;
				auto it = allMap.lower_bound(costTime);
				if (it == allMap.begin()) key = it->first;
				else --it, key = it->first;

				if (it==allMap.end() || allMap[key] < cur_revenue)
					allMap.insert({costTime,cur_revenue});
			}
		}
		//4. ѡ���������ʱ��С�ڵ����Լ�������Ǹ�����,��Ӧ���������
		int ret_key = -1,ret_revenue=-1;
		auto it1 = allMap.lower_bound(allTime);
		if (it1 == allMap.begin())
			ret_key = it1->first,ret_revenue=it1->second;
		else --it1, ret_key = it1->first, ret_revenue = it1->second;

		return { ret_key ,ret_revenue };
	}
};