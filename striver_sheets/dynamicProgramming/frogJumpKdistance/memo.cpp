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

int func(int ind, vint & heights, int k, vint & dp){
    if(ind ==0) return 0;

    if(dp[ind]!= -1)return dp[ind];


    int ans=INT_MAX;

    for(int i=1;i<=k;i++){
        if(ind >= i){
            int temp=func(ind-i, heights, k, dp) + abs(heights[ind]-heights[ind-i]);
            ans=min(ans,temp);
        }      
    }
    return dp[ind]=ans;
}

int frogJump(vector<int>& heights, int k) {
    int n=heights.size();
    vint dp(n, -1);

    return func(n-1, heights, k, dp);

}

int main() {
    FAST_IO;
    vint heights={15, 4, 1, 14, 15};
    cout<<frogJump(heights, 3);
    return 0;
}
//by ad73prem 