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

int minimumDifference(vector<int>& nums) {
    int n=nums.size();
    int sum=0;
    for(auto it: nums){
        sum+=it;
    }    

    vector<vector<bool>> dp(n, vector<bool>(sum/2 +1, false));

    for(int i=0;i<n;i++) dp[i][0]=true; //with any number of elements, we can always form sum = 0 (by choosing nothing).

    for(int i=0;i<sum/2+1;i++) dp[0][i]=( nums[0]==i); //with only nums[0], we can form sum = nums[0] (if it matches j).

    for(int i=1;i<n;i++){
        for(int j=1;j<sum/2+1;j++){
            bool notPick = dp[i-1][j];

            bool pick=false;
            if(nums[i]<= j){
                pick= dp[i-1][j-nums[i]];
            }

            dp[i][j]= pick||notPick;
        }
    }
    // so now, the dp array holds the info whether a particular target is possible or not to get from the igven array

    int mini=INT_MAX;
    for(int i=0;i<=sum/2;i++){
        if(dp[n-1][i]){
            int s1=i;
            int s2=sum-s1;
            int diff=abs( s1-s2);
            mini= min(mini, diff );
        }
    }
    return mini;
}

int main() {
    FAST_IO;
    vint nums={3,9,7,3};
    cout<<minimumDifference(nums);
    return 0;
}
//by ad73prem