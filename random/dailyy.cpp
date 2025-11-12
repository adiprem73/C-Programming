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

int minOperations(vector<int> &nums)
{
    int n= nums.size();
    
    // if there are ones already present inside the arrray
    int ones=0;
    for(auto it: nums){
        if (it==1){
            ones++;
        }
    }
    if(ones) return n-ones;

    // if gcd of the entire array is greater thatn 1 then also its impossible to convert the entire array into 1
    int overallgcd=0;
    for(auto it: nums){
        overallgcd= gcd(overallgcd, it);
    }
    if(overallgcd!=1)return -1;

    // since now we confirm that the arrays overall gcd is not equal to 1 we can easily find the shorted lenght whose gcd is equal to 1

    int bestlen= INT_MAX;

    for(int i=0;i<n;i++){
        int g=0;
        for(int j=i;j<n;j++){
            g= gcd(g, nums[j]);
            if(g==1){
                bestlen= min(bestlen, j-i+1);
            }
        }
    }
    // cout<<bestlen;
    return n+bestlen-2;
}

int main()
{
    FAST_IO;
    vint nums={2,6,3,4};
    cout<<minOperations(nums);
    return 0;
}
//by ad73prem