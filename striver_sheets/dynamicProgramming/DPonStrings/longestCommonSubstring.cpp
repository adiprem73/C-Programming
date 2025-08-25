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

int longestCommonSubstring(string text1, string text2) {
    int n1=text1.length();
    int n2=text2.length();
    int maxi=0;
    vector<vector<int>> dp(n1+1, vector<int>(n2+1, 0));
    for(int ind1=1;ind1<n1+1;ind1++){
        for(int ind2=1; ind2<n2+1;ind2++){
            if(text1[ind1-1]==text2[ind2-1]){
                dp[ind1][ind2]=1+ dp[ind1-1][ind2-1];
                maxi=max(maxi, dp[ind1][ind2]);
            }else{
                dp[ind1][ind2]= 0;
            }
        }
    }
    return maxi;
}

int main() {
    FAST_IO;
    
    return 0;
}
//by ad73prem