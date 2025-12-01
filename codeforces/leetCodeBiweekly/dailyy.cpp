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

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


void makeadjacency (vector<vector<int>>& edges, vector<vector<int>>& adj){
    for(auto it: edges){
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
    }
}

long long dfs(int u, int parent, vector<vector<int>> & adj, vector<int>& values, int k, int & components){
    long long cur = values[u]%k;

    for(int v: adj[u]){ //visit all the nodes attached to node u
        if(v== parent)continue;

        long long child = dfs(v, u, adj, values, k, components);
        cur= (cur+child)%k;
    }

    if(cur%k == 0){
        components++;
        return 0; //cut here
    }

    return cur;
}

int maxKDivisibleComponents(int n, vector<vector<int>> &edges, vector<int> &values, int k)
{
    vector<vector<int>> adj(n);
    makeadjacency(edges, adj);
    // for(auto it: adj){
    //     vprint(it);
    // }

    //the total sum of values must be divisible by k
    long long sum= accumulate(values.begin(), values.end(), 0LL);
    if(sum%k!=0)return 0;

    int components=0;
    dfs(0, -1, adj, values, k, components );

    return components;
}

int main()
{
    FAST_IO;
    vector<int> values={1,8,1,4,4};
    vector<vector<int>> nums={{0,2},{1,2},{1,3},{2,4}};
    cout<<maxKDivisibleComponents(5,nums, values, 6);
    return 0;
}
//by ad73prem