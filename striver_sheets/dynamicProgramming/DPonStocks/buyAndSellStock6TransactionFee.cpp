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

int func(int ind, int buy, vector<int>& prices, int n, int fee , vector<vector<int>>& dp){
    if(ind == n)return 0;
    if(dp[ind][buy]!=-1)return dp[ind][buy];
    if(buy){
        return dp[ind][buy]=max(-prices[ind]+func(ind+1, 0, prices, n, fee,dp) , func(ind+1, 1, prices, n, fee,dp));
    }
    else{
        return dp[ind][buy]=max( prices[ind]-fee+func(ind +1, 1, prices, n, fee,dp) , func(ind+1, 0, prices, n, fee,dp));
    }
}

int maxProfit(vector<int>& prices, int fee) {
    int n=prices.size();
    vector<vector<int>> dp(n, vector<int>(2, -1));
    return func(0, 1, prices, n, fee, dp);
}

int main() {
    FAST_IO;
    vint prices={1,3,7,5,10,3};
    cout<<maxProfit(prices, 3);
    return 0;
}
//by ad73prem