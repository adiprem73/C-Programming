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

int func(int ind, int target, vector<int> & nums, vector<vector<int>> &dp, int totalSum){
    if(ind ==0){
        if(target==0 && nums[0]==0) return 2;

        if(target==nums[0] || target== -nums[0]) return 1;
        return 0;
    }

    if(dp[ind][target +totalSum]!= -1)return dp[ind][target+totalSum];

    int plus=func(ind-1, target- nums[ind], nums, dp, totalSum);

    int minus=func(ind-1, target+ nums[ind], nums, dp, totalSum);
    return dp[ind][target+totalSum]=plus+minus;
}

int findTargetSumWays(vector<int>& nums, int target) {
    int n=nums.size();
    int totalSum=accumulate(nums.begin(), nums.end(),0);

    vector<vector<int>> dp(n, vector<int>(2* totalSum + 1, -1));
    return func(n-1, target, nums, dp, totalSum);
}

int main() {
    FAST_IO;
    vint nums={1,1,1,1,1};
    cout<<findTargetSumWays(nums, 3);
    return 0;
}
//by ad73prem