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

//rod cuttingf is unbounded knapsack problem

int func(int ind, int N, vector<int> price, vector<vector<int>> dp){
    //base cases
    if(ind == 0) return N * price[0]; //index 0 corresponds to cutting the rod in 1 inches size and hence this is returned

    if(dp[ind][N]!=-1)return dp[ind][N];
    int notTake= func(ind-1, N, price, dp);
    int take=0;
    if(N>=ind+1){
        take= price[ind] + func(ind, N-(ind+1), price, dp); //ind+1 because ind is zero absed indexing but in price we have 1 based indexing corresponding to the length
    }

    return dp[ind][N]= max(take, notTake);
}

int rodCutting(vector<int> price, int n) {
    vector<vector<int>> dp(n,vector<int>(n+1, -1));
    return func(n-1,n, price, dp);
}

int main() {
    FAST_IO;
    vint price={1, 6, 8, 9, 10, 19, 7, 20};
    cout<<rodCutting(price, 8);
    return 0;
}
//by ad73prem