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

vector<int> findErrorNums(vector<int> &nums)
{
    int n= nums.size();
    vector<int> mp(n+1, 0);

    for(int i=0;i<n;i++){
        mp[i]++;
    }

    int missing, extra;
    for(int i=0;i<mp.size();i++){
        if(mp[i]==2){
            extra= i;
        }
        if(mp[i]==0){
            missing= i;
        }
    }
    return {extra, missing};
}

vector<int> smallerNumbersThanCurrent(vector<int> &nums)
{
    int n = nums.size();
    vector<int> freq(101);
    for (int i = 0; i < n; i++)
    {
        freq[nums[i]]++;
    }
    // vprint(freq);
    int rank = 0;
    map<int, int> mp;
    for(int i=0;i<=100;i++){
        if(freq[i]>0){
            mp[i]=rank;
            rank+=freq[i];
        }
    }
    // mprint(mp);
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        ans.push_back(mp[nums[i]]);
    }
    return ans;
}

int main()
{
    FAST_IO;
    vint nums = {8, 1, 2, 2, 3};
    vprint(smallerNumbersThanCurrent(nums));
    return 0;
}
//by ad73prem