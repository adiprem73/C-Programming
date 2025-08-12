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

void dfs(int r, int c, vector<vector<int>>&grid, vector<vector<int>> &vis){
    vis[r][c]=1;
    int n=grid.size();
    int m=grid[0].size();
    vector<int> drow={-1,0,1,0};
    vector<int> dcol={0,1,0,-1};
    for(int i=0;i<4;i++){
        int nrow=r+drow[i];
        int ncol=c+dcol[i];
        //check if valid and perform further dfs
        if(nrow>=0&&ncol>=0&&nrow<n&&ncol<m&&vis[nrow][ncol]!=1&&grid[nrow][ncol]==1){
            dfs(nrow,ncol,grid,vis);
        }
    }
}

int numEnclaves(vector<vector<int>>& grid) {
    int n=grid.size();
    int m=grid[0].size();
    vector<vector<int>> vis(n,vector<int>(m,0));
    //only start dfs for the boundary elements
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i==0 || j==0 || i==n-1 || j==m-1){
                if(grid[i][j]==1 && vis[i][j]!=1){
                    dfs(i,j,grid,vis);
                }
            }
        }
    }

    int cnt=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]==1 && vis[i][j]==0){
                cnt++;
            }
        }
    }
    return cnt;
}

int main() {
    FAST_IO;
    vector<vector<int>> grid = {
    {0, 1, 1, 0},
    {0, 0, 1, 0},
    {0, 0, 1, 0},
    {0, 0, 0, 0}
};

    cout<<numEnclaves(grid);
    return 0;
}
//by ad73prem