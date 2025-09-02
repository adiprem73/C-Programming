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

vector<int> topKFrequent(vector<int>& nums, int k) {
    priority_queue<pair<int,int>> pq;
    map<int,int> mp;
    for(auto it: nums){
        mp[it]++;
    }
    for(auto it: mp){
        pq.push({it.second, it.first});
    }

    vector<int> ans;
    for(int i=0;i<k;i++){
        ans.push_back(pq.top().second);
        pq.pop();
    }
    return ans;
}

int main() {
    FAST_IO;
    vint nums={1,2,1,2,1,2,3,1,3,2};
    vint ans=topKFrequent(nums, 2);
    vprint(ans);
    return 0;
}
//by ad73prem