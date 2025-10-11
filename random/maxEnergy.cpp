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
/*

int maximumEnergy(vector<int>& energy, int k) {
    
    int maxi=INT_MIN;
    for(int i=0;i<n;i++){
        int start= i;
        int sum=0;
        while(start<n){
            sum+=energy[start];
            start+=k;
        }
        maxi=max(maxi,sum);
    } 
    return maxi;
}
*/


int maximumEnergy(vector<int>& energy, int k){
    int n = energy.size();
    vector<int> dp(n);
    for(int i=0;i<k;i++){
        dp[n-1-i]= energy[n-1-i];
    }

    for(int i=n-k-1;i>=0;i--){
        dp[i]= dp[i+k]+ energy[i];
    }
    // vprint(dp);
    return *max_element(dp.begin(), dp.end());
}


int main() {
    FAST_IO;
    vint nums = {5, 2, -10, -5, 1};
    cout<<maximumEnergy(nums, 3);
    return 0;
}
//by ad73prem