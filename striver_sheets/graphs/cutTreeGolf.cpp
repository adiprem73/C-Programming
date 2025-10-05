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

int cutOffTree(vector<vector<int>> &forest)
{
    queue<pair<pair<int, int>, int>> q; // (row, col),steps
    int n=forest.size();
    if(!n)return 0;
    int m=forest[0].size();
    vector<vector<bool>> vis(n, vector<bool> (m,0));
    // coutnig the total number of trees ot be cut
    int cnt=-1; 
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(forest[i][j]>1){
                cnt++;
            }
        }
    }

    q.push({{0,0},1});
    vis[0][0]=true;

    vector<int> dr={-1, 0, 1, 0};
    vector<int> dc={0, 1, 0, -1};

    while(!q.empty()){
        auto it= q.front();
        q.pop();
        int r= it.first.first;
        int c= it.first.second;
        int steps= it.second;

        int mini=INT_MAX;
        int x,y;
        // explore all the four directions
        for(int i=0;i<4;i++){
            int nr= r+dr[i];
            int nc= c+dc[i];
            if(nr>=0 && nr<n && nc>=0 && nc<m && forest[nr][nc]!=0 && forest[nr][nc] && vis[nr][nc]==false){
                if(forest[nr][nc]<mini){
                    mini=forest[nr][nc];
                    x=nr;
                    y=nc;
                }
            }
        }
        q.push({{x,y}, steps+1});
    }
}

int main()
{
    FAST_IO;
    
    return 0;
}
//by ad73prem