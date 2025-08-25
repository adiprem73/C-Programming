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

int func(int ind, vector<int> &cost, vector<int> & dp)
{
    // base cases
    if (ind == 0)
        return cost[ind];
    if (ind == 1)
        return cost[ind];

    if(dp[ind]!=-1)return dp[ind];

    int takeOneStep = func(ind - 1, cost, dp);
    int takeTwoStep = func(ind - 2, cost, dp);
    return cost[ind] + min(takeOneStep, takeTwoStep);
}

int minCostClimbingStairs(vector<int> &cost)
{
    int n = cost.size();
    vector<int> dp(n,-1);
    
    dp[0] = cost[0];
    dp[1] = cost[1];
    
    for(int i=2;i<n;i++){
        int oneStep= dp[i-1];
        int twoStep= dp[i-2];

        dp[i]= cost[i] + min(oneStep, twoStep);
    }
    return min(dp[n-1], dp[n-2]);
}

int minCostClimbingStairsSO(vector<int> &cost)
{
    int n = cost.size();
    vector<int> dp(n,-1);
    
    // dp[0] = cost[0];
    // dp[1] = cost[1];

    int prev=cost[0];
    int curr=cost[1];
    
    for(int i=2;i<n;i++){
        // int oneStep= dp[i-1];
        // int twoStep= dp[i-2];

        // dp[i]= cost[i] + min(prev, curr);

        int temp= cost[i] + min(prev, curr);
        prev=curr;
        curr=temp;
    }
    return min(prev, curr);
}

int main()
{
    FAST_IO;
    vint nums = {10, 15, 20};
    cout << minCostClimbingStairsSO(nums);
    return 0;
}
// by ad73prem