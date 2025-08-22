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

int func(int i, int j1, int j2, vector<vector<int>> & g, vector<vector<vector<int>>> &dp){
    int n = g.size();
    int m = g[0].size();

    if(j1<0||j1>=m||j2<0||j2>=m){
        return -1e8;
    }

    if(i==n-1){
        if(j1==j2){
            return dp[i][j1][j2]= g[i][j1];
        }

        else{
            return dp[i][j1][j2]= g[i][j1] + g[i][j2];
        }
    }

    //dp check
    if(dp[i][j1][j2]!= -1) return dp[i][j1][j2];

    int maxi = -1e8;
    for (int dj1 = -1; dj1 <= 1; dj1++)
    {
        for (int dj2 = -1; dj2 <= 1; dj2++)
        {
            // if both end up in the same cell
            if (j1 == j2)
            {
                maxi = max(maxi, (g[i][j1] + func(i + 1, j1 + dj1, j2 + dj2, g,dp)));
            }

            else{
                maxi = max(maxi, g[i][j1]+g[i][j2]+ func(i+1, j1+dj1, j2+dj2, g,dp));
            }
        }
    }
    
    return dp[i][j1][j2]= maxi;
}

int maxChocolates(vector<vector<int>> &g)
{
    int n = g.size();
    int m = g[0].size();
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m,-1)));
    return func(0, 0, m-1,g,dp);
}

int main() {
    FAST_IO;
    vmat g={{2,3,1,2},{3,4,2,2},{5,6,3,5}};
    cout<<maxChocolates(g);
    return 0;
}
//by ad73prem