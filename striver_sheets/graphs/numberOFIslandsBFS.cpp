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

int numOfIslands(vector<vector<char>> & grid){
    int n=grid.size();
    int m= grid.size();

    vector<vector<int>> vis(n, vector<int>(m,0));

    int cnt=0;
    vector<int> dx={0,1,0,-1};
    vector<int> dy={-1,0,1,0};
    // cout << "hello" << endl;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(vis[i][j]==0 && grid[i][j]=='1'){
                // cout<<"hello"<<endl;
                cnt++;
                queue<pair<int,int>> q;
                q.push({i,j});
                vis[i][j]=1;
                while(!q.empty()){
                    auto it= q.front();
                    q.pop();
                    int r= it.first;
                    int c= it.second;

                    for(int k=0;k<4;k++){
                        int nr= r+dx[k];
                        int nc= c+dy[k];
                        if(nr>=0 && nr<n && nc>=0 && nc<m && vis[nr][nc]==0 && grid[nr][nc]=='1'){
                            q.push({nr,nc});
                            vis[nr][nc]=1;
                        }
                    }
                }
            }
        }
    }
    return cnt;
}

int main() {
    FAST_IO;
    vector<vector<char>> grid = {
        {'1'},
        {'1'}};
    cout<<numOfIslands(grid);
    return 0;
}
//by ad73prem