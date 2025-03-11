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

int fibonacci(int N){
    if(N<=1){
        return N;
    }
    int last=fibonacci(N-1);
    int slast=fibonacci(N-2);
    return  last+slast;
}

int fib(int n) {
    if(n<=1){
        return n;
    }
    int last=fib(n-1);
    int slast=fib(n-2);
    return last+slast;
    }

int main() {
    FAST_IO;
    cout<<fibonacci(4);
    return 0;
}
//by ad73prem