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

int longestOnes(vector<int>& nums, int k) {
    int l=0,r=0,maxLen=0;
    int count=0;
    while(r<nums.size()){
        if(nums[r]==0){
            count++;
        }

        if(count>k){
            if(nums[l]==0){
                count--;
            }
            l++;
        }

        maxLen=max(maxLen,r-l+1);
        r++;
    } 
    return maxLen;
}

int main() {
    FAST_IO;
    vector<int> nums={0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1};
    cout<<longestOnes(nums,3);
    return 0;
}
//by ad73prem