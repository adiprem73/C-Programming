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
        if(weights[ind]<=bag)return values[ind];
        else return 0;
    }

    if(bag==0){
        return 0;
    }

    if(dp[ind][bag]!=-1)return dp[ind][bag];

    int notPick=0+func(ind-1, bag, weights, values, dp);
    int pick=0;
    if(weights[ind]<=bag){
        pick=values[ind] + func(ind-1, bag-weights[ind], weights, values, dp);
    }

    return dp[ind][bag]=max(pick, notPick);
}

int knapsack(vector<int> & weights, vector<int> & values, int bag){
    int n=weights.size();
    vector<int> curr(bag+1,0), prev(bag+1,0);
    for(int j=0;j<=bag;j++){
        prev[j]= (weights[0]<=j)? values[0]: 0;
    }

    // for(int i=0;i<n;i++){
    //     dp[i][0] = 0;
    // }

    for(int i=1;i<n;i++){
        fill(curr.begin(), curr.end(), 0);
        for(int j=1;j<=bag;j++){
            int notPick= 0+ prev[j];

            int pick=0;
            if(weights[i]<=j){
                pick= values[i]+ prev[j-weights[i]];
            }
            curr[j]=max(pick, notPick);
        }
        prev=curr;
    }
    return prev[bag];
}


int knapsackOptimized(vector<int> & weights, vector<int> & values, int bag){
    int n=weights.size();
    vector<int> prev(bag+1,0);
    for(int j=0;j<=bag;j++){
        prev[j]= (weights[0]<=j)? ((int)bag/values[0]): 0;
    }

    // for(int i=0;i<n;i++){
    //     dp[i][0] = 0;
    // }

    for(int i=1;i<n;i++){
        for(int j=0;j<=bag>;j++){
            int notPick= 0+ prev[j];

            int pick=0;
            if(weights[i]<=j){
                pick= values[i]+ prev[j-weights[i]];
            }
            prev[j]=max(pick, notPick);
        }
    }
    return prev[bag];

}

int main() {
    FAST_IO;
    vint values={10, 40, 50, 70};
    vint weights={1,3, 4, 5};
    cout<<knapsackOptimized(weights, values, 8);
    return 0;
}
//by ad73prem