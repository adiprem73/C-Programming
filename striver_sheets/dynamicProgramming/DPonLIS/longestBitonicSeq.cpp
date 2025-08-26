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

int longestBitonic(vector<int>& arr, int n){
    // the intuition is to find the LIS of the arr and the arr_reversed, and then we can easily combine the two arrays and get the bitonic result that is required
    vector<int> dp(n,1);
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            if(arr[i]>arr[j] && dp[i]<1+dp[j] ){
                dp[i]=1+dp[j];
            }
        }
    }

    //now we can reverse the given array
    reverse(arr.begin(), arr.end());
    vector<int>dp1(n,1);
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            if(arr[i]>arr[j] && dp1[i]<1+dp1[j]){
                dp1[i]=1+dp1[j];
            }
        }
    }
    // vprint(dp);
    // vprint(dp1);
    int maxi=INT_MIN;
    for(int i=0;i<n;i++){
        maxi=max(maxi, dp[i]+dp1[n-1-i]);
    }
    return maxi-1;

}

int main() {
    FAST_IO;
    vint nums={1,11,2,10,4,5,2,1};
    cout<<longestBitonic(nums, 8);
    return 0;
}
//by ad73prem