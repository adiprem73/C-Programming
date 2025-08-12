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

vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
    int n=isWater.size();
    int m=isWater[0].size();
    vector<vector<int>> vis(n, vector<int>(m,0));
    vector<vector<int>> dist(n,vector<int>(m,0));

    queue<pair<pair<int,int>,int>> q;
    //declaring starting nodes
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(isWater[i][j]==1){
                q.push({{i,j},0});
                vis[i][j]=1;
            }
            else{
                vis[i][j]=0;
            }
        }
    }


    vector<int> drow={-1,0,1,0};
    vector<int> dcol={0,1,0,-1};
    while(!q.empty()){
        auto node=q.front();
        int r=node.first.first;
        int c=node.first.second;
        int step= node.second;
        q.pop();
        dist[r][c]=step;
        for(int i=0;i<4;i++){
            int nrow=r+drow[i];
            int ncol=c+dcol[i];
            if(nrow>=0&&nrow<n&&ncol>=0&&ncol<m&&vis[nrow][ncol]==0){
                vis[nrow][ncol]=1;
                q.push({{nrow,ncol}, step+1});
            }
        }
    }
    return dist;
}

vector<vector<int>> updateMatrix(vector<vector<int>> & mat){
    int n=mat.size();
    int m=mat[0].size();
    vector<vector<int>> vis(n, vector<int>(m,0));
    vector<vector<int>> dist(n,vector<int>(m,0));

    queue<pair<pair<int,int>,int>> q;
    //declaring starting nodes
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(mat[i][j]==0){
                q.push({{i,j},0});
                vis[i][j]=1;
            }
            else{
                vis[i][j]=0;
            }
        }
    }


    vector<int> drow={-1,0,1,0};
    vector<int> dcol={0,1,0,-1};
    while(!q.empty()){
        auto node=q.front();
        int r=node.first.first;
        int c=node.first.second;
        int step= node.second;
        q.pop();
        dist[r][c]=step;
        for(int i=0;i<4;i++){
            int nrow=r+drow[i];
            int ncol=c+dcol[i];
            if(nrow>=0&&nrow<n&&ncol>=0&&ncol<m&&vis[nrow][ncol]==0){
                vis[nrow][ncol]=1;
                q.push({{nrow,ncol}, step+1});
            }
        }
    }
    return dist;
}

vector<vector<int>> nearest(vector<vector<int>> grid){
    int n=grid.size();
    int m=grid[0].size();
    vector<vector<int>> vis(n, vector<int>(m,0));
    vector<vector<int>> dist(n,vector<int>(m,0));

    queue<pair<pair<int,int>,int>> q;
    //declaring starting nodes
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]==0){
                q.push({{i,j},0});
                vis[i][j]=1;
            }
            else{
                vis[i][j]=0;
            }
        }
    }


    vector<int> drow={-1,0,1,0};
    vector<int> dcol={0,1,0,-1};
    while(!q.empty()){
        auto node=q.front();
        int r=node.first.first;
        int c=node.first.second;
        int step= node.second;
        q.pop();
        dist[r][c]=step;
        for(int i=0;i<4;i++){
            int nrow=r+drow[i];
            int ncol=c+dcol[i];
            if(nrow>=0&&nrow<n&&ncol>=0&&ncol<m&&vis[nrow][ncol]==0){
                vis[nrow][ncol]=1;
                q.push({{nrow,ncol}, step+1});
            }
        }
    }
    return dist;
}

int main() {
    FAST_IO;
    vector<vector<int>> mat={{0,0,0},{0,1,0},{1,1,1}};
    vector<vector<int>> ans=nearest(mat);
    for(int i=0;i<ans.size();i++){
        vprint(ans[i]);
    }
    return 0;
}
//by ad73prem