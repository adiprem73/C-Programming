#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define f(i, a, b) for (int i = a; i < b; i++)
#define all(x) x.begin(), x.end()
#define vprint(v)            \
    for (auto &elem : v)     \
        cout << elem << " "; \
    cout << endl;
#define mprint(m)                                       \
    for (auto it : m)                                   \
        cout << it.first << " : " << it.second << endl; \
    cout << endl;
#define vint vector<int>
#define vstring vector<string>
#define vmat vector<vector<int>>
#define FAST_IO                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define pii pair<int, int>
#define pll pair<ll, ll>
#define mii map<int, int>
#define mll map<ll, ll>

const int INF = 1e9;
const ll MOD = 1e9 + 7;

class TaskManager
{

private:
    priority_queue<array<int, 3>> data; //(priority, taskId, userId)
    unordered_map<int, pair<int,int>> mp; // for optimisations of the code

public:
    TaskManager(vector<vector<int>> &tasks)
    {
        for (auto it : tasks)
        {
            data.push({it[2], it[1], it[0]});
            mp[it[1]]={it[2], it[0]}; // taskid ===> {priority, userid}
        }
        
    }

    void add(int userId, int taskId, int priority)
    {
        data.push({priority, taskId, userId});
        // data2.push_back({userId, taskId, priority});
        mp[taskId]={priority, userId};
    }

    void edit(int taskId, int newPriority)
    {
        mp[taskId].first=newPriority;
        data.push({newPriority, taskId, mp[taskId].second});
    }

    void rmv(int taskId)
    {
        mp.erase(taskId);
    }

    int execTop()
    {
        // priority_queue<array<int, 3>> copy=data;
        // cout<<"map : "<<endl;
        // for(auto it: mp){
        //     cout<<it.first<<" "<<it.second.first<<" "<<it.second.second<<endl;
        // }
        // cout<<"data : "<<endl;
        // while(!copy.empty()){
        //     auto top = copy.top();
        //     int pri = top[0];
        //     int tid = top[1];
        //     int uid = top[2];
        //     cout<<tid<<" "<<pri<<" "<<uid<<endl;
        //     copy.pop();
        // }

        while (!data.empty())
        {
            auto top = data.top(); data.pop();
            int pri = top[0];
            int tid = top[1];
            int uid = top[2];
            bool flag = false;
            auto it= mp.find(tid);
            if(it!=mp.end()){
                if (mp[tid].first == pri && mp[tid].second == uid)
                {
                    mp.erase(tid);
                    data.pop();
                    return uid;
                }

            }
            
        }
        return -1;
    }
};

int main()
{
    FAST_IO;
    vector<vector<int>> tasks={
        {9,1,31},
        {6,8,31}
    };
    TaskManager tm(tasks);
    cout<<tm.execTop()<<endl;
    tm.rmv(1);
    cout<<tm.execTop()<<endl;
    tm.add(0,11,0);
    tm.add(1,9,2);
    tm.rmv(11);
    cout<<tm.execTop()<<endl;
    tm.add(3, 7, 2);
    tm.add(5, 3, 2);
    cout<<tm.execTop()<<endl;
    tm.rmv(3);
    cout<<tm.execTop()<<endl;
    cout<<tm.execTop()<<endl;
    return 0;
}
// by ad73prem