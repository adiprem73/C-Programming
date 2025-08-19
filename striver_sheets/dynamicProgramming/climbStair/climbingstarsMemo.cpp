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

int climbingstairs(int ind, vector<int> & dp){
    if(ind<=1)return 1;

    if(dp[ind]!=-1){
        return dp[ind];
    }

    return dp[ind]= climbingstairs(ind-1, dp)+ climbingstairs(ind-2, dp);
}

int climbStairs(int n) {
    vector<int> dp(n+1,-1);
    int ans= climbingstairs(n,dp);
    return ans;
}

int main() {
    FAST_IO;
    int n;
    cin>>n;
    cout<<climbStairs(n);
    return 0;
}
//by ad73prem