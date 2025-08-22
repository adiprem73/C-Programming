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

int minPathSum(vector<vector<int>>& grid) {
    int n=grid.size();
    int m=grid[0].size();
    vector<vector<int>> dp(n, vector<int>(m,1e9));
    
    dp[0][0]= grid[0][0];

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i==0 && j==0)continue;
            
            int left=1e9, up=1e9;

            if(j>0){
                left=dp[i][j-1];
            }

            if(i>0){
                up= dp[i-1][j];
            }

            dp[i][j]= min(left, up)+ grid[i][j];
            
        }
    }


    return dp[n-1][m-1];
}

int minPathSumSO(vector<vector<int>> & grid){
    int n=grid.size();
    int m=grid[0].size();
    //observations: for computing the current element we only need the current row and the previous row

    vector<int> prev(m, 1e9);

    for(int i=0;i<n;i++){
        vector<int> curr(m,1e9);
        for(int j=0;j<m;j++){
            if(i==0 && j==0){
                curr[j]= grid[0][0];
                continue;
            }
            int left = (j>0)? curr[j-1] : 1e9;

            int up = (i>0)? prev[j] : 1e9;

            curr[j]= grid[i][j]+ min(left, up);
            
        }
        prev=curr;
    }
    return prev[m-1];
}

int main() {
    FAST_IO;
    vmat grid={{1,3,1},{1,5,1},{4,2,1}};
    vmat grid2={{1,2,3},{4,5,6}};
    cout<<minPathSumSO(grid);
    return 0;
}
//by ad73prem