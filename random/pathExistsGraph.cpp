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

bool dfs(int u, int destination, vector<vector<int>>& g, vector<int> &vis){
    //base case
    if(u==destination)return true;
    if(vis[u]!=0)return false; //means we have alredy visited this but we didnt found

    vis[u]=1;

    for(int v: g[u]){
        if(!vis[v] && dfs(v, destination, g, vis))return true;
    }
    return false;
}

bool validPath(int n, vector<vector<int>> &edges, int source, int destination)
{
    vector<vector<int>> g(n);
    for (auto it : edges)
    {
        g[it[0]].push_back(it[1]);
        g[it[1]].push_back(it[0]);
    }
    // make the visited array

    vector<int> vis(n, 0);
    return dfs(source, destination, g, vis);
}

int main()
{
    FAST_IO;
    vector<vector<int>> nums={
        {0,1},
        {3,5},
        {0,2},
        {5,4},
        {4,3}
    };
    cout<<validPath(6, nums, 0, 5);
    return 0;
}
//by ad73prem