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

int removeDuplicates(vector<int>& nums){
    int cnt=0;
    for(int i=1;i<nums.size();i++){
        if(nums[i]==nums[i-1]){
            if(cnt==0){
                cnt++;
            }else{
                nums.erase(nums.begin()+i);
                --i;
            }
        }
        else{
            cnt=0;
        }
    }
    return nums.size();
}

int removeDuplicates2(vector<int> &nums)
{
    int n = nums.size();
    if (n <= 2)
        return n;
    int k = 2; //the vlaue of this will determine th writing ptr and the reading ptr will have the gap of
    for (int i = 2; i < n; ++i)
    {
        if (nums[i] != nums[k - 2])
            nums[k++] = nums[i];

        // vprint(nums);
    }
    nums.resize(k);
    return k;
}

int main() {
    FAST_IO;
    vint nums={1,1,1,2,2,3};
    cout<<removeDuplicates2(nums)<<endl;
    // vprint(nums);
    return 0;
}
//by ad73prem