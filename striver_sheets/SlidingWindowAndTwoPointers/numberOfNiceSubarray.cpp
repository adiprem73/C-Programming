#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define f(i, a, b) for(int i=a;i<b;i++)
#define all(x) x.begin(),x.end()
#define vprint(v) for (auto& elem : v) cout << elem << " "; cout << endl;
#define vmatprint(vv) for (auto& row : vv) { for (auto& elem : row) cout << elem << " "; cout << endl; } cout << endl;
#define mprint(m) for (auto it : m) cout << it.first << " : " << it.second << endl; cout << endl;
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

int atMostkOdds(vector<int>& nums, int k) {
    int l=0,r=0,countofodd=0,count=0;
    while(r<nums.size()){
        if(nums[r]%2!=0){
            countofodd++;
        }

        while(countofodd>k){
            if(nums[l]%2!=0){
                countofodd--;
            }
            l++;
        }
        
        count+=r-l+1;
        r++;
    }
    return count;
}

int numberOfSubarrays(vector<int>& nums,int k){
    return atMostkOdds(nums,k)-atMostkOdds(nums,k-1);
}

int main() {
    FAST_IO;
    vint nums={1,1,2,1,1};
    cout<<numberOfSubarrays(nums,3);
    return 0;
}
//by ad73prem