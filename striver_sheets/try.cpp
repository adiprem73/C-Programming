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

int arrayPairSum(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    int sum = 0;
    for (int i = 0; i < nums.size() - 1; i = i + 2)
    {
        // cout<<nums[i]<<" "<<nums[i+1]<<endl;
        sum = sum+min(nums[i], nums[i + 1]);
    }
    return sum;
}

int main()
{
    FAST_IO;
    vint nums={1,4,3,2};
    cout<<arrayPairSum(nums);
    return 0;
}
//by ad73prem