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

bool func(int ind, int target, vector<int> arr){
    // base case
    if(target==0)return true;

    if(ind == 0 )return (arr[0]==target);

    bool notPick = func(ind-1, target, arr);

    bool pick=false;
    if(arr[ind]<=target){
        pick= func(ind-1, target- arr[ind], arr);
    }

    return (pick || notPick);
}

bool isSubsetSum(vector<int>arr, int target){
    return func(arr.size()-1, target, arr);
}

int main() {
    FAST_IO;
    
    return 0;
}
//by ad73prem