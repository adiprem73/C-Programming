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
/*Recursion
bool func(int i, int j, string s, string p){
    //base cases
    if(i<0 && j< 0)return true;
    if(i<0 && j>=0)return false;
    if(j<0 && i>=0){
        for(int x=0;x<=i;x++){
            if(p[x]!='*'){
                return false;
            }
        }return true;
    }

    //matching
    if(p[i]==s[j] || p[i]=='?'){
        return func(i-1, j-1, s, p);
    }
    if(p[i]=='*'){
        return func(i-1, j, s, p) || func(i, j-1, s, p);
    }
    return false;
}

bool isMatch(string s, string p) {
    int n=p.size();
    int m=s.size();
    return func(n-1, m-1, s, p); 
}*/

bool func(int i, int j, string s, string p, vector<vector<int>> dp){
    //base cases
    if(i<0 && j< 0)return true;
    if(i<0 && j>=0)return false;
    if(j<0 && i>=0){
        for(int x=0;x<=i;x++){
            if(p[x]!='*'){
                return false;
            }
        }return true;
    }

    //dp check
    if(dp[i][j]!=-1)return dp[i][j];

    //matching
    if(p[i]==s[j] || p[i]=='?'){
        return dp[i][j]=func(i-1, j-1, s, p,dp);
    }
    if(p[i]=='*'){
        return dp[i][j]=func(i-1, j, s, p,dp) || func(i, j-1, s, p,dp);
    }
    return false;
}

bool isMatch(string s, string p) {
    int n=p.size();
    int m=s.size();
    vector<vector<int>> dp(n, vector<int>(m,-1));
    return func(n-1, m-1, s, p,dp); 
}

int main() {
    FAST_IO;
    cout<<isMatch("cb","?a");
    return 0;
}
//by ad73prem