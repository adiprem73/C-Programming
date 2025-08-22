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

int func(int i, int j, vector<vector<int>> & grid){
    if(i==0 && j==0){
        return grid[0][0];
    }
    if(i<0 || j<0){
        return 1e9;
    }

    int left = func(i, j-1, grid);
    int up = func(i-1, j, grid);

    return grid[i][j] + min(left, up);
}

int minPathSum(vector<vector<int>>& grid) {
    int n=grid.size();
    int m=grid[0].size();
    
    return func(n-1,m-1, grid);
    }

int main() {
    FAST_IO;
    vmat grid={{1,3,1},{1,5,1},{4,2,1}};
    vmat grid2={{1,2,3},{4,5,6}};
    cout<<minPathSum(grid2);
    return 0;
}
//by ad73prem