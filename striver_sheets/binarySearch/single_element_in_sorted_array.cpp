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

int singleNonDuplicate(vector<int>& nums) {

    int n=nums.size();

    //resolving the edge cases
    if(n==1)  return nums[0];
    if(nums[0]!=nums[1]){
        return nums[0];
    }
    if(nums[n-1]!=nums[n-2]){
        return nums[n-1];
    }

    int s=0,e=n-1;
    while(s<=e){
        int mid=s+(e-s)/2;
        // cout<<"hi";
        if(nums[mid]!=nums[mid+1]&&nums[mid]!=nums[mid-1]){
            return nums[mid];
        }


        //left side eleimination condition
        if(((mid%2==0)&&nums[mid]==nums[mid+1])||((mid%2==1)&&nums[mid]==nums[mid-1])){
            s=mid+1;
        }

        //right side elimination condition
        else{
            e=mid-1;
        }
    }
    return -1;


}

int main() {
    FAST_IO;
    vint  nums={1,1,2,3,3,4,4,8,8};
    cout<<singleNonDuplicate(nums);
    return 0;
}
//by ad73prem