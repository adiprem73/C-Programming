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

//we need to make all thr possible permutations for btrute force usinsg recursion

void recurPermute(int index, vint &nums, vmat &ans){
    if(index==nums.size()){
        ans.push(nums);
        return;
    }
    f(i,index,nums.size()){
        swap(nums[index],nums[i]);
        recurPermute(index+1,nums,ans);
        swap(nums[index],nums[i]);
    }
}

vmat permute(vint& nums){
    vmat ans;
    recurPermute(0,nums,ans);
    return ans;
}

vmat filter(vmat ans){
    vint v=ans[0];
    sort(ans.begin(),ans.end());
    vmat answer;
    f(i,0,ans.size()){
        if(ans[i]==v){

        }
        else{
            answer.push(v);
            v=ans[i];
        }
    }
    answer.push(ans[ans.size()-1]);
    f(i,0,answer.size()){
        vprint(answer[i]);
    }

    cout<<endl;
    return answer;
}

void nextPermutation(vector<int>& nums) {
    vint a=nums;
    vmat perm=permute(nums);
    sort(perm.begin(),perm.end());
    perm=filter(perm);
    f(i,0,perm.size()){
        if(a==perm[perm.size()-1]){
            // vprint(perm[0]);
            nums=perm[0];
            break;
        }
        else if(perm[i]==a){
            // vprint(perm[i+1]);
            nums=perm[i+1];
            break;
        }
    } 
    vprint(nums);   
}



int main() {
    FAST_IO;
    vint v={1,1,5};
    
    // vmat vm=permute(v);
    // filter(vm);
    // f(i,0,vm.size()){
    //     vprint(vm[i]);
    // }
    // cout<<endl;
    // sort(vm.begin(),vm.end());
    // f(i,0,vm.size()){
    //     vprint(vm[i]);
    // }
    // cout<<endl;
    nextPermutation(v);
    return 0;
}
//by ad73prem