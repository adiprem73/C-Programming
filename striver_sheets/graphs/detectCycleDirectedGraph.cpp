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

bool detect(int node, vector<int> &vis, vector<int> &pathvis, vector<vector<int>> &graph, vector<int> &order) {
    vis[node] = 1;
    pathvis[node] = 1;

    for (auto it : graph[node]) {
        if (vis[it] == 0) {
            if (detect(it, vis, pathvis, graph, order))
                return true; // cycle found
        } 
        else if (pathvis[it] == 1) {
            return true; // cycle found
        }
    }

    pathvis[node] = 0;
    order.push_back(node); // add to topo order after visiting all dependencies
    return false;
}

vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites) {
    vector<vector<int>> graph(numCourses);
    for (auto &p : prerequisites) {
        graph[p[1]].push_back(p[0]);
    }

    vector<int> vis(numCourses, 0), pathvis(numCourses, 0), order;
    
    for (int i = 0; i < numCourses; i++) {
        if (!vis[i]) {
            if (detect(i, vis, pathvis, graph, order)) {
                return {}; // cycle detected
            }
        }
    }

    reverse(order.begin(), order.end()); // reverse for correct topological order
    return order;
}

bool detect(int node, vector<int> & vis, vector<int> &pathvis, vector<vector<int>> &graph){
    vis[node]=1;
    pathvis[node]=1;
    for(auto it: graph[node]){
        if(vis[it]==0){
            if(detect(it, vis, pathvis, graph)==true)return true;
        }
        else if(vis[it]==1&& pathvis[it]==1){
            return true;
        }
    }
    pathvis[node]=0;
    return false;
}

bool detectCycle(vector<vector<int>> & graph){
    int n=graph.size();
    vector<int> vis(n);
    vector<int> pathvis(n);
    for(int i=1;i<n;i++){
        if(!vis[i]){
            if(detect(i, vis, pathvis, graph)==true)return true;
        }
    }
    return false;
}

int main() {
    FAST_IO;
    
    return 0;
}
//by ad73prem