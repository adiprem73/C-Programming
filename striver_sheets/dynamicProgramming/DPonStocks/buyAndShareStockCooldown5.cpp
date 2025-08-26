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
/*
MEMOIZATION
int func(int ind, int buy, vector<int>& prices, vector<vector<int>> &dp){
    //base case
    int n=prices.size();
    if(ind>=n)return 0;

    if(dp[ind][buy]!=-1)return dp[ind][buy];
    if(buy){
        return dp[ind][buy]=max(-prices[ind]+func(ind+1, 0, prices, dp) , func(ind+1, 1, prices ,dp));
    }

    else{
        return dp[ind][buy]=max(prices[ind]+func(ind+2, 1, prices ,dp) , func(ind+1, 0, prices ,dp));
    }

}

int maxProfit(vector<int>& prices) {
    int n=prices.size();
    vector<vector<int>> dp(n, vector<int>(2,-1));
    return func(0, 1, prices, dp);
}
*/

int maxProfit(vector<int> &prices)
{
    int n = prices.size();
    vector<vector<int>> dp(n + 2, vector<int>(2, 0));

    for (int ind = n - 1; ind >= 0; ind--)
    {
        for (int buy = 0; buy <= 1; buy++)
        {
            if (buy)
            {
                dp[ind][buy] = max(-prices[ind] + dp[ind+1][0], dp[ind+1][1]);
            }

            else
            {
                dp[ind][buy] = max(prices[ind] + dp[ind+2][1], dp[ind+1][0]);
            }
        }
    }
    return dp[0][1];
}

int main()
{
    FAST_IO;
    vint prices = {1, 2, 3, 0, 2};
    cout << maxProfit(prices);
    return 0;
}
// by ad73prem