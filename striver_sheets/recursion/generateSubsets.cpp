#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define push(a) push_back(a)
#define f(i, a, b) for(int i=a;i<b;i++)
#define all(x) x.begin(),x.end()
#define vprint(v) for (auto& elem : v) cout << elem << " "; cout << endl;
#define vmatprint(vv) for (auto& row : vv) { for (auto& elem : row) cout << elem << " "; cout << endl; }cout<<endl;
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

void subsetGenerate(vmat &res, vint curr,vint nums,int i){
    if(i==nums.size()){
        res.push_back(curr);
        return;
    }
    
    curr.push_back(nums[i]);
    subsetGenerate(res,curr,nums,i+1);


    curr.pop_back();
    subsetGenerate(res,curr,nums,i+1);
}

vector<vector<int>> subsets(vector<int>& nums) {
    vmat res;
    vint curr;
    subsetGenerate(res,curr,nums,0);
    return res;
}

int main() {
    FAST_IO;
    vint nums={1,2,3};
    vmat res=subsets(nums);
    vmatprint(res);
    return 0;
}
//by ad73prem