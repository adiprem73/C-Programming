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

int minOperations(vector<int> &nums)
{
    int mini=INT_MAX;
    for(int i=0;i<nums.size();i++){
        mini=min(mini, nums[i]);
    }
    int cnt;
    if(mini){
        cnt=1;
    }
    else{
        cnt=0;
    }
    // cout<<cnt;
    // int cnt=0;
    for(int i=0;i<nums.size();i++){
        if(nums[i]==mini){
            nums[i]=0;
        }
    }
    vprint(nums);
    nums.push_back(0);
    vector<int> proxy;
    for(int i=0;i<nums.size();i++){
        if(nums[i]==0){
            unordered_map<int,int> mp;
            for(auto it: proxy){
                mp[it]++;
            }
            cnt+=mp.size();
            proxy={};
        }else{
            proxy.push_back(nums[i]);
        }
    }
    return cnt;
}

int minOperation2(vector<int> &nums){
    stack<int> st;
    int cnt=0;
    for(auto it: nums){
        
            while( !st.empty() && it<st.top()){
                st.pop();
            }
        
        if(it==0)continue;
        
        if(st.empty() || st.top() <it){
            cnt++;
            st.push(it);
        }
    }
    return cnt;
}

int main()
{
    FAST_IO;
    vint nums = {1, 2, 1, 2, 1, 2};
    cout<<minOperation2(nums);   
    return 0;
}
//by ad73prem