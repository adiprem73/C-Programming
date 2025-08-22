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

int minimumTotal(vector<vector<int>>& triangle){
    int n=triangle.size();// number of rowas
    vector<vector<int>> dp(n, vector<int>(n,1e9));

    // now since we went top to bottom in recursion and in memo,w e will do the opposite in tabulation. in tabulation we always want to start with some wehre thatt we alreayd inow tha vlaue know

    // in this case, we already know that the last row will have itself as the dp wehn we start at bottom

    // setting the last row of dp ss the same as the last row of triangle grid
    for(int j=0;j<n;j++){
        dp[n-1][j]= triangle[n-1][j];
    }

    for(int i=n-2;i>=0;i--){
        for(int j=0;j<i;j++){
            dp[i][j]= min(dp[i+1][j], dp[i+1][j+1])+ triangle[i][j];
        }
    }

    return dp[0][0];
}


int minimumTotalSO(vector<vector<int>>& triangle){
    int n=triangle.size();// number of rowas
    // vector<vector<int>> dp(n, vector<int>(n,1e9));
    vector<int> prev(n);
    prev= triangle[n-1]; //take the lat row of the triangle only

    // now since we went top to bottom in recursion and in memo,w e will do the opposite in tabulation. in tabulation we always want to start with some wehre thatt we alreayd inow tha vlaue know

    // in this case, we already know that the last row will have itself as the dp wehn we start at bottom

    // setting the last row of dp ss the same as the last row of triangle grid
    for(int i=n-2;i>=0;i--){


        vector<int> curr(i+1,0); //to store the current array
        for(int j=0;j<=i;j++){
            // dp[i][j]= min(dp[i+1][j], dp[i+1][j+1])+ triangle[i][j];
            curr[j]= min(prev[j], prev[j+1])+ triangle[i][j];
        }

        // vprint(prev);
        // vprint(curr);
        // cout<<endl;
        prev=curr;
    }

    return prev[0];
}

int main() {
    FAST_IO;
    vector<vector<int>> triangle={{2},{3,4},{6,5,7},{4,1,8,3}};
    cout<<minimumTotalSO(triangle);
    return 0;
}
//by ad73prem1