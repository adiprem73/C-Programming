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

vector<int> intersection(vector<vector<int>> &nums)
{
    vector<int> freq(1001,0);
    for (int i = 0; i < nums[0].size(); i++)
    {
        freq[nums[0][i]]++;
    }
    for (int i = 1; i < nums.size(); i++)
    {
        vector<int> seen(1001,0);
        for (int j = 0; j < nums[i].size(); j++)
        {
            if (freq[nums[i][j]])
            {
                seen[nums[i][j]]=1;
            }
        }
        freq=seen;
        // vprint(freq);
    }
    vector<int> ans;
    for (int i = 0; i < freq.size(); i++)
    {
        if (freq[i] != 0)
        {
            ans.push_back(i);
        }
    }
    return ans;
}

int main() {
    FAST_IO;
    vector<vector<int>> nums={
        {3,1,2,4,5},
        {1,2,3,4},
        {3,4,5,6}
    };
    intersection(nums);
    return 0;
}
//by ad73prem