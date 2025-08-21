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

int func(int i, int j, vector<vector<int>> & obstacleGrid){
    if(i<0 || j<0)return 0;
    if(obstacleGrid[i][j]==1) return 0;
    if(i==0 && j==0)return 1;

    int left=0, up=0;
    if(j>0){
        left=func(i, j-1, obstacleGrid);
    }
    if(i>0){
        up= func(i-1, j, obstacleGrid);
    }
    return up+left;
}

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int n= obstacleGrid.size();
    int m=obstacleGrid[0].size();
    return func(n-1, m-1, obstacleGrid);    
}

int main() {
    FAST_IO;
    vmat obs={{1}};
    cout<< uniquePathsWithObstacles(obs);
    return 0;
}
//by ad73prem