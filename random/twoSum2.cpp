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

vector<int> twoSum(vector<int>& numbers, int target) {
    int n=numbers.size();
    int l=0;
    int r=n-1;
    while(l<r){
        int sum= numbers[l]+numbers[r];
        if(sum < target){
            l++;
        }else if(sum>target){
            r--;
        }else {
            return {l+1, r+1};
        }
    }      
}

int main() {
    FAST_IO;
    vint nums={-1,0};
    vprint(twoSum(nums, -1));
    return 0;
}
//by ad73prem