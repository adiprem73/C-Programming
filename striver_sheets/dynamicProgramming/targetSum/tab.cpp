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

    if(abs(target)>totalSum) return 0;
    vector<vector<int>> dp(n, vector<int>(2* totalSum + 1, -1));

    for(int j=-totalSum ; j<=totalSum ; j++){
        if (nums[0]==0 && j==0) dp[0][j+totalSum]=2;
        else if (j==nums[0] || j==-nums[0]) dp[0][j+totalSum]=1;
        else dp[0][j+ totalSum] = 0;
    }
    

    for(int i=1;i<n;i++){
        for(int j=-totalSum;j<=totalSum;j++){
            int plus=(j-nums[i] >= -totalSum)? dp[i-1][j- nums[i]+totalSum] : 0;

            int minus=(j+nums[i] <= totalSum)? dp[i-1][j+ nums[i]+totalSum] : 0;

            dp[i][j+totalSum]=plus + minus;
        }
    }

    return dp[n-1][target+totalSum];

}

int main() {
    FAST_IO;
    vint nums={1,1,1,1,1};
    cout<<findTargetSumWays(nums, 3);
    return 0;
}
//by ad73prem