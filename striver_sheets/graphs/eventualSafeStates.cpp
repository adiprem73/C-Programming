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


vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
    int n=graph.size();
    vector<int> indegree(n);
    vector<vector<int>> rgraph(n);

    //reversal and indegreeof the reversed grpah is calculated
    for(int i=0;i<n;i++){
        // i->it
        // it->i
        for(auto it: graph[i]){
            rgraph[it].push_back(i);
            indegree[i]++;
        }
    }
    queue<int> q;
    vector<int> safenode;
    for(int i=0;i<n;i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }

    while(!q.empty()){
        int node=q.front();
        q.pop();
        safenode.push_back(node);
        for(auto it: rgraph[node]){
            indegree[it]--;
            if(indegree[it]==0){
                q.push(it);
            }
        }
    }
    sort(safenode.begin(),safenode.end());
    return safenode;
}
int main() {
    FAST_IO;
    vector<vector<int>> graph={{1,2,3,4},{2,1},{3,4},{0,4},{}};
    vector<int> ans=eventualSafeNodes(graph);
    vprint(ans);
    return 0;
}
//by ad73prem