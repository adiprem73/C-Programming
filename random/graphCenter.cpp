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

int findCenter(vector<vector<int>> &edges)
{
    int n=INT_MIN;
    for(auto it: edges){
        n=max(n,max(it[0], it[1]));
    }
    vector<vector<int>> gph(n+1);
    for (auto it : edges)
    {
        // cout<<it[0]<<" "<<it[1]<<endl;
        // the two nodes are it[0] and it[1]
        gph[it[0]].push_back(it[1]);
        gph[it[1]].push_back(it[0]);
        // for (auto it : gph)
        // {
        //     vprint(it);
        // }
    }
    // cout<<"HEllo"<<endl;
    // for(auto it: gph){
    //     vprint(it);
    // }
    for (int i = 1; i <= n; i++)
    {
        // vprint(gph[i]);
        if (gph[i].size() == n - 1)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    FAST_IO;
    vector<vector<int>> edges={
        {1,2},
        {5,1},
        {1,3},
        {1,4}
    };
    cout<<findCenter(edges);
    return 0;
}
//by ad73prem