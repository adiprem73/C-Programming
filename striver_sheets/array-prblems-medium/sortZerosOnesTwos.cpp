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

void sortColors(vector<int>& nums) {
    map<int,int> mp;
    vint ans;
    int n=nums.size();
    for(int i=0;i<n;i++){
        mp[nums[i]]++;
    }
    for(int i=0;i<mp[0];i++){
        ans.push_back(0);
    }
    for(int i=0;i<mp[1];i++){
        ans.push_back(1);
    }
    for(int i=0;i<mp[2];i++){
        ans.push_back(2);
    }
    nums=ans;
}

int main() {
    FAST_IO;
    vint nums={2,0,2,1,1,0};
    sortColors(nums);
    vprint(nums);
    return 0;
}
//by ad73prem