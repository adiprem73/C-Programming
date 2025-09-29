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


int func(vector<int>& values, int i, int j){
    if(i+1==j){
        return 0;
    }

    int ans=INT_MAX;
    for(int k=i+1; k<j ; k++){
        ans=min(ans, ((values[i]*values[k]*values[j])+ func(values, i, k) + func(values, k , j)));
    }
    return ans;
}

int minScoreTriangulation(vector<int> &values)
{
    // the intuition is to first tackle it with recursion and then go ahead towards dynamic programming

    return func(values, 0, values.size()-1);
}



MEMOIZATION
int func(vector<int> &values, int i, int j, vector<vector<int>> &dp)
{
    if (i + 1 == j)
    {
        return 0;
    }

    if(dp[i][j]!=-1)return dp[i][j];

    int ans = INT_MAX;
    for (int k = i + 1; k < j; k++)
    {
        ans = min(ans, ((values[i] * values[k] * values[j]) + func(values, i, k, dp) + func(values, k, j, dp)));
    }
    return dp[i][j]=ans;
}

int minScoreTriangulation(vector<int> &values)
{
    // the intuition is to first tackle it with recursion and then go ahead towards dynamic programming
    int n=values.size();
    vector<vector<int>> dp(n, vector<int> (n, -1));
    return func(values, 0, values.size() - 1, dp);
}
    
*/

//TABULATION

int minScoreTriangulation(vector<int> &values)
{
    // the intuition is to first tackle it with recursion and then go ahead towards dynamic programming
    int n = values.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));

    // base casea ccomodation happens in initializatin only

    for(int gap=2;gap<n;gap++){
        for(int i=0;i+gap<n;i++){
            int j=i+gap;
            int best= INT_MAX;
            for(int k=i+1;k<j;k++){
                long long cost= 1LL* values[i]* values[j]* values[k] + dp[i][k]+ dp[k][j];
                if(cost<best) best= (int)cost;
            }
            dp[i][j]= (best==INT_MAX ? 0 : best);
        }
    }
    return dp[0][n-1];
}


int main()
{
    FAST_IO;
    vint nums = {1, 3, 1, 4, 1, 5};
    cout<<minScoreTriangulation(nums);
    return 0;
}
//by ad73prem