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

int findKthPositive(vector<int> &arr, int k)
{
    int cnt=0;
    int e= *max_element(arr.begin(), arr.end());
    vector<int> missing;
    for(int i=1;i<e;i++){
        if(find(arr.begin(), arr.end(), i) == arr.end()){
            missing.push_back(i);
            cnt++;
        }
    }
    if(cnt>=k){
        return missing[k-1];
    }else{
        int temp=k-cnt;
        return e+temp;
    }   
}

int main()
{
    FAST_IO;
    vint nums = {1,2,4,5};
    cout<<findKthPositive(nums, 3);
    return 0;
}
//by ad73prem