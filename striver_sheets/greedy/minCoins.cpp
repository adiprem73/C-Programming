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



int main() {
    FAST_IO;
    vint coins={1,2,5,10,20,50,100,500,1000};
    int val=49;
    int cnt=0;
    for(int i=coins.size()-1;i>=0;i--){
        if(coins[i]<=val){
            cnt+=val/coins[i];
            val=val%coins[i];
        }
    }
    cout<<cnt;
    return 0;
}
//by ad73prem