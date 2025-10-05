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

bool compare(pair<string, int> a, pair<string, int>b){
    if(a.second!=b.second)return a.second<b.second;
    return a.first<b.first;
}

vector<string> watchedVideosByFriends(vector<vector<string>> &watchedVideos, vector<vector<int>> &friends, int id, int level)
{
    queue<pair<int, int>> q; // (id, level)
    q.push({id, 0});
    map<string, int> mp;
    unordered_set<int> vis;
    vis.insert(id);
    while(!q.empty()){
        auto it= q.front();
        q.pop();
        int person= it.first;
        int currlevel= it.second;
        if(currlevel == level){
            for(auto x: watchedVideos[person]){
                mp[x]++;
            }
            continue;
        }
        if(currlevel<level){
            for (auto frnd : friends[person])
            {
                if (vis.find(frnd) == vis.end())
                {
                    q.push({frnd, currlevel + 1});
                    vis.insert(frnd);
                }
            }
        }
         
    }
    // now we need to prepare the vector from t he map
    vector<pair<string, int>> items(mp.begin(), mp.end());
    sort(items.begin(), items.end(), compare);
    vector<string> ans;
    for(auto it: items){
        ans.push_back(it.first);
    }
    return ans;
}

int main()
{
    FAST_IO;
    vector<vector<string>> wv={
        {"A", "B"},
        {"C"},
        {"B", "C"},
        {"D"}
    };
    vector<vector<int>> frnds={
        {1,2},
        {0,3},
        {0,3},
        {1,2}
    };
    vprint(watchedVideosByFriends(wv, frnds, 0 , 1));
    return 0;
}
//by ad73prem