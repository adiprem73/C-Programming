#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define f(i, a, b) for (int i = a; i < b; i++)
#define all(x) x.begin(), x.end()
#define vprint(v)            \
    for (auto &elem : v)     \
        cout << elem << " "; \
    cout << endl;
#define mprint(m)                                       \
    for (auto it : m)                                   \
        cout << it.first << " : " << it.second << endl; \
    cout << endl;
#define vint vector<int>
#define vstring vector<string>
#define vmat vector<vector<int>>
#define FAST_IO                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define pii pair<int, int>
#define pll pair<ll, ll>
#define mii map<int, int>
#define mll map<ll, ll>

const int INF = 1e9;
const ll MOD = 1e9 + 7;

int perfectSum(vector<int> & arr, int K){
    int n=arr.size();
    int sum=0;
    for(const auto& it: arr){
        sum+=it;
    }

    //dp arrya initialisation
    vector<vector<int>> dp(n, vector<int>(K+1, 0));

    for(int i=0;i<K+1;i++) dp[0][i]=(arr[0]==i)? 1:0; // by setting the entire first row as this we make sure that if index is zero, then returnign true is only possible if the first element of the array is equal to the target.

    //base case
    for(int i=0;i<n;i++) dp[i][0]=1; // bys ettign all the first element of each row that is the firt column as true we define that a sum=0 is lawya possible since target is zero we can always not pick any element and that would give us this true

    

    for(int i=1;i<n;i++){
        for(int j=1;j<K+1;j++){
            int notPick = dp[i-1][j];

            int pick=0;
            if(arr[i]<= j){
                pick= dp[i-1][j-arr[i]];
            }

            dp[i][j]= pick+notPick;
        }
    }

    // for(auto it: dp){
    //     vprint(it);
    // }

    return dp[n-1][K];
}

int countPartitions(int n, int diff, vector<int> &arr)
{
    int sum=0;
    for(auto it: arr){
        sum+=it;
    }

    if(sum-diff<0 || (sum-diff)%2) return false;
    return perfectSum(arr, (sum-diff)/2);

}

int main()
{
    FAST_IO;
    vint arr={1,1,2,3};
    cout<<countPartitions(4, 1, arr);
    return 0;
}
// by ad73prem