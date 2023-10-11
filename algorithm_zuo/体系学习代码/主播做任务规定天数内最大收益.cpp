//CC直播的运营部门组织了很多运营活动，每个活动需要花费一定的时间参与，主播每参
//加完一个活动即可得到一定的奖励，参与活动可以从任意活动开始，但一旦开始，就需
//要将后续活动参加完毕（注意：最后一个活动必须参与），活动之间存在一定的依赖关
//系（不存在环的情况），现在给出所有的活动时间与依赖关系，以及给出有限的时间，
//请帮主播计算在有限的时候内，能获得的最大奖励，以及需要的最少时长。
//输入描述：
//第一行输入数据N与D，表示有N项活动，D表示给予的时长。0＜N＜＝1000，0＜D＜＝10000。
//从第二行开始到N + 1行，每行描述一个活动的信息，其中第一项表示当前活动需要花费的时间t，第二项表示可以获
//得的奖励a，之后有N项数据，表示当前活动与其他活动的依赖关系，1表示有依赖，0表示无依赖。每项数据用空格
//分开。
// 输入
//8 10
//3 2000 0 1 1 0 0 0 0 0     A 后序节点有B和C两个
//3 4000 0 0 0 1 1 0 0 0
//2 2500 0 0 0 1 0 0 0 0
//1 1600 0 0 0 0 1 1 1 0
//4 3800 0 0 0 0 0 0 0 1
//2 2600 0 0 0 0 0 0 0 1
//4 4000 0 0 0 0 0 0 0 1
//3 3500 0 0 0 0 0 0 0 0

//输出描述：输出两项数据A与T，用空格分割。A表示所获得的最大奖励，T表示所需要的时长。
//输出11700 9
// 
// 
// 
//思路: 
// 注意:可以选择任何一个节点开始做任务,但是最后一个必须做,也就是每条路径的结尾都是end节点
// 1. 既然都需要做到最后一个任务,那么就从最后一个任务开始向前找,将倒数第二个节点中<天数,收益>进行更新,
//	  然后依次再往前找倒数第三个节点...
// 2. 每个节点都维护一张表,记录不同路径中,每个路径都有一个<天数,收益>记录,让这张表是有序表map,即天数递增,收益必须递增,否则删除
//	  贪心思路: 我既然能用更少的天数获取更好的收益,那我为什么要做别的呢?
// 将每个节点内数据更新之后,进行节点表内数据清洗,然后进行所有表整合,也就是所有节点互联
// 为什么不直接使用一张表,最开始就互联?因为某一个很差劲的节点之前可能有一个巨牛逼的点,你把它删了就找不到之前的了
// 3. 将所有的表进行整合,维护单调性,天数增加收益增加;
//	  然后根据每个主播自己的天数day,找到<=day的最大天数以及收益.

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
		//本来可以依据矩阵图建立每个节点下一个依赖节点放到vector<>中
		//1. 但是我们是需要从最后一个节点往前找,所以我们记录每个节点的上一个节点有哪些
		unordered_map<int, vector<int>> parents;
		int end = -1;	//记录最后一个节点编号
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
			if (rowAllZero)//没孩子的肯定是最后一个节点
				end = i;
		}
		//2. 每一个点中维护一张有序表,<cost天数,收益>,<cost天数,收益>...随着路径(链表维护)更新
		//map<int, int> signleNoderevenue;
		//typedef map<int, int>::iterator it;
		//unordered_map<int, it> nodeCostRevenue;//<节点编号,reveue表>

		unordered_map<int, map<int, int>> nodeCostRevenue;//<节点编号,reveue表有序表>
		nodeCostRevenue[end].insert(make_pair(times[end], revenue[end]));

		list<int> lt;
		lt.push_back(end);
		while (!lt.empty())
		{
			int cur = lt.front(); lt.pop_front();
			for (int last : parents[cur])//更新前一个节点的表,前一个节点有很多可能
			{
				for (auto node_map : nodeCostRevenue[cur])//使用cur节点值来更新parent节点
				{
					int lastCost = node_map.first + times[last];
					int lastRevenue = node_map.second + revenue[last];
					//每个节点维护一张有序表<天数,收益>,控制单调性,随着天数增加,收益严格递增
					map<int, int> lastMap;	
					//实现floorkey()
					int key = -1;
					auto it = lastMap.lower_bound(lastCost);
					//if (it == lastMap.begin()) return it->first; --it; return it->first; 找到小于等于他最近的那个数
					if (it == lastMap.begin()) key = it->first;
					else --it, key = it->first;
					if (it != lastMap.end() || lastMap[key]< lastRevenue)
						lastMap.insert({lastCost,lastRevenue});
				}
				lt.push_front(last);//插入路径链表,方便使用它更新它前一个节点的表
			}
		}
		//3. 将所有节点的有序表进行整合,控制单调性,随着天数增加,收益严格递增
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
		//4. 选出有序表中时间小于等于自己最近的那个天数,对应的最大收益
		int ret_key = -1,ret_revenue=-1;
		auto it1 = allMap.lower_bound(allTime);
		if (it1 == allMap.begin())
			ret_key = it1->first,ret_revenue=it1->second;
		else --it1, ret_key = it1->first, ret_revenue = it1->second;

		return { ret_key ,ret_revenue };
	}
};