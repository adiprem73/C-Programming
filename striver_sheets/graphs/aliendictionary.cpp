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

string findORder(vector<string> & dict, int n, int k){
    //n i shte number of words in the dictionary
    // k is the number of ndoes in the graph that is alpahbets starting from a

    vector<vector<int>>adj(k);
    for(int i=0;i<n-1;i++){
        string word1=dict[i];
        string word2=dict[i+1];
        int len=min(word1.size(),word2.size());
        for(int j=0;j<len;j++){
            if(word1[j]!=word2[j]){
                adj[word1[j]-'a'].push_back(word2[j]-'a'); //construct the required adjacency list
                break; //since only the first diferetnt charatcer matters
            }
        }
    }

    //now isnce we have the adjacency list we jsut need to top sort it
    //start by prepareing the indegree
    vector<int> indegree(n);
    for(int i=0;i<k;i++){
        for(auto it: adj[i]){
            indegree[it]++;
        }
    }

    queue<int> q;
    for(int i=0;i<k;i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }

    vector<int> topo;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        topo.push_back(node);
        for(auto it: adj[node]){
            indegree[it]--;
            if(indegree[it]==0){
                q.push(it);
            }
        }
    }

    string ans;
    for(int i=0;i<k;i++){
        ans+=(topo[i]+'a');
    }
    return ans;
}

int main() {
    FAST_IO;
    vector<string> dict={"baa","abcd","abca","cab","cad"};
    cout<<findORder(dict, 5,4);
    return 0;
}
//by ad73prem