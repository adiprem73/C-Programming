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

vector<int> twoSum(vector<int>& nums,int target){
    map<int,int> mp;
    int n=nums.size();  
    for(int i=0;i<n;i++){
        if(mp.find(target-nums[i])!=mp.end()){
            return{mp[target-nums[i]],i};
        }
        mp[nums[i]]=i;
    }
    return {};
}

int main() {
    FAST_IO;
    vint nums={3,2,4};
    int target=6;
    vprint(twoSum(nums,target));
    return 0;
}
//by ad73prem