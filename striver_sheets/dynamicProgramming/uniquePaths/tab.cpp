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

int uniquePaths(int m, int n){
    vector<vector<int>> dp(m, vector<int>(n, -1));
    dp[0][0]=1; //base case: only one wya to reach the start from (0,0)

    for(int i=0; i<m;i++){
        for(int j=0;j<n;j++){
            if(!(i==0&&j==0)){ //excludig the base case from the loops

                int right=0;
                int down=0;
                if(j>0){
                    right= dp[i][j-1];
                }

                if(i>0){
                    down= dp[i-1][j];
                }
                dp[i][j] = down+right;
            }
        }
    }

    

    return dp[m-1][n-1];
}

int uniquePathsSO(int m, int n){
    vector<vector<int>> dp(m, vector<int>(n, -1));
    dp[0][0]=1; //base case: only one wya to reach the start from (0,0)

    for(int i=0; i<m;i++){
        for(int j=0;j<n;j++){
            if(!(i==0&&j==0)){ //excludig the base case from the loops

                int right=0;
                int down=0;
                if(j>0){
                    right= dp[i][j-1];
                }

                if(i>0){
                    down= dp[i-1][j];
                }
                dp[i][j] = down+right;
            }
        }
    }

    return dp[m-1][n-1];
}

int main() {
    FAST_IO;
    cout<<uniquePaths(3,7);
    return 0;
}
//by ad73prem