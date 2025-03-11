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

void nextPermutation(vector<int>& nums) {
    int bp=-1;
    for(int i=nums.size()-1;i>0;i--){
        // cout<<endl<<i<<" ="<<nums[i]<<endl;
        if(nums[i]>nums[i-1]){
            bp=i-1;
            break;
        }
    }
    // cout<<bp<<endl;
    if(bp==-1){
        reverse(nums.begin(),nums.end());
        return;
    }
    // cout<<bp<<" "<<nums[bp];
    int max=nums[bp];
    mii mp;
    for(int i=nums.size()-1;i>bp;i--){
        if(nums[i]>nums[bp]){
            swap(nums[i],nums[bp]);
            break;
        }
    }
    reverse(nums.begin()+bp+1,nums.end());
    // vprint(nums);
    // vint v;
    // for(auto it: mp){
    //     v.push(it.first);
    // }
    // f(i,0,v.size()){
    //     if(v[i]==nums[bp]){
    //         max=v[i+1];
    //     }
    // }
    // cout<<"max : "<<max;

}

int main() {
    FAST_IO;
    vint v={3,2,1};
    nextPermutation(v);
    return 0;
}
//by ad73prem