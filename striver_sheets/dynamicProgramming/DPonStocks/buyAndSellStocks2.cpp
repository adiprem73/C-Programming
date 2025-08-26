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
int func(int ind, int buy, vector<int>& prices, vector<vector<int>> & dp){
    //base case
    int n=prices.size();
    if(ind==n){
        return 0;
    }
    if(dp[ind][buy]!=-1){
        return dp[ind][buy];
    }
    if(buy){
        return dp[ind][buy]=max((-prices[ind]+func(ind+1,0, prices, dp)),(func(ind+1,1, prices, dp)));
    }else{
        return dp[ind][buy]=max((prices[ind]+func(ind+1, 1, prices, dp)),(func(ind+1, 0, prices, dp)));
    }
}

int maxProfit(vector<int>& prices) {
    int n=prices.size();
    vector<vector<int>> dp(n, vector<int> (2, -1));
    return func(0,1, prices, dp);
}
    */

int maxProfit(vector<int> &prices)
{
    int n = prices.size();
    vector<vector<int>> dp(n + 1, vector<int>(2, 0));
    vector<int>ahead(2,0);
    ahead[0] = ahead[1] = 0;
    for (int ind = n - 1; ind >= 0; ind--)
    {
        vector<int> cur(2,0);
        for (int buy = 0; buy <= 1; buy++)
        {
            if (buy)
            {
                cur[buy] = max((-prices[ind] + ahead[0]), ahead[1]);
            }
            else
            {
                cur[buy] = max((prices[ind] + ahead[1]), (ahead[0]));
            }
        }
        ahead=cur;
    }
    return ahead[1];
}


int maxProfitSO(vector<int> & prices){
    int n = prices.size();
    long aheadBuy, aheadNotBuy, curBuy, curNotBuy;
    aheadBuy=aheadNotBuy=0;

    for (int ind = n - 1; ind >= 0; ind--)
    {
        for (int buy = 0; buy <= 1; buy++)
        {
        
            curBuy = max((-prices[ind] + aheadNotBuy), aheadBuy);
            curNotBuy = max((prices[ind] + aheadBuy), (aheadNotBuy));
        
        }
        aheadBuy=curBuy;
        aheadNotBuy=curNotBuy;
    }
    return aheadBuy;
}

int main()
{
    FAST_IO;
    vint prices = {7, 1, 5, 3, 6, 4};
    cout << maxProfitSO(prices);
    return 0;
}
// by ad73prem