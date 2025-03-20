#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define push(a) push_back(a)
#define f(i, a, b) for(int i=a;i<b;i++)
#define all(x) x.begin(),x.end()
#define vprint(v) for (auto& elem : v) cout << elem << " "; cout << endl;
#define vmatprint(vv) for (auto& row : vv) { for (auto& elem : row) cout << elem << " "; cout << endl; } cout << endl;
#define mprint(m) for (auto it : m) cout << it.first << " : " << it.second << endl; cout << endl;
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

void generateCombination(int index, int k, int target, vint &curr, vint&nums, vmat &ans){
    if(target==0 && curr.size()==k){
        ans.push_back(curr);
        return;
    }

    for(int i=index;i<nums.size();i++){
        if(i>index&&nums[i]==nums[i-1]){
            continue;
        }

        if(nums[i]>target){
            break;
        }

        curr.push_back(nums[i]);
        generateCombination(i+1,k,target-nums[i],curr,nums,ans);

        curr.pop_back();
    }
}

vector<vector<int>> combinationSum3(int k, int n) {
    vint nums={1,2,3,4,5,6,7,8,9};
    vint curr;
    vmat ans;
    int target=n;
    int index=0;
    generateCombination(index,k,target,curr,nums,ans);    
    return ans;
}

int main() {
    FAST_IO;
    vmat ans=combinationSum3(4,1);
    vmatprint(ans);
    return 0;
}
//by ad73prem