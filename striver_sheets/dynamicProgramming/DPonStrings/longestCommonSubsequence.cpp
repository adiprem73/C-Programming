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

//RECURSIVE
/*
int func(int ind1, int ind2, string text1, string text2){
    //base case
    if(ind1<0 || ind2<0){
        return 0;
    }

    //matched
    if(text1[ind1]==text2[ind2]){
        return 1+ func(ind1-1, ind2-1, text1, text2);
    }

    //not matched
    return 0+ max(func(ind1-1, ind2, text1, text2), func(ind1, ind2-1, text1, text2));
}

int longestCommonSubsequence(string text1, string text2) {
    int n1=text1.length();
    int n2=text2.length();
    return func(n1-1, n2-1, text1, text2);
}
*/


//MEMOISATION
/*
int func(int ind1, int ind2, string text1, string text2, vector<vector<int>> dp){
    //base case
    if(ind1<0 || ind2<0){
        return 0;
    }


    if(dp[ind1][ind2]!=-1)return dp[ind1][ind2];
    //matched
    if(text1[ind1]==text2[ind2]){
        return dp[ind1][ind2]= 1+ func(ind1-1, ind2-1, text1, text2, dp);
    }

    //not matched
    return dp[ind1][ind2]= 0+ max(func(ind1-1, ind2, text1, text2, dp), func(ind1, ind2-1, text1, text2, dp));
}

int longestCommonSubsequence(string text1, string text2) {
    int n1=text1.length();
    int n2=text2.length();
    vector<vector<int>> dp(n1, vector<int>(n2, -1));
    return func(n1-1, n2-1, text1, text2, dp);
}
    */

//TABULATION
int func(int ind1, int ind2, string text1, string text2, vector<vector<int>> dp){
    //base case
    if(ind1<0 || ind2<0){
        return 0;
    }
    if(dp[ind1][ind2]!=-1)return dp[ind1][ind2];
    //matched
    if(text1[ind1]==text2[ind2]){
        return dp[ind1][ind2]= 1+ func(ind1-1, ind2-1, text1, text2, dp);
    }

    //not matched
    return dp[ind1][ind2]= 0+ max(func(ind1-1, ind2, text1, text2, dp), func(ind1, ind2-1, text1, text2, dp));
}

int longestCommonSubsequence(string text1, string text2) {
    int n1=text1.length();
    int n2=text2.length();
    vector<vector<int>> dp(n1+1, vector<int>(n2+1, 0));
    for(int ind1=1;ind1<n1+1;ind1++){
        for(int ind2=1; ind2<n2+1;ind2++){
            if(text1[ind1-1]==text2[ind2-1]){
                dp[ind1][ind2]=1+ dp[ind1-1][ind2-1];
            }else{
                dp[ind1][ind2]= max(dp[ind1-1][ind2], dp[ind1][ind2-1]);
            }
        }
    }
    return dp[n1][n2];
}

int longestCommonSubsequenceSO(string text1, string text2) {
    int n1=text1.length();
    int n2=text2.length();
    vector<int> prev(n2+1, 0);
    for(int ind1=1;ind1<n1+1;ind1++){
        vector<int> curr(n2+1, 0);
        for(int ind2=1; ind2<n2+1;ind2++){
            if(text1[ind1-1]==text2[ind2-1]){
                curr[ind2]=1+ prev[ind2-1];
            }else{
                curr[ind2]= max(prev[ind2], curr[ind2-1]);
            }
        }
        prev=curr;
    }
    return prev[n2];
}

string printLongestCommonSubsequence(string text1, string text2){
    int n1=text1.length();
    int n2=text2.length();
    vector<vector<int>> dp(n1+1, vector<int>(n2+1, 0));
    for(int ind1=1;ind1<n1+1;ind1++){
        for(int ind2=1; ind2<n2+1;ind2++){
            if(text1[ind1-1]==text2[ind2-1]){
                dp[ind1][ind2]=1+ dp[ind1-1][ind2-1];
            }else{
                dp[ind1][ind2]= max(dp[ind1-1][ind2], dp[ind1][ind2-1]);
            }
        }
    }
    //dp array created with shifted indexes
    string st;
    int i=n1, j=n2;
    while(i>0 && j>0){
        if(text1[i-1] == text2[j-1]){
            st=text1[i-1]+st;
            i--;
            j--;
        }else if(dp[i-1][j]>dp[i][j-1]){
            i--;
        }else{
            j--;
        }
    }
    return st;
}


int main() {
    FAST_IO;
    cout<<printLongestCommonSubsequence("abcde","ace");
    return 0;
}
//by ad73prem