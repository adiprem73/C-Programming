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

int subarraySum(vector<int>& nums, int k) {
    // sort(nums.begin(),nums.end());
    mii mp;
    int sum=0;
    int count=0;
    for(int i=0;i<nums.size();i++){
        sum=sum+nums[i];
        // cout<<sum<<" "<<nums[i]<<endl;
        if(sum==k){
            // cout<<"hi"<<i<<endl;
            count++;
        }
        int x=sum-k;
        if(mp.find(x)!=mp.end()){
            // cout<<"bye"<<i<<endl;
            count++;
        }
        if(mp.find(sum)==mp.end()){
            mp[sum]=i;
        }
        
    }
    return count;
}

int main() {
    FAST_IO;
    vint nums={0,0,0,0,0,0,0,0,0,0};
    int k=0;
    cout<<subarraySum(nums,k);
    return 0;
}
//by ad73prem