#include"head.hpp"
class Solution1 {
public:
    //编写函数yeah():完成m个任务,需要ret个药丸
    //如果ret<pills,说明药丸还够,可以继续在右区间二分
    //如果ret>pills,说明药丸不够,可以继续在左区间二分
    int yeah(vector<int >&tasks,int tl,int tr,vector<int>&workers,int wl,int wr,int strength)
    {
        if (wl < 0)//workers.size()-m<0,说明工人数目不够m个任务,吃多少药也无法完成
        {
            return INT_MAX;
        }
        map<int, int> my_map;
        for (int i = tl; i <= tr; i++)
        {
            if (my_map.count(tasks[i]) == 0)
                my_map[tasks[i]] = 1;
            else
                my_map[tasks[i]]++;
        }
        int ans = 0;
        for (int i = wl; i <= wr; i++) 
        {
            //需要查找第一个小于等于workers[i]的
            //找到了,直接抵消
            //没找到,吃药之后找第一个小于等于吃完药后的
            //吃完药都没找到一个能干的任务,就无法完成

            auto job = my_map.upper_bound(workers[i]);//3
            if (job != my_map.begin())
                job--;
            else
                job = my_map.end();

            if (job != my_map.end())
            {
                //不吃药也有任务能完成
                int times = job->second;
                if (times == 1)
                    my_map.erase(job);
                else
                    job->second--;
            }
            else
            {
                //吃药
                job = my_map.upper_bound(workers[i]+strength);
                if (job != my_map.begin())
                    job--;
                else
                    job = my_map.end();

                //吃完药都没任务能完成
                if (job == my_map.end())
                    return INT_MAX;
                ans++;

                int times = job->second;
                if (times == 1)
                    my_map.erase(job);
                else
                    job->second--;
            }

        }
        return ans;
    }
    //排序需要n*logn 
    //logN*N*logN
    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) 
    {
        int l = 0;
        int r = tasks.size();
        //n个任务,选择K个任务需要完成,则选择工作量最小的K个任务,tasks[0,m-1]
        sort(tasks.begin(),tasks.end());
        //n个任务,选择K个任务需要完成,则选择能力最强的K个工人去完成,workers[workers.size()-m,workers.size()-1]
        sort(workers.begin(), workers.end());
        int ans=0;
        while (l <= r)
        {
            int m = (l + r) / 2;
            if (yeah(tasks, 0, m - 1, workers, workers.size() - m, workers.size() - 1, strength) <= pills)
            {
                ans = m;
                l=m + 1;
            }
            else
            {
                r = m - 1;
            }
        }
        return ans;
    }
};
class Solution2
{
public:
    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength)
    {
        vector<int>help(tasks.size());
        int l = 0;
        int r = tasks.size();
        int m = 0, ans = 0;
        sort(tasks.begin(),tasks.end());
        sort(workers.begin(), workers.end());

        while (l <= r)
        {
            int m = (l + r) / 2;
            if (yeah(tasks, 0, m - 1, workers, workers.size() - m, workers.size() - 1, strength,help)<=pills)
            {
                ans = m;
                l = m + 1;
            }
            else
            {
                r = m - 1;
            }
        }
        return ans;
    }
    int yeah(vector<int >& tasks, int tl, int tr, vector<int>& workers, int wl, int wr, int strength,vector<int>&help)
    {
        if (wl < 0)
            return INT_MAX;
        int l = 0;
        int r = 0;
        int ti = tl;
        int ans = 0;
        for (int wi = wl; wi <= wr; wi++)
        {
            //每次进来这个函数只用一次用于确定区间
            for (; ti <= tr && tasks[ti] <= workers[wi]; ti++)
            {
                help[r++] = ti;
            }


            if (l < r && tasks[help[l]] <= workers[wi])//不吃药就搞定
            {
                l++;
            }
            else
            {
                //吃完药之后还需要向后拓展右边届,找到能完成的最大任务
                for (; ti <= tr && tasks[ti] <= workers[wi] + strength; ti++)
                {
                    help[r++] = ti;
                }
                if (l < r)//区间存在,吃一次药,消耗掉右区间r
                {
                    ans++;
                    r--;
                }
                else//l=r说明即使吃了药都没有拓展右区间,也就代表没有能完成的任务
                {
                    return INT_MAX;
                }
            }
        }
        return ans;
    }
};
//int main()
//{
//    Solution2 s;
//    vector<int> arr;
//    arr.push_back(1);
//    arr.push_back(2);
//    arr.push_back(6);
//    arr.push_back(8);
//    arr.push_back(9);
//    vector<int> arr2;
//    arr2.push_back(4);
//    arr2.push_back(3); 
//    arr2.push_back(3); 
//    arr2.push_back(5); 
//    arr2.push_back(10);
//
//
//    cout<<s.maxTaskAssign(arr, arr2,1,1);
//    //map<int, int>u_map;
//    //u_map[0] = 1;
//    //u_map[4] = 1;
//    //u_map[6] = 1;
//    //u_map[7] = 1;
//    // 查询第一个小于等于目标值的元素
//    //auto it=u_map.upper_bound (5);//4 
//
//    //if (it != u_map.begin())
//    //    it--;
//    //else 
//    //    it = u_map.end();
//
//    //cout << (it)->first << endl;
//    return 0;
//}