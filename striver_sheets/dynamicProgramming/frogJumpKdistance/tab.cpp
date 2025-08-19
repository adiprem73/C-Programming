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

int main() {
    FAST_IO;
    vint heights={10, 5, 20, 0, 15};
    int k=2;
    int n = heights.size();

    vector<int> dp(n,-1);

    dp[0]=0;
    int ans;
    for(int j=1;j<n;j++){
        ans=INT_MAX;

        for(int i=1;i<=k;i++){
            if(j>=i){
                int temp= dp[j-i]+ abs(heights[j]- heights[j-i]);
                ans=min(ans, temp);
            }
        }
        dp[j]=ans;
    }
    cout<<ans;

    return 0;
}
//by ad73prem