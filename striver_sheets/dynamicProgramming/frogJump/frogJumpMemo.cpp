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

int func(int ind, vector<int> &heights, vector<int> & dp){
    if(ind ==0 )return 0;

    if(dp[ind]!=-1)return dp[ind];

    int left = func(ind-1, heights, dp) + abs(heights[ind]- heights[ind-1]);

    int right= INT_MAX;

    if(ind>1){
        right = func(ind-2, heights, dp) + abs(heights[ind]- heights[ind-2]);
    }

    return dp[ind]= min(left, right);
}



int frogJump(int n, vector<int> & heights){
    vector<int> dp(n, -1);
    return func(n-1, heights, dp);
}

int main() {
    FAST_IO;
    vint h={10, 20, 30, 10};
    cout<<frogJump(4, h);
    return 0;
}
//by ad73prem