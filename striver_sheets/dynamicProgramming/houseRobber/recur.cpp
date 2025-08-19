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

int func(int ind, vector<int> & nums){
    if(ind==0)return nums[ind];
    if(ind<0) return 0;

    int pick = nums[ind] + func(ind-2, nums); //since we pick  nums[ind] we cannot take ind-1 and hence we took the sum till ind-2

    int notpick = func(ind-1, nums);

    return max(pick, notpick);
}

int rob(vector<int>& nums) {
    return func(nums.size()-1, nums);
}

int main() {
    FAST_IO;
    vint nums={2,7,9,3,1};
    cout<<rob(nums);
    return 0;
}
//by ad73prem