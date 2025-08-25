#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define f(i, a, b) for (int i = a; i < b; i++)
#define all(x) x.begin(), x.end()
#define vprint(v)            \
    for (auto &elem : v)     \
        cout << elem << " "; \
    cout << endl;
#define mprint(m)                                       \
    for (auto it : m)                                   \
        cout << it.first << " : " << it.second << endl; \
    cout << endl;
#define vint vector<int>
#define vstring vector<string>
#define vmat vector<vector<int>>
#define FAST_IO                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define pii pair<int, int>
#define pll pair<ll, ll>
#define mii map<int, int>
#define mll map<ll, ll>

const int INF = 1e9;
const ll MOD = 1e9 + 7;

int func(int ind, int target, vector<int> &coins, vector<vector<int>> &dp)
{
    // base case
    //  cout<<"ind : "<<ind<<" target : "<<target<<endl;
    if (ind == 0)
    {
        if (target % coins[ind] == 0)
            return (target / coins[ind]);
        else
            return 1e9;
    }

    if (dp[ind][target] !=-1)
        return dp[ind][target];
    int notPick = 0 + func(ind - 1, target, coins, dp);

    int pick = INT_MAX;

    if (coins[ind] <= target)
    {
        pick = 1 + func(ind, target - coins[ind], coins, dp);
    }

    return dp[ind][target] = min(pick, notPick);
}

int coinChange(vector<int> &coins, int amount)
{
    int n = coins.size();
    vector<vector<int>> dp(n, vector<int>(amount + 1, -1));

    for(int j=0;j<=amount;j++){
        if(j% coins[0]==0) dp[0][j]= j/ coins[0];
        else dp[0][j]=1e9;
    }

    for(int i=0;i<n;i++){
        dp[i][0]=0; //if the amount is zero then we dont need to have any coins hence the number of min coins is zero
    }
    
    for(int i=1;i<n;i++){
        for(int j=0;j<=amount;j++){
            int notPick= dp[i-1][j];
            int pick = 1e9;
            if(coins[i]<=j){
                pick = 1+ dp[i][j - coins[i]];
            }

            dp[i][j]= min(pick, notPick);
        }
    }
    int ans=dp[n-1][amount];
    if(ans==1e9)return -1;
    else return ans;
}

int main()
{
    FAST_IO;
    vint coins = {1, 2, 5};
    int amt = 11;
    cout << coinChange(coins, amt);
    return 0;
}
// by ad73prem