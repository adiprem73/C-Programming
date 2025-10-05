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

double djikstra(unordered_map<string, vector<pair<string, double>>>& mp, vector<string> queries){
    int n=mp.size();
    unordered_map<string, double> dist;
    string source= queries[0];
    dist[source]=0;

    priority_queue<pair<double,string>, vector<pair<double,string>>, greater<pair<double,string>>> pq;
    pq.push({0.0, source});
    while(!pq.empty()){
        auto it= pq.top();
        string node= it.second;
        double weight= it.first;

        for(auto iter : mp[node]){
            string adjnode= iter.first;
            double adjWeight= iter.second;
            if(dist[adjnode]>weight* adjWeight){
                dist[adjnode]= adjWeight*weight;
                pq.push({dist[adjnode] , adjnode});
            }
        }
    }
    return dist[queries[1]];
}

    vector<double> calcEquation(vector<vector<string>> &equations, vector<double> &values, vector<vector<string>> &queries)
{
    int n=equations.size();
    
    unordered_map<string,vector<pair<string, double>>> mp;
    for (int i = 0; i <equations.size();i++){
        mp[equations[i][0]].push_back({equations[i][1], (double)values[i]});
        mp[equations[i][1]].push_back({equations[i][0], (double)1.0/values[i]});
    }

    vector<double> ans;
    ans.reserve(queries.size());
    for(auto & q: queries){
        string source= q[0];
        string destination= q[1];
        
        if(!mp.count(source) || !mp.count(destination)) {
            ans.push_back(-1.0);
            continue;
        }
        if(source == destination) {
            ans.push_back(1.0);
            continue;
        }

        // now we need to perform BFS
        unordered_set<string> vis;
        queue<pair<string, double>> qq;
        qq.push({source, 1.0});

        double found=-1.0;

        while(!qq.empty()){
            auto it= qq.front();
            string node= it.first;
            double wt= it.second;
            qq.pop();
            if(node == destination){
                found=wt;
                break;
            }

            for(auto iter: mp[node]){
                string adjnode = iter.first;
                double adjWt = iter.second;
                if(!vis.count(adjnode)){
                    vis.insert(adjnode);
                    qq.push({adjnode, wt*adjWt});
                }
            }

        }
        ans.push_back(found);
    }
    return ans;
}

int main()
{
    FAST_IO;
    
    return 0;
}
//by ad73prem