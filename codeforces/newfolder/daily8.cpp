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

int countUnguarded (int m, int n, vector<vector<int>> & guards, vector<vector<int>> & walls){
    swap(m,n);
    vector<vector<int>> vis(n, vector<int>(m,0));
    // let's mark all the cells which have guards or walls as visited
    for(auto it: guards){
        vis[it[0]][it[1]]=1;
    }
    for (auto it : walls)
    {
        vis[it[0]][it[1]] = 1;
    }
    // now each time we will be starting from a guard only
    vector<int> drow={-1,0,1,0};
    vector<int> dcol={0,1,0,-1};

    // for (int i = 0; i < n; ++i)
    // {
    //     for (int j = 0; j < m; ++j)
    //     {
    //         cout << vis[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }

    // cout<<endl;

    for(auto it: guards){
        int row= it[0];
        int col=it[1];
        for(int i=0;i<4;i++){
            int nrow= row+drow[i];
            int ncol= col+dcol[i];
            while(nrow>=0 && nrow<n && ncol>=0 && ncol<m&& vis[nrow][ncol]!=1){
                vis[nrow][ncol]=2;
                nrow = nrow + drow[i];
                ncol = ncol + dcol[i];
            }
        }
    }

    // for (int i = 0; i < n; ++i) {
    //     for (int j = 0; j < m; ++j) {
    //         cout << vis[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    // cout << '\n';
    int count=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(vis[i][j]==0){
                count++;
            }
        }
    }
    return count;

}

int main() {
    FAST_IO;
    vector<vector<int>> guards={{0,0},{1,1},{2,3}};
    vector<vector<int>> walls={{0,1},{2,2},{1,4}};
    cout<<countUnguarded(4,6, guards, walls);
    return 0;
}
//by ad73prem