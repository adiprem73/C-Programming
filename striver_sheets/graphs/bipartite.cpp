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

bool dfs(int node, int col, int color[], vector<int> adj[]){
    color[node] = col;
    for(auto it: adj[node]){
        if(color[it]==-1){
            if(dfs(it, !col, color, adj)==false)return false;
        }
        else if(color[it]==col){
            return false;
        }
    }
    return true;
}

bool isBipartite(int V, vector<int>adj[]){
    int color[V];
    for(int i=0;i<V;i++) color[i]=-1;
    
    for(int i=0;i<V;i++){
        if(color[i]==-1){
            if(dfs(i,0,color, adj)== false){
                return false;
            }
        }

    }
    return true;
}

bool dfs(int node, int col, vector<int>& color, vector<vector<int>>& graph){
    color[node]=col;
    for(auto it: graph[node]){
        if(color[it]==-1){
            if(dfs(it, !col, color, graph)==false)return false;
        }
        else if(color[it]==col){
            return false;
        }
    }
    return true;
}

bool isBipartite(vector<vector<int>>& graph) {
    int n=graph.size();
    vector<int> color(n,-1);
    for(int i=0;i<n;i++){
        if(color[i]==-1){
            if(dfs(i,0,color,graph)==false){
                return false;
            }
        }
    }
    return true;
}

int main() {
    FAST_IO;
    
    return 0;
}
//by ad73prem