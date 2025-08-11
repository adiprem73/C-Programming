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

void dfs(int node, vector<vector<int>> & adj, vector<int>& vis){
    vis[node]= 1;
    for(auto it: adj[node]){
        if(!vis[it]){
            dfs(it, adj, vis);
        }
    }    
}

int findCircleNum(vector<vector<int>>& isConnected) {
    int n=isConnected.size();
    // vector<int> adjLs[n];
    vector<vector<int>> adjLs(n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(isConnected[i][j]==1 && i!=j){
                adjLs[i].push_back(j);
                adjLs[j].push_back(i);
            }
        }
    }
    // int vis[n]={0};
    vector<int> vis(n);
    int cnt=0;
    for(int i=0;i<n;i++){
        if(!vis[i]){
            cnt++;
            dfs(i, adjLs, vis);
        }
    }
    return cnt;
}

int main() {
    FAST_IO;
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    vmat mat={{1,0,0},{0,1,0},{0,0,1}};
    cout<<findCircleNum(mat);
    return 0;
}
//by ad73prem