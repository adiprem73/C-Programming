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
#define ull unsigned long long
const int INF = 1e9;
const ll MOD = 1e9+7;

int main() {
    FAST_IO;
    int t;
    cin >> t;
    while (t--)
    {
        ull k, x;
        cin >> k >> x; //choco
        ull s= 1ULL<<(k+1); //total
        ull u= s-x; //vani
        vint ops;
        while(x!=u){
            if(x<u){
                ops.push_back(1);
                u=u-x; //badhe number se chhote ko subtract kr diya
                x=x+x; //chhote number ko double kr diay 
                               
            }else if(u<x){
                ops.push_back(2);
                x=x-u;
                u=u+u;
                
            }
        }
        reverse(ops.begin(), ops.end());
        cout<<ops.size()<<endl;
        vprint(ops);    
    }

    return 0;
}
//by ad73prem