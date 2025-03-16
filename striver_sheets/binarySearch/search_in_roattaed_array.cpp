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

int search(vector<int>& nums, int target) {
    mii mp;
    int n=nums.size();
    for(int i=0;i<n;i++){
        mp[nums[i]]=i;
    }
    sort(nums.begin(),nums.end());
    int s=0;
    int e=n-1;
    int mid;
    int res=-1;
    while(s<=e){
        mid=s+(e-s)/2;

        if(nums[mid]==target){
            res=mid;
        }
        if(nums[mid]<target){
            s=mid+1;
        }
        else{
            e=mid-1;
        }
    }
    // cout<<"Res : "<<res<<endl;
    if(res!=-1){
        return mp[target];
    }
    return -1;
}

int main() {
    FAST_IO;
    vint nums={2,5,6,0,0,1,2};
    cout<<search(nums,3);
    return 0;
}
//by ad73prem