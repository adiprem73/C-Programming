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

int rob(vector<int>& nums) {
    int n=nums.size();
    vector<int> dp(n, -1);
    dp[0]= nums[0];
    for(int i=1;i<n;i++){
        int pick = nums[i];
        if(i>1){
            pick+=dp[i-2];
        }

        int notpick = dp[i-1];

        dp[i]= max(pick, notpick);
    }
    return dp[n-1];
}

int robSO(vector<int>& nums) {
    int n=nums.size();
    // vector<int> dp(n, -1);
    // dp[0]= nums[0];

    int prev2= nums[0];
    int prev1= max(nums[0], nums[1]); //if htere are only two hosues, the robber will ofcourse loot the one witht he most loot
    for(int i=1;i<n;i++){
        int pick = nums[i]+ prev2;

        int notpick = prev1;

        int curr = max(pick, notpick);

        prev2= prev1;
        prev1 = curr;
    }
    return prev1;
}

int main() {
    FAST_IO;
    vint nums={2,7,9,3,1};
    cout<<rob(nums);
    return 0;
}
//by ad73prem