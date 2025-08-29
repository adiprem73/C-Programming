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

vector<int> rankGen(vector<int>& nums){
    vint temp=nums;
    sort(temp.begin(), temp.end());
    map<int, int> mp;
    int rankCounter=1;
    for(int i=0;i<temp.size();i++){
        if(mp.find(temp[i])==mp.end()){
            mp[temp[i]]=rankCounter;
            rankCounter++;
        }
    }
    mprint(mp);
    vint ans;
    for(int i=0;i<nums.size();i++){
        ans.push_back(mp[nums[i]]);
    }
    return ans;
}

int main() {
    FAST_IO;
    vint nums={1 ,5 ,8 ,15, 8, 25, 9};
    vint ans=rankGen(nums);
    vprint(ans);
    return 0;
}
//by ad73prem