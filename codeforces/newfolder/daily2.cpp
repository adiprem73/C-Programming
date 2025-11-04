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

bool checkStartLeft(int pos, vector<int> nums){
    // left direction
    int n= nums.size();
    bool dir= false;// 1 for rigt and 0 for left
    while(pos<n && pos>=0){
        if (nums[pos]==0){
            if(dir){
                pos++;
            }
            else{
                pos--;
            }
        }
        else if(nums[pos]>0){
            nums[pos]--;
            dir=!dir;
            if(dir){
                pos++;
            }
            else{
                pos--;
            }
        }
    }
    for(int i=0;i<nums.size();i++){
        if(nums[i]){
            return false;
        }
    }
    return true;
}

bool checkStartRight(int pos, vector<int> nums)
{
    // right direction
    int n = nums.size();
    bool dir = true; // 1 for rigt and 0 for left
    while (pos < n && pos >= 0)
    {
        if (nums[pos] == 0)
        {
            if (dir)
            {
                pos++;
            }
            else
            {
                pos--;
            }
        }
        else if (nums[pos] > 0)
        {
            nums[pos]--;
            dir = !dir;
            if (dir)
            {
                pos++;
            }
            else
            {
                pos--;
            }
        }
    }
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i])
        {
            return false;
        }
    }
    return true;
}

int countValidSelections(vector<int>& nums) {
    int count=0;
    for(int i=0;i<nums.size();i++){
        if(nums[i]==0){
            if(checkStartLeft(i, nums)){
                count++;
                // cout<<i<<endl;
                // cout<<checkStartLeft(i,nums)<<endl;
                // cout<<checkStartRight(i, nums)<<endl;
            }
            if (checkStartRight(i, nums))
            {
                count++;
                // cout<<i<<endl;
                // cout<<checkStartLeft(i,nums)<<endl;
                // cout<<checkStartRight(i, nums)<<endl;
            }
        }
    }
    return count;
}

int main() {
    FAST_IO;
    vint nums = {1, 0, 2, 0, 3};
    cout<<countValidSelections(nums);
    return 0;
}
//by ad73prem