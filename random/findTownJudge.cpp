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
/*
int findJudge(int n, vector<vector<int>> &trust)
{
    if(trust.size()==0)return -1;
    if(trust.size()==1 && trust[0].size()==0)return -1;
    vector<vector<int>> gp(n+1);
    for(auto it: trust){
        gp[it[0]].push_back(it[1]);
    }
    // graph is ready
    vector<int> judgeCandidates; //ones who dont have anybody who they trust
    for(int i=1;i<=n;i++){
        if(gp[i].size()==0){
            judgeCandidates.push_back(i);
        }
    }
    // now we just need to search others. search for whom does everyone trust
    for(int it: judgeCandidates){
        bool flag=true;
        for (int i = 1; i <= n; i++)
        {
            if (i!=it)
            {
                if(find(gp[i].begin(), gp[i].end(), it)==gp[i].end()){
                    flag=false;
                    break;
                }
            }
        }
        if(flag==true){
            return it;
        }
    }return -1;
    
}
*/

int findJudge(int n, vector<vector<int>> &trust)
{
    vector<int> score(n+1);
    for(auto it: trust){
        score[it[1]]++;
        score[it[0]]--;
    }
    for(int i=1;i<n+1;i++){
        if(score[i]==n-1)return i;
    }return -1;
}

int main()
{
    FAST_IO;
    vector<vector<int>> nums={
        {}
    };
    cout<<findJudge(3, nums);
    return 0;
}
//by ad73prem