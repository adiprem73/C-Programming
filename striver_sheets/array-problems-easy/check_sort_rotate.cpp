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

bool check(vector<int> &nums){
    vector<int> sortedArray=nums;
    vint copy=nums;
    sort(copy.begin(),copy.end());
    int n=nums.size();


    for(int j=0;j<n;j++){

    
        int last=nums[n-1];
        for(int i=n-1;i>0;i--){
            nums[i]=nums[i-1];
        }
        nums[0]=last;
        // vprint(nums);
        if(nums==copy){
            return true;
        }
        
    }
    
    return false;
}

int main() {
    FAST_IO;
    vector<int> nums={2,1,3,4,3,4,5,1,2};
    cout<<check(nums);
    return 0;
}
//by ad73prem