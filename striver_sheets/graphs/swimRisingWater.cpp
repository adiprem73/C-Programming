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

bool bfsCheck(vector<vector<int>>&grid, int t){
    int n=grid.size();
    if(!n)return false;
    int m=grid[0].size();
    queue<pair<int,int>> q;
    vector<vector<int>> vis(n, vector<int> (m,0));
    q.push({0,0});
    vis[0][0]=1;
    vector<int> dr={-1, 0, 1, 0};
    vector<int> dc={0, 1, 0, -1};
    if(grid[0][0]>t)return false;
    while(!q.empty()){
        auto it= q.front();
        q.pop();
        int r= it.first;
        int c= it.second;

        if(r==n-1 && c==m-1)return true;

        for(int i=0;i<4;i++){
            int nr= r+dr[i];
            int nc= c+dc[i];
            if(nr>=0 && nr<n && nc>=0 && nc<m){
                if(grid[nr][nc]<=t && vis[nr][nc]==0){
                    q.push({nr, nc});
                    vis[nr][nc]=1;
                }
            }

        }
    }
    return false;
}

int swimInWater(vector<vector<int>> &grid)
{
    int maxi=INT_MIN,mini=INT_MAX;

    int n = grid.size();
    if (!n)
        return false;
    int m = grid[0].size();
    for(int i=0;i<n;i++){
        maxi= max(maxi, *max_element(grid[i].begin(), grid[i].end()));
    }
    for (int i = 0; i < n; i++)
    {
        mini = min(mini, *min_element(grid[i].begin(), grid[i].end()));
    }
    // cout<<maxi << " "<<mini<<endl;
    int s=mini;
    int e=maxi;
    while(s<e){
        int mid= s+(e-s)/2;
        cout<<s<<" "<<mid<<" "<<e<<endl;
        bool flag=bfsCheck(grid, mid);
        if(flag==true){
            e= mid;
        }
        else{
            s=mid+1;
        }
    }
    return s;
}

int main()
{
    FAST_IO;
    vector<vector<int>> nums = {
        {11, 15, 3, 2},
        {6, 4, 0, 13},
        {5, 8, 9, 10},
        {1, 14, 12, 7}};
    cout<<swimInWater(nums);
    return 0;
}
//by ad73prem