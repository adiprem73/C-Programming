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

int func(int ind, int last, vector<vector<int>> & matrix, vector<vector<int>>& dp){
    int maxi=0;

    //base case
    if(ind == 0){
        int temp;
        for(int i=0;i<3;i++){
            if(i!=last && maxi<matrix[ind][i]){
                maxi=max(maxi, matrix[0][i]);
                temp=i;
            }
        }
        dp[0][temp]= maxi;
        return;
    }

    for(int i=0;i<3;i++){
        if(i!=last){
            int pts= matrix[ind][i] + func(ind-1, i, matrix, dp);

            maxi=max(maxi, pts);
        }
    }
    return dp[ind][last]= maxi;
}

int ninjaTraining(vector<vector<int>>& matrix) {
    int n=matrix.size();
    vector<vector<int>> dp(n, vector<int> (4, -1)); //an Nx4 dp array to store the memoizations


}

int main() {
    FAST_IO;
    
    return 0;
}
//by ad73prem