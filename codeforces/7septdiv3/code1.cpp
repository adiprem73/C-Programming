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

// doesnt matter what operation you do in this, the result will always come to be even

int main() {
    FAST_IO;
    int t;
    cin >> t;
    while(t--){
        int k,x;
        cin>>k>>x;
        int ans= x*(1LL<<k); //pow does wrong output in higher values of k so thereofre its always good to use the left shift operator for more precise results... 
        cout<<ans<<endl;
    }
    return 0;
}
//by ad73prem