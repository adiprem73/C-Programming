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

bool check (vector<int> &nums){
    int indexSmallest;
    int smallest=INT_MAX;
    for(int i=0;i<nums.size();i++){
        if(nums[i]<smallest){
            smallest=nums[i];
            indexSmallest=i;
        }
    }
    // cout<<"smallst index : "<<indexSmallest<<endl;
    // cout<<nums.size();
    bool ans=true;
    if(nums.size()==1){
        return true;
    }
    if(indexSmallest==0){
        // cout<<"1";
        for(int i=1;i<nums.size()-1;i++){
            if(nums[i]<=nums[i+1]){

            }
            else{
                return false;
            }
        }
        return true;
    }
    else if(indexSmallest==nums.size()-1){
        // cout<<"2";

        for(int i=1;i<nums.size()-2;i++){
            if(nums[i]<=nums[i+1]){

            }
            else{
                return false;
            }
        }
        return true;
    }
    else{
        vector<int> left;
        vector<int> right;
        if(left.size()==1){
            return true;
        }
        for(int i=0;i<indexSmallest;i++){
            left.push_back(nums[i]);
            
        }
        for(int i=indexSmallest+1;i<nums.size();i++){
            right.push_back(nums[i]);
        }

        // vprint(left);
        // vprint(right);
        if(right[right.size()-1]<left[0]){
            if(right.size()==1){
                return true;
            }
            for(int i=0;i<left.size()-1;i++){
                if(left[i]<=left[i+1]){
                    
                }
                else{
                    cout<<"hii";
                    return false;
                }
            }
            for(int i=0;i<right.size();i++){
                if(right[i]<=right[i+1]){
                    
                }
                else{
                    cout<<"hello";
                    return false;
                }
            }
        }
        else{
            return false;
        }
    }
    return true;
}

int main() {
    FAST_IO;
    vector<int> nums={1,2,3};
    cout<<check(nums);
    return 0;
}
//by ad73prem