#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define push(a) push_back(a)
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

int longestSubarray(vector<int>& arr, int k) {
    map<int,int> prefixsum;
    int sum=0;
    int maxLen=0;
    for(int i=0;i<arr.size();i++){
        sum=sum+arr[i];
        if(sum==k){
            maxLen=max(maxLen,i+1);
        }
        int rem=sum-k;
        //check whether this remainder is inside the hashmap somewhere which would mean that the sum k has been found
        if(prefixsum.find(rem)!=prefixsum.end()){
            maxLen=max(maxLen,i-prefixsum[rem]);
        }

        //now its time to save the sum uptill this length i iunto the hashmap but since nos, can be positvie,negative and zeroes as well... for the longest sum we need to put condition to eliminate the repeated refixsums

        if(prefixsum.find(sum)==prefixsum.end()){
            prefixsum[sum]=i;
        }
    }
    return maxLen;
}

int main() {
    FAST_IO;
    vint arr={94 ,-33, -13, 40, -82, 94, -33 ,-13, 40, -82};
    
    int k=52;
    cout<<longestSubarray(arr,k);
    return 0;
}
//by ad73prem