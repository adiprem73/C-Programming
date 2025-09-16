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

//min of max 
// place cows in stalls in such a way that the min distance between any two cows is maxium possible. basicallyy we want the cows to be as far apart to each other as possible

// sort the given array of the stalls
// we will go on from 1 , 2 , 3 ... and so on and allott cows only where its possible to get that minimum distace

// the range of answers will be from 1 to tthe difference between the min and the max from the array

// range : [ 1 to (max-min) ]

int aggressiveCows(vector<int> &nums, int k)
{
    sort(nums.begin(), nums.end());
    int n=nums.size();
    int s=1;
    int e=nums[n-1]- nums[0];
    // int ans=0;
    while(s<=e){
        int mid= s+ (e-s)/2;
        // cout<<"s: "<<s<<" e: "<<e<<endl;
        // cout<<"mid : "<<mid<<endl;
        int cnt=1; //counter for number of cows placed
        int lastCowPlacedAt= nums[0];
        for(int i=1;i<nums.size();i++){
            int diff= nums[i]-lastCowPlacedAt;
            if(diff>=mid){
                cnt++;
                lastCowPlacedAt=nums[i];
            }
        }
        // cout<<"cnt : "<<cnt<<endl;
        if(cnt<k){
            e=mid-1;
        }else{
            s=mid+1;
            // ans=mid;
        }
    }
    return e;
}

int main() {
    FAST_IO;
    vint nums={4,2,1,3,6};
    cout<<aggressiveCows(nums, 2);
    return 0;
}
//by ad73prem