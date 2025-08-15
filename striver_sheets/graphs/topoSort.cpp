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

void dfs(int node, vector<int>& vis, vector<vector<int>>& graph, stack<int> ans){
    vis[node]=0;
    for(auto it: graph[node]){
        if(!vis[it]){
            dfs(it, vis, graph, ans);
        }
    }
    ans.push(node);
}

vector<int> topoSort(vector<vector<int>> &graph){
    int n=graph.size();
    vector<int> vis(n,0);
    stack<int> ans;
    //assuming that the graph has 0 starting indexing
    for(int i=0;i<n;i++){
        if(!vis[i]){
            dfs(i,vis,graph,ans);
        }
    }
    vector<int> answer;
    while(!ans.empty()){
        int x=ans.top();
        ans.pop();
        answer.push_back(x);
    }
    return answer;
}

int main() {
    FAST_IO;
    
    return 0;
}
//by ad73prem