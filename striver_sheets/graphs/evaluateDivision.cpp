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

vector<double> calcEquation(vector<vector<string>> &equations, vector<double> &values, vector<vector<string>> &queries)
{
  unordered_map<string, vector<pair<string,double>>>g;
  for(int i=0;i<equations.size();i++){
    vector<string> x= equations[i];
    g[x[0]].push_back({x[1], values[i]});
    g[x[1]].push_back({x[0], 1.0/values[i]});
  }
  vector<double> ans;

  for (auto it: queries){
    string start= it[0];
    string end= it[1];
    if(start== end)ans.push_back(1.0);
    
    queue<pair<string, double>> q;
    q.push({start, 1.0});
    set<string> vis;
    bool found=false;
    while(!q.empty()){
      auto x= q.front();
      q.pop();
      
      string st= x.first;
      double val= x.second;
      vis.insert(st);
      if(st==end){
        ans.push_back(val);
        found= true;
        break;
      }

      for(auto iter: g[st]){
        
        string nst= iter.first;
        double nval= iter.second;
        if(vis.find(nst)==vis.end()){
          q.push({nst, nval*val});
        }
        
      }
    }
    if(found== false){
      ans.push_back(-1.0);
    }
    
  }
}

int main()
{
  FAST_IO;

  return 0;
}
//by ad73prem