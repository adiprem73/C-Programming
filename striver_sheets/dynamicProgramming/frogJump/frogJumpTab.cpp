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
    int n;
    cin>>n;
    vector<int> heights;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        heights.push_back(x);
    }
    vector<int> dp(n, -1);
    dp[0]=0;

    for(int i=1;i<n;i++){
        int left= dp[i-1]+ abs(heights[i]-heights[i-1]);
        int right=INT_MAX;
        if(i>1){
            right=dp[i-2]+ abs(heights[i]-heights[i-2]);
        }

        dp[i]=min(left, right);

    }
    cout<<dp[n-1];
    return 0;
}
//by ad73prem