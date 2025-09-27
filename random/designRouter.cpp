#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define f(i, a, b) for(int i=a;i<b;i++)
#define all(x) x.begin(),x.end()
#define vprint(v) for (auto& elem : v) cout << elem << " "; cout << endl;
#define mprint(m) for (auto it:m) cout<<it.first<<" : "<<it.second<<endl; cout<<endl;
#define vint vector<int>
#define vstring vector<string>
#define vmat vector<vector<int>>
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define pii pair<int,int>
#define pll pair<ll,ll>
#define mii map<int,int>
#define mll map<ll,ll>

const int INF = 1e9;
const ll MOD = 1e9+7;

struct Array3Hash
{
    size_t operator()(const array<int, 3> &a) const noexcept
    {
        // combine three ints into one hash (simple and fine here)
        size_t h = std::hash<long long>()(((long long)a[0] << 32) ^ (unsigned int)a[1]);
        h ^= std::hash<int>()(a[2]) + 0x9e3779b97f4a7c15ULL + (h << 6) + (h >> 2);
        return h;
    }
};

class Router
{
private:
    queue<array<int,3>>q;
    unordered_set<array<int,3>, Array3Hash>st; //for faster lookups
    map<int, set<pair<int,int>>> mp;
    int memLimit;
public:
    Router(int memoryLimit)
    {
        memLimit=memoryLimit;
    }

    bool addPacket(int source, int destination, int timestamp)
    {
        if(st.count({source, destination, timestamp})!=0){
            return false;
        }
        bool flag;
        if(st.size()<memLimit){
            if(st.count({source, destination, timestamp})==0){
                flag= true;
                st.insert({source, destination, timestamp});
                q.push({source, destination, timestamp});
                mp[destination].insert({timestamp, source});
            }
            else{
                flag=false;
            }
        }else{
            auto it= q.front();
            q.pop();
            st.erase(it);
            mp[it[1]].erase({it[2], it[0]});
            if (st.count({source, destination, timestamp}) == 0)
            {
                flag = true;
                st.insert({source, destination, timestamp});
                q.push({source, destination, timestamp});
                mp[destination].insert({timestamp, source});
            }
            else
            {
                flag = false;
            }
        }
        return flag;
    }

    

    vector<int> forwardPacket()
    {
        if(q.empty())return {};
        auto it = q.front();
        q.pop();
        st.erase(it);
        mp[it[1]].erase({it[2], it[0]});
        if(mp[it[1]].empty()) mp.erase(it[1]);
        return {it[0], it[1], it[2]};
    }

    int getCount(int destination, int startTime, int endTime)
    {
        int cnt=0;
        for(auto it: mp[destination]){
            if(it.first>=startTime&& it.first<=endTime){
                cnt++;
            }
        }
        return cnt;
    }
};

int main() {
    FAST_IO;
    Router rt(2);
    cout<<rt.addPacket(1,4,1)<<endl;
    cout << rt.addPacket(5, 4, 1)<<endl;
    cout << rt.addPacket(1,4,1) << endl;
    
    return 0;
}
//by ad73prem