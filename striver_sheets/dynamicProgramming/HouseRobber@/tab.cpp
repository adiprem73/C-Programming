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

int robSO(vector<int>& nums) {
    int n=nums.size();
    // vector<int> dp(n, -1);
    // dp[0]= nums[0];

    if(n == 1) return nums[0];
    if(n==2) return max(nums[0], nums[1]);

    int prev2= nums[0];
    int prev1= max(nums[0], nums[1]); //if htere are only two hosues, the robber will ofcourse loot the one witht he most loot
    for(int i=2;i<n-1;i++){
        int pick = nums[i]+ prev2;

        int notpick = prev1;

        int curr = max(pick, notpick);

        prev2= prev1;
        prev1 = curr;
    }
    //prev1 is the ans1 whcih excludes the last element
    int ans1= prev1;

    prev2= nums[1];
    prev1= max(nums[1], nums[2]); //if htere are only two hosues, the robber will ofcourse loot the one witht he most loot
    for(int i=3;i<n;i++){
        int pick = nums[i]+ prev2;

        int notpick = prev1;

        int curr = max(pick, notpick);

        prev2= prev1;
        prev1 = curr;
    }
    // prev1 here is the ans2 which excludes the first element
    int ans2= prev1;


    return max(ans1, ans2);


}


int main() {
    FAST_IO;
    vint nums={1,2,3,1};
    cout<<robSO(nums);
    return 0;
}
//by ad73prem