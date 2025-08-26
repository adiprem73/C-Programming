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

string shortestCommonSupersequence(string str1, string str2) {
    int n1=str1.length();
    int n2=str2.length();
    vector<vector<int>> dp(n1+1, vector<int>(n2+1, 0));
    for(int ind1=1;ind1<n1+1;ind1++){
        for(int ind2=1; ind2<n2+1;ind2++){
            if(str1[ind1-1]==str2[ind2-1]){
                dp[ind1][ind2]=1+ dp[ind1-1][ind2-1];
            }else{
                dp[ind1][ind2]= max(dp[ind1-1][ind2], dp[ind1][ind2-1]);
            }
        }
    }
    string ans="";
    int i=n1, j=n2;
    while(i>0 && j>0){
        if(str1[i-1]==str2[j-1]){
            ans+=str1[i-1];
            i--, j--;
        }
        else if(dp[i-1][j] > dp[i][j-1]){
            ans+=str1[i-1];
            i--;
        }
        else{
            ans+=str2[j-1];
            j--;
        }
    }
    while(i>0){
        ans+=str1[i-1];
        i--;

    }
    while(j>0){
        ans+=str2[j-1];
        j--;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main() {
    FAST_IO;
    
    return 0;
}
//by ad73prem