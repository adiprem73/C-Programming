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

int countValidSelections(vector<int> &nums)
{
    int n= nums.size();
    int leftSum = 0;
    int sum = accumulate(nums.begin(), nums.end(), 0);
    int rightSum = sum;
    int ans=0;
    for (int i = 0; i < n; i++)
    {
        if(nums[i]==0){
            if(leftSum-rightSum>=0 && leftSum-rightSum<=1){
                ans++;
            }

            if(rightSum-leftSum>=0 && rightSum-leftSum<=1){
                ans++;
            }
        }
        else{
            leftSum+= nums[i];
            rightSum += nums[i];
        }
    }
    return ans;
}

int main() {
    FAST_IO;
    
    return 0;
}
//by ad73prem