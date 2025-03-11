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

vector<int> getSneakyNumbers(vector<int>& nums) {
    mii mp;
    f(i,0,nums.size()){
        mp[nums[i]]++;
    }
    vint ans;
    for(auto it:mp){
        if(it.second==2){
            ans.push(it.first);
        }
    }  
    // vprint(ans);
    return ans;
}

int main() {
    FAST_IO;
    vint nums={7,1,5,4,3,4,6,0,9,5,8,2};
    vint ans=getSneakyNumbers(nums);
    return 0;
}
//by ad73prem