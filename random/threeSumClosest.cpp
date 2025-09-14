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

int threeSumClosest(vector<int> &nums, int target)
{
    sort(nums.begin(), nums.end());
    int closest= nums[0]+nums[1]+nums[2];
    for( int i=0;i<nums.size();i++){
        int x=nums[i];
        int newtarget= target-x;
        int s=i+1;
        int e=nums.size()-1;
        while(s<e){
            
            int sum= nums[i]+nums[s]+nums[e];

            if(abs(target-sum)<abs(target-closest)){
                closest=sum;
            }


            if(sum == target){
                return sum;
            }
            else if (sum<target){
                s++;
            }
            else{
                e--;
            }
        }
    }
    return closest;
}

int main()
{
    FAST_IO;
    vint nums={3,6,2,9,0,4,1};
    cout<<threeSumClosest(nums, 2);
    return 0;
}
//by ad73prem