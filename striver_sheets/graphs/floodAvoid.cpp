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

vector<int> avoidFlood(vector<int> &rains)
{
    priority_queue<pair<int,int>> pq; // (freq, i)
    map<int,int> mp;
    int cnt_zero=0;
    for(auto it: rains){
        if(it){
            mp[it]++;
        }else{
            cnt_zero++;
        }
    }
    int cnt=0;
    // mprint(mp);
    for(auto it: mp){
        pq.push({it.second, it.first});
        if(it.second>1){
            cnt+=it.second-1;
        }
    }
    if(cnt>cnt_zero){
        return {};
    }
    vector<int> ans(rains.size());
    for(int i=0;i<rains.size();i++){
        if(rains[i]!=0){
            ans[i]=-1;
        }else{
            auto it= pq.top();
            pq.pop();
            ans[i]= it.second;
            pq.push({it.first-1, it.second});
        }
    }
    return ans;
}

int main()
{
    FAST_IO;
    vint nums={1,1,0,0};
    vint ans= avoidFlood(nums);
    vprint(ans);
    return 0;
}
//by ad73prem