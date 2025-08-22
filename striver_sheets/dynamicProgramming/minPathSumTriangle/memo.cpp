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

int func(int i, int j , vector<vector<int>> & triangle, vector<vector<int>>& dp){
    int n=triangle.size();

    if(i== n-1) return triangle[i][j]; //base case fo the elelment so fht eending row

    if(dp[i][j]!=1e9) return dp[i][j];

    int down= func(i+1, j, triangle, dp);
    int diag= func(i+1, j+1, triangle, dp);

    return dp[i][j]= min(down, diag) + triangle[i][j];
}

int minimumTotal(vector<vector<int>>& triangle){
    int n=triangle.size();// number of rowas
    int m=triangle[triangle.size()-1].size();
    vector<vector<int>> dp(n, vector<int>(m,1e9));

    return func(0,0, triangle, dp);
}

int main() {
    FAST_IO;
    
    return 0;
}
//by ad73prem1