#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define push(a) push_back(a)
#define f(i, a, b) for(int i=a;i<b;i++)
#define all(x) x.begin(),x.end()
#define vprint(v) for (auto& elem : v) cout << elem << " "; cout << endl;
#define mprint(m) for (auto it:m) cout<<it.first<<" : "<<it.second<<endl; cout<<endl;
#define vmatprint(v) for(int i=0;i<v.size();i++) {for(int j=0;j<v[i].size();j++){ cout<<v[i][j]<<" ";}cout<<endl;}
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


int maxSubArray(vector<int>& nums) {
    int n=nums.size();
    f(i,1,n+1){
        int sum=0;
        f(j,0,i){
            sum+=nums[j];
        }
        cout<<sum<<endl;
        //sliding window
        cout<<" i : "<<i<<endl;
        f(j,i-1,n-1){
            sum=sum-nums[j-(i-1)]+nums[j+1];
            cout<<"sum : "<<sum<<endl;
        }
        cout<<endl;
    }
    return 0;
}


int main() {
    FAST_IO;
    vint v={-2,1,-3,4,-1,2,1,-5,4};
    maxSubArray(v);
    return 0;
}
//by ad73prem