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

bool isHeap(vector<int>& nums) {
    //every parent node must be less than its child node
    int n=nums.size();
    for(int i=0;i<n/2;i++){
        int left= 2*i+1;
        int right=2*i+2;
        if(left<n && nums[i] > nums[left])return false;
        if(right<n && nums[i] > nums[right]) return false;
    }
    return true;
}

int main() {
    FAST_IO;
    vint nums={10, 20, 30, 25, 15};
    cout<<isHeap(nums);
    return 0;
}
//by ad73prem