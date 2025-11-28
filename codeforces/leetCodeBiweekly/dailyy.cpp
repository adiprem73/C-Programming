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




// const int MOD = 1000000007;

// void dfs(int r, int c, vector<vector<int>> &grid, int k, long long sum, long long & count){
//     int n = grid.size();
//     if (!n)
//     {
//         return;
//     }
//     int m = grid[0].size();

//     sum = (sum+grid[r][c])%k;
//     if(r==n-1 && c==m-1){
//         // cout<<sum<<endl;
//         if(sum%k==0){
//             count=(count+1)%(MOD);
//         }
//     }

//     // move right
//     if(c+1<m){
//         dfs(r, c+1, grid, k, sum,  count);
//     }
    

//     //move down
//     if(r+1<n){
//         dfs(r+1, c, grid, k, sum, count);
//     }
    
// }

//     int numberOfPaths(vector<vector<int>> &grid, int k)
// {
//     int n= grid.size();
//     if(!n){
//         return 0;
//     }
//     int m = grid[0].size();

//     long long count=0;
//     dfs(0 ,0, grid, k, 0,  count);
//     return count;
// }

const int MOD = 1000000007;

int dfs(int r, int c, vector<vector<int>> &grid, int k, int rem, vector<vector<vector<int>>> &dp)
{
    int n = grid.size();
    int m = grid[0].size();

    rem = (rem + grid[r][c]) % k;

    if (dp[r][c][rem] != -1)
    {
        return dp[r][c][rem];
    }

    if(r==n-1 && c==m-1){
        return (rem==0);
    }

    long long ways=0;

    // move right
    if (c + 1 < m)
    {
        ways+= dfs(r, c + 1, grid, k, rem, dp);
    }

    // move down
    if (r + 1 < n)
    {
        ways+= dfs(r + 1, c, grid, k, rem,  dp);
    }

    return dp[r][c][rem] = ways%MOD;
}

int numberOfPaths(vector<vector<int>> &grid, int k)
{
    int n = grid.size();
    if (!n)
    {
        return 0;
    }
    int m = grid[0].size();

    vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(k,-1)));

    return dfs(0,0, grid, k, 0 , dp);
}

long long maxSubarraySum(vector<int> &nums, int k)
{
    long long n= nums.size();
    vector<long long> prefixSum(n);
    long long sum=0;
    for(int i=0;i<n;i++){
        sum+=nums[i];
        prefixSum[i]=sum;
    }
    vprint(nums);
    for(int i=0;i<n;i++){
        for(int j=0;j<i+1;j++){
            if(j!=0){
                long long x = prefixSum[i] - prefixSum[j - 1];
                cout<<x<<endl;
            }
        }
    }
    vprint(prefixSum);
}

int main()
{
    FAST_IO;
    vint nums={1,2,3,4};
    maxSubarraySum(nums,2);
    return 0;
}
//by ad73prem