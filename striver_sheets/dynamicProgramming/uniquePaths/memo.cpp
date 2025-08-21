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

int func(int i, int j, vector<vector<int>> & dp){
    if(i==0 && j==0){
        return 1;
    }

    if(i<0 || j<0){
        return 0;
    }

    if(dp[i][j]!= -1)return dp[i][j];

    int left = func(i, j-1, dp);
    int right= func(i-1, j, dp);

    return dp[i][j]= left + right;
}

int uniquePaths(int m, int n){
    vector<vector<int>> dp(m, vector<int>(n, -1));
    return func(m-1, n-1, dp);
}

int main() {
    FAST_IO;
    cout<<uniquePaths(3,7);
    return 0;
}
//by ad73prem