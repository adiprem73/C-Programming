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

vector<int> largestDivisibleSubset(vector<int> &nums){
    int n=nums.size();
    vector<int> dp(n,1), hash(n);
    
    int maxi=INT_MIN;
    int lastIndex=0;
    sort(nums.begin(), nums.end());
    for(int i=0;i<n;i++){
        hash[i]=i;
        for(int prev=0;prev<i;prev++){
            if(nums[i] % nums[prev]==0 && dp[i] < 1+dp[prev]){
                dp[i]=1+dp[prev];
                hash[i]= prev;
            }
        }
        if(dp[i] > maxi){
            maxi=dp[i];
            lastIndex=i;
        }
    }
    vector<int> lis;
    lis.push_back(nums[lastIndex]);
    int ind=1;
    while(hash[lastIndex]!=lastIndex){
        lastIndex= hash[lastIndex];
        lis.push_back(nums[lastIndex]);
    }
    reverse(lis.begin(), lis.end());
    return lis;
}

int main() {
    FAST_IO;
    
    return 0;
}
//by ad73prem