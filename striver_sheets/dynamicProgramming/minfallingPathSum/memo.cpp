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

int func(int i, int j, vector<vector<int>>& matrix, vector<vector<int>> & dp){

    if(i==0) return matrix[i][j]; //base case


    if(dp[i][j]!=1e9)return dp[i][j]; //turne what already been computed to avoid any overlapping sums
    int up= (i>0)? func(i-1, j, matrix,dp) : 1e9;
    int upleft= (j>0)? func(i-1, j-1, matrix, dp) : 1e9;
    int upright= (i>0 && j+1< matrix.size())? func(i-1, j+1, matrix, dp) : 1e9;

    return dp[i][j] = min(up, min(upleft, upright))+ matrix[i][j];

}

int minFallingPathSum(vector<vector<int>>& matrix) {
    int n=matrix.size() ;
    int mini=INT_MAX;

    vector<vector<int>> dp(n, vector<int> (n, 1e9));
    //we need to call the function form every elelmnt of the last row
    for(int j=0;j<n;j++){
        mini=min(mini, func(n-1, j, matrix,dp));
    }
    return mini;     
}

int main() {
    FAST_IO;
    vector<vector<int>> matrix= {{2,1,3},{6,5,4},{7,8,9}};
    cout<<minFallingPathSum(matrix);
    return 0;
}
//by ad73prem