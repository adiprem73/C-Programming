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

int func(int ind, int bag, vector<int> & weights, vector<int> & values, vector<vector<int>>& dp){
    //base cases
    // cout<<"ind : "<<ind<<" bag : "<<bag<<endl;
    if(ind ==0){
        if(weights[ind]<=bag)return bag/values[ind];
        else return 0;
    }

    if(bag==0){
        return 0;
    }

    if(dp[ind][bag]!=-1)return dp[ind][bag];

    int notPick=0+func(ind-1, bag, weights, values, dp);
    int pick=0;
    if(weights[ind]<=bag){
        pick=values[ind] + func(ind, bag-weights[ind], weights, values, dp);
    }

    return dp[ind][bag]=max(pick, notPick);
}

int knapsack(vector<int> & weights, vector<int> & values, int bag){
    int n=weights.size();
    vector<vector<int>> dp(n, vector<int> (bag+1, -1));
    return func(n-1, bag, weights, values, dp);
}

int main() {
    FAST_IO;
    vint values={10, 40, 50, 70};
    vint weights={1,3, 4, 5};
    cout<<knapsack(weights, values, 8);
    return 0;
}
//by ad73prem