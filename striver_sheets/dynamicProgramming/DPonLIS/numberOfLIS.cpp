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

int findNumberOfLIS(vector<int>& nums) {
    int n=nums.size();
    vector<int> dp(n,1), cnt(n,1);;
    int maxi=INT_MIN;
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            if(nums[i]>nums[j] && dp[j]+1>dp[i]){
                dp[i]= 1+dp[j];
                cnt[i]=cnt[j];
            }
            else if(nums[i]>nums[j] && dp[j]+1==dp[i]){
                cnt[i]+=cnt[j];
            }
        }
        maxi=max(maxi, dp[i]);
    }
    int ans=0;
    for(int i=0;i<n;i++){
        if(dp[i]==maxi){
            ans+=cnt[i];
        }
    }
    return ans;
}

int main() {
    FAST_IO;
    
    return 0;
}
//by ad73prem