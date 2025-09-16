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

//agian we are gping to loop over the limit that we decide for each subarray to have

int check(vector<int> nums, int x){
    //x is the limit for each subarray sum
    int cnt=1;
    int bag= nums[0];
    for(int i=1;i<nums.size();i++){
        if(bag+nums[i]<=x){
            bag+=nums[i];
        }else{
            cnt++;
            bag=nums[i];
        }
    }
    return cnt;
}
/*
int splitArray(vector<int> &nums, int k)
{
    int low= *max_element(nums.begin(), nums.end());
    int high= accumulate(nums.begin(), nums.end(), 0);
    // cout<<"low : "<<low<<" high : "<<high<<endl;
    for(int i=low;i<=high;i++){
        if(check(nums,i)<=k)return i;
    }
    return -1;
}
*/

int splitArray(vector<int> &nums, int k)
{
    int low = *max_element(nums.begin(), nums.end());
    int high = accumulate(nums.begin(), nums.end(), 0);
    // cout<<"low : "<<low<<" high : "<<high<<endl;
    while(low<=high){
        int mid= low +(high-low)/2;

        if(check(nums,mid)<=k){
            high=mid-1;
        }else{
            low=mid+1;
        }
    }
    return low;
}

int main()
{
    FAST_IO;
    vint nums = {7, 2, 5, 10, 8};
    // cout<<check(nums, 3)<<endl;
    cout<<splitArray(nums, 2);
    return 0;
}
//by ad73prem