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

int fun(int n, vector<int> &dp){
    if(n<=1){
        return n;
    }

    // #2 adding a condition to check i fpreviously saved in dp array
    if(dp[n] != -1)return dp[n];


    // #1 to change the returning of the recursive funciton into saving it into dp
    return dp[n]= fun(n-1,dp) + fun(n-2,dp);
}

int main() {
    FAST_IO;
    int n;
    cin>>n;

    // #0 intitalizing an array of size n+1 for saving numbers in dp
    vector<int> dp(n+1,-1);
    cout<< fun(n,dp);
    return 0;
}
//by ad73prem