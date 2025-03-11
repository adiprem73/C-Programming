// formulae for modular arithematic
// 1. (a+b)%m = ((a%m)+(b%m))%m
// 2. (a*b)%m = ((a%m)*(b%m))%m
// 3. (a-b)%m = ((a%m)-(b%m)+m)%m
// 4. (a/b)&m = ((a%m)*(b^-1)%m)%m


//given a numer n, print its factorial ... constraints 1<=n<=100
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define push(a) push_back(a)
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
    int n;
    cin>>n;
    ll fact=1;
    for(int i=2;i<=n;i++){
        fact=fact*i;
    }
    cout<<fact;
    //even large data typ[es like long long doesnt has the capability to store the numbers above the factorials of 21. hence for these the question will have hte line " print answer module m, m=47"

    return 0;
}
//by ad73prem