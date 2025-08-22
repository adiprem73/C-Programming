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

int minFallingPathSum(vector<vector<int>>& matrix) {
    int n=matrix.size() ;
    int mini=INT_MAX;

    vector<vector<int>> dp(n, vector<int> (n, 1e9));
    // as the base case we need to set the first row of the dp as the first row of the matrix
    
    for(int j=0;j<n;j++){
        dp[0][j]= matrix[0][j];
    }

    for(int i=1;i<n;i++){
        for(int j=0;j<n;j++){


            int up = dp[i-1][j];
            int leftdiag= (j>0)? dp[i-1][j-1] : 1e9;
            int rightdiag = (j+1<n) ? dp[i-1][j+1] : 1e9;
            dp[i][j]= matrix[i][j]+ min(up, min(leftdiag,rightdiag));
        }
    }


    int ans=INT_MAX;
    for(int j=0;j<n;j++){
        ans=min(ans, dp[n-1][j]);
    }

    return ans;
}

int main() {
    FAST_IO;
    vector<vector<int>> matrix= {{2,1,3},{6,5,4},{7,8,9}};
    cout<<minFallingPathSum(matrix);
    return 0;
}
//by ad73prem