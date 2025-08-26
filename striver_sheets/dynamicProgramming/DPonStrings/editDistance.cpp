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
/*Memoization
int func(int i, int j, string word1, string word2, vector<vector<int>> &dp){
    //base case

    if(i<0)return j+1;
    if(j<0)return i+1;

    if(dp[i][j]!=-1)return dp[i][j];
    //matched
    if(word1[i] == word2[j])return dp[i][j] = func(i-1, j-1, word1, word2, dp);

    //if not matched then we can perform three operations: insert delete and replace
    return dp[i][j] = min(1+func(i, j-1, word1, word2, dp), min(1+func(i-1, j, word1, word2, dp), 1+func(i-1, j-1, word1, word2, dp)));
}

int minDistance(string word1, string word2) {
    int n=word1.size();
    int m=word2.size();
    vector<vector<int>> dp(n, vector<int> (m,-1)); 
    int ans=func(n-1, m-1, word1, word2, dp);  
    return  ans;
}
*/

//for tabulation it becomes necessary to take 1 indexing that is shifting of dp array by 1

int minDistance(string word1, string word2) {
    int n=word1.size();
    int m=word2.size();
    vector<vector<int>> dp(n+1, vector<int> (m+1,0)); 

    //base cases
    for(int j=0;j<=m;j++){
        dp[0][j]=j;
    }
    for(int i=0;i<=m;i++){
        dp[i][0]=i;
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(word1[i-1]==word2[j-1]){
                dp[i][j]=dp[i-1][j-1];
            }
            else{
                dp[i][j]= min(1+dp[i-1][j], min(1+dp[i][j-1], 1+dp[i-1][j-1]));
            }
        }
    }
    return dp[n][m];
}



int main() {
    FAST_IO;
    cout<<minDistance("horse", "ros");
    return 0;
}
//by ad73prem