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
int func(int ind , int prevInd, vector<int>& nums, int n){
    //base case
    if(ind==n)return 0;

    int notTake= func(ind+1, prevInd, nums, n);

    int take=0;
    if(prevInd==-1 || nums[prevInd]< nums[ind]){
        take = func(ind+1, ind, nums, n)+1;
    }
    return max(take, notTake);

}

int lengthOfLIS(vector<int>& nums) {
    int n=nums.size();
    return func(0, -1, nums, n);
}


int func(int ind, int prevInd, vector<int> &nums, int n, vector<vector<int>> &dp)
{
    // base case
    if (ind == n)
        return 0;

    if(dp[ind][prevInd+1]!=-1)return dp[ind][prevInd+1];

    int notTake = func(ind + 1, prevInd, nums, n,dp);

    int take = 0;
    if (prevInd == -1 || nums[prevInd] < nums[ind])
    {
        take = func(ind + 1, ind, nums, n,dp) + 1;
    }
    return dp[ind][prevInd+1]=max(take, notTake);
}

int lengthOfLIS(vector<int> &nums)
{
    int n = nums.size();
    vector<vector<int>> dp(n, vector<int>(n+1,-1));
    return func(0, -1, nums, n, dp);
}
*/

int lengthOfLIS(vector<int> &nums)
{
    int n = nums.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    for (int ind = n - 1; ind >= 0; ind--)
    {
        for (int prevInd = -1; prevInd < ind; prevInd++)
        {
            int notTake = dp[ind+1][prevInd+1];

            int take = 0;
            if (prevInd == -1 || nums[prevInd] < nums[ind])
            {
                take = dp[ind+1][ind+1] + 1;
            }
            dp[ind][prevInd+1] = max(take, notTake);
        }
    }
    for(auto it: dp){
        vprint(it);
    }
    return dp[0][0];
}


int lengthOfLISso(vector<int> &nums)
{
    int n = nums.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    vector<int>ahead(n + 1, 0);
    for (int ind = n - 1; ind >= 0; ind--)
    {
        vector<int>curr(n + 1, 0);
        for (int prevInd = -1; prevInd < ind; prevInd++)
        {
            int notTake = ahead[prevInd+1];

            int take = 0;
            if (prevInd == -1 || nums[prevInd] < nums[ind])
            {
                take = ahead[ind+1] + 1;
            }
            curr[prevInd+1] = max(take, notTake);
        }
        ahead=curr;
    }
    
    return ahead[0];
}

int main()
{
    FAST_IO;
    vint nums = {0, 1, 0, 3, 2, 3};
    cout << lengthOfLISso(nums);
    return 0;
}
// by ad73prem