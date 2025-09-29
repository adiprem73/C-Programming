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
/*
int largestPerimeter(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int n = nums.size();
    int maxi=0;
    for (int k = n - 1; k >= 2; k--)
    {
        int i=0;
        int j=k-1;
        while(i<j){
            if (nums[i] + nums[j] > nums[k])
            {
                maxi = max(maxi, nums[i] + nums[j] + nums[k]);

            }
            i++;
        }

    }
    return maxi;
}

*/

// sort the array in desceneding and cehck by makking tros of the three three elements

bool comp(int a, int b){
    if(a>b)return true;
    return false;
}

int largestPerimeter(vector<int> &nums)
{
    sort(nums.begin(), nums.end(), comp);
    int n=nums.size();

    for(int i=0;i<n-2;i++){
        if(nums[i]<nums[i+1]+nums[i+2]){
            return (nums[i]+nums[i+1]+nums[i+2]);
        }
    }return 0;
}

int main() {
    FAST_IO;
    vint nums={1,2,1,10};
    cout<<largestPerimeter(nums);
    return 0;
}
//by ad73prem