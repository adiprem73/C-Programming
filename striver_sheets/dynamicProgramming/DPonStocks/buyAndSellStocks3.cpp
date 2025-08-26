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
/*Memoization
int func(int ind, int buy, int cap, vector<int> prices, vector<vector<vector<int>>> dp){
    //base cases
    if(cap==0)return 0;
    if(ind == prices.size())return 0;


    if(dp[ind][buy][cap]!=-1)return dp[ind][buy][cap];
    //if we can buy then we will take the maximum of buy and not buy
    if(buy){
        return dp[ind][buy][cap]=max(-prices[ind]+func(ind+1, 0, cap, prices, dp) , func(ind+1, 1, cap, prices, dp));
    }

    //if its the time to sell then we will take the max of sell and not sell
    else{
        return dp[ind][buy][cap]=max(prices[ind]+func(ind+1, 1, cap-1, prices, dp) , func(ind+1, 0, cap, prices, dp));
    }

}

int maxProfit(vector<int>& prices) {
    int n=prices.size();
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));

    return func(0, 1, 2, prices, dp);
}
*/

int maxProfit(vector<int> &prices)
{
    int n = prices.size();
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, 0)));

    // base cases
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= 1; j++)
        {
            dp[i][j][0] = 0;
        }
    }

    for (int j = 0; j <= 1; j++)
    {
        for (int k = 0; k < 3; k++)
        {
            dp[n][j][k] = 0;
        }
    }

    for (int ind = n-1; ind >= 0; ind--) //running the loop form n will make prices[n] og out of bounds
    {
        for (int buy = 0; buy <= 1; buy++)
        {
            for (int cap = 1; cap <= 2; cap++) //cap msu tbe gretaer than 0
            {
                if (buy)
                {
                    dp[ind][buy][cap] = max(-prices[ind] +dp[ind+1][0][cap], dp[ind+1][1][cap]);
                }

                // if its the time to sell then we will take the max of sell and not sell
                else
                {
                    dp[ind][buy][cap] = max(prices[ind] + dp[ind+1][1][cap-1], dp[ind+1][0][cap]);
                }
            }
        }
    }
    return dp[0][1][2];
}


int maxProfitSO(vector<int> &prices)
{
    int n = prices.size();
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, 0)));
    vector<vector<int>>after(2, vector<int>(3, 0));
    vector<vector<int>>curr(2, vector<int>(3, 0));
   

    for (int ind = n-1; ind >= 0; ind--) //running the loop form n will make prices[n] og out of bounds
    {
        for (int buy = 0; buy <= 1; buy++)
        {
            for (int cap = 1; cap <= 2; cap++) //cap msu tbe gretaer than 0
            {
                if (buy)
                {
                    curr[buy][cap] = max(-prices[ind] +after[0][cap], after[1][cap]);
                }

                // if its the time to sell then we will take the max of sell and not sell
                else
                {
                    curr[buy][cap] = max(prices[ind] + after[1][cap-1], after[0][cap]);
                }
            }
        }
        after = curr;
    }
    return after[1][2];
}
int main()
{
    FAST_IO;
    vint prices = {1, 2, 3, 4, 5};
    cout << maxProfit(prices);
    return 0;
}
// by ad73prem