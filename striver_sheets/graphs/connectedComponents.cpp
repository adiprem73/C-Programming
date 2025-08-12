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

void dfs(int node, vector<vector<int>>& adjls, vector<int> & vis){
    vis[node]=1;
    for(auto it: adjls[node]){
        if(!vis[it]){
            dfs(it, adjls, vis);
        }
    }
}

int findNumberOfComponent(int V, vector<vector<int>> &edges) {
    vector<vector<int>> adjls(V);
    for(int i=0;i<edges.size();i++){
        adjls[edges[i][0]].push_back(edges[i][1]);
        adjls[edges[i][1]].push_back(edges[i][0]);
    }
    vector<int> vis(V,0);
    int cnt=0;
    for(int i=0;i<V;i++){
        if(!vis[i]){
            cnt++;
            dfs(i, adjls, vis);
        }
    }
    return cnt;
}

int main() {
    FAST_IO;
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    vmat mt={{0,1},{1,2}};
    cout<<findNumberOfComponent(4, mt);
    return 0;
}
//by ad73prem