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
/*

MEMOIZATION
int func(int i, int j, string s, string t, vector<vector<int>> dp){
    //base cases
    if(j<0)return 1; //if string t gets exhausted means we have found a distinct subsequence hence we return 1
    if(i<0) return 0;// if string s gete exhausted means we could not find a distinct subsequence hence we return 0
    if(dp[i][j]!=-1)return dp[i][j];
    if(s[i]==t[j]){
        return dp[i][j]=(func(i-1, j-1, s, t, dp)+func(i-1, j, s, t, dp)); //here the first call accepts that we foudn amatcha nd ence boths tring moved by 1 and the second onte addresses that yes we did find but lets find some other one match
    }
    else{
        return dp[i][j]=func(i-1, j, s,t, dp);
    }
}

int numDistinct(string s, string t) {
    int n=s.size();
    int m=t.size();
    vector<vector<int>> dp(n, vector<int> (m,-1)); 
    return func(n-1, m-1, s, t, dp);       
}
    */

int numDistinct(string s, string t) {
    int n=s.size();
    int m=t.size();
    vector<vector<ll>> dp(n+1, vector<ll> (m+1,0)); //now the indexing is all one based inside the dp table
    //i think we might want to shift the dp table by one index

    for(int i=0;i<=n;i++){ //i think this will solve the base case number 1 and base case number 2 isnt necessary since alreayd all the elements inside the dp table are initialised with 0
        dp[i][0]=1;
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s[i-1]==t[j-1]){
                dp[i][j]=dp[i-1][j-1] + dp[i-1][j];
            }
            else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    return dp[n][m];
}


int main() {
    FAST_IO;
    cout<<numDistinct("rabbbit","rabbit");
    return 0;
}
//by ad73prem