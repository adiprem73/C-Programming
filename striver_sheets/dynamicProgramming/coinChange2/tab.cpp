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

int func(int ind, int amount, vector<int> &coins, vector<vector<int>>& dp)
{
    // base case
    if (amount == 0)
        return 1;
    if (ind < 0)
        return 0;
    if (amount < 0)
        return 0;

    if(dp[ind][amount]!=-1)return dp[ind][amount];
    int notPick = func(ind - 1, amount, coins, dp);
    int pick = 0;
    if (coins[ind] <= amount)
    {
        pick = func(ind, amount - coins[ind], coins, dp);
    }
    return dp[ind][amount]=pick + notPick;
}

int change(int amount, vector<int> &coins)
{
    int n = coins.size();
    vector<vector<ll>> dp(n, vector<ll> (amount+1, 0));
    //base cases
    

    for(int j=0;j<amount+1;j++){
        if(j% coins[0]==0) dp[0][j]=1;
    }

    for(int i=1;i<n;i++){
        for(int j=0;j<amount+1;j++){
            int notPick= dp[i-1][j];

            int pick=0;
            if(coins[i]<=j){
                pick=dp[i][j-coins[i]];
            }

            dp[i][j]= pick+notPick;
        }
    }

    return dp[n-1][amount];
}

int changeSO(int amount, vector<int> & coins){
    int n = coins.size();
    vector<int> prev(amount+1 , 0), curr(amount+1 , 0);

    for(int j=0;j<=amount;j++){
        prev[j]= ((j% coins[0])==0);
    }

    for(int i=1;i<n;i++){
        fill(curr.begin(), curr.end(), 0);
        for(int j=0;j<=amount;j++){
            int notPick = prev[j];

            int pick=0;
            if(coins[i]<=j){
                pick = curr[j-coins[i]];
            }
            curr[j]= pick +notPick;
        }
        prev=curr;
    }
    return prev[amount];

}

int main() {
    FAST_IO;
    vint coins = {1,2,5};
    cout << changeSO(5, coins);    
    return 0;
}
//by ad73prem