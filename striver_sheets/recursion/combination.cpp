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

void generateCombination(int index,int target, vint &candidates, vmat &ans, vint &curr){
    if(index==candidates.size()){
        if(target==0){
            ans.push_back(curr);
        }
        return;
    }


    //pickup element
    if(candidates[index]<=target){
        curr.push_back(candidates[index]);
        generateCombination(index, target-candidates[index], candidates, ans, curr);

        curr.pop_back();
    }
    
    generateCombination(index+1,target,candidates,ans,curr);
}

vmat combinationSum(vint & candidates, int target){
    vmat ans;
    vint curr;
    generateCombination(0,target,candidates,ans,curr);
    return ans;
}

int main() {
    FAST_IO;
    vint candidates={2,3,6,7};
    vmat ans=combinationSum(candidates,7);
    vmatprint(ans);
    return 0;
}
//by ad73prem