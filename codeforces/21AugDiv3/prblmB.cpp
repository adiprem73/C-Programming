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

bool digitChk(ll n){
    bool flag= true;
    vint nums;
    while(n>0){
        int d= n%10 ;
        // cout<<d;
        nums.push_back(d);
        n=n/10;
    }
    // vprint(nums);

    for(int i=0;i<nums.size()-1;i++){
        if(nums[i]!=nums[i+1]){
            flag= false;
            break;
        }
    }
    return flag;
}

vint func(ll n){
    vint nums;
    ll temp=n;
    while(n>0){
        int d=n%10;
        nums.push_back(d);
        n=n/10;
    }
    vint ans;
    int size=nums.size();
    // vprint(nums);
    // cout<<nums.size();
    ll x=nums[0];
    // cout<<x;
    for(int i=0;i<size;i++){
        cout<<x<<endl;
        // ll y=x*pow(10, size-i);
        long long y = x * 1LL;
        for (int j = 0; j < size - i-1; j++) y *= 10;
        cout<<"y : "<<y<<endl;
        if(x+y== temp){
            ans.push_back(x);
        }
        x=(x*10)+nums[i];
    }
    return ans;
}

int main() {
    FAST_IO;
    int t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;

        if(digitChk(n)){
            // cout<<n<<endl;
            vint ans=func(n);
            cout<<ans.size()<<endl;
            vprint(ans);
        }
    }
    return 0;
}
//by ad73prem