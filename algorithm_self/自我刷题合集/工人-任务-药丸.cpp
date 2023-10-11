#include"head.hpp"
class Solution1 {
public:
    //��д����yeah():���m������,��Ҫret��ҩ��
    //���ret<pills,˵��ҩ�軹��,���Լ��������������
    //���ret>pills,˵��ҩ�費��,���Լ��������������
    int yeah(vector<int >&tasks,int tl,int tr,vector<int>&workers,int wl,int wr,int strength)
    {
        if (wl < 0)//workers.size()-m<0,˵��������Ŀ����m������,�Զ���ҩҲ�޷����
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
            //��Ҫ���ҵ�һ��С�ڵ���workers[i]��
            //�ҵ���,ֱ�ӵ���
            //û�ҵ�,��ҩ֮���ҵ�һ��С�ڵ��ڳ���ҩ���
            //����ҩ��û�ҵ�һ���ܸɵ�����,���޷����

            auto job = my_map.upper_bound(workers[i]);//3
            if (job != my_map.begin())
                job--;
            else
                job = my_map.end();

            if (job != my_map.end())
            {
                //����ҩҲ�����������
                int times = job->second;
                if (times == 1)
                    my_map.erase(job);
                else
                    job->second--;
            }
            else
            {
                //��ҩ
                job = my_map.upper_bound(workers[i]+strength);
                if (job != my_map.begin())
                    job--;
                else
                    job = my_map.end();

                //����ҩ��û���������
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
    //������Ҫn*logn 
    //logN*N*logN
    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) 
    {
        int l = 0;
        int r = tasks.size();
        //n������,ѡ��K��������Ҫ���,��ѡ��������С��K������,tasks[0,m-1]
        sort(tasks.begin(),tasks.end());
        //n������,ѡ��K��������Ҫ���,��ѡ��������ǿ��K������ȥ���,workers[workers.size()-m,workers.size()-1]
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
            //ÿ�ν����������ֻ��һ������ȷ������
            for (; ti <= tr && tasks[ti] <= workers[wi]; ti++)
            {
                help[r++] = ti;
            }


            if (l < r && tasks[help[l]] <= workers[wi])//����ҩ�͸㶨
            {
                l++;
            }
            else
            {
                //����ҩ֮����Ҫ�����չ�ұ߽�,�ҵ�����ɵ��������
                for (; ti <= tr && tasks[ti] <= workers[wi] + strength; ti++)
                {
                    help[r++] = ti;
                }
                if (l < r)//�������,��һ��ҩ,���ĵ�������r
                {
                    ans++;
                    r--;
                }
                else//l=r˵����ʹ����ҩ��û����չ������,Ҳ�ʹ���û������ɵ�����
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
//    // ��ѯ��һ��С�ڵ���Ŀ��ֵ��Ԫ��
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