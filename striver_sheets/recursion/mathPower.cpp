#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define push(a) push_back(a)
#define f(i, a, b) for (int i = a; i < b; i++)
#define all(x) x.begin(), x.end()
#define vprint(v)            \
    for (auto &elem : v)     \
        cout << elem << " "; \
    cout << endl;
#define mprint(m)                                       \
    for (auto it : m)                                   \
        cout << it.first << " : " << it.second << endl; \
    cout << endl;
#define vint vector<int>
#define vstring vector<string>
#define vmat vector<vector<int>>
#define FAST_IO                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define pii pair<int, int>
#define pll pair<ll, ll>
#define mii map<int, int>
#define mll map<ll, ll>

const int INF = 1e9;
const ll MOD = 1e9 + 7;

double myPow(double x, int n)
{

    if(x==1.0){
        return x;
    }
    long long N=n;
    if(N<0){
        x=1/x;
        N=-1*N;
    }

    

    double result=1.0;
    while(N>0){
        if(N%2!=0){
            result*=x;
        }

        x*=x;
        N/=2;
    }
    return result;
}

int main()
{
    FAST_IO;
    double x = 2.00;
    int n = -2147483648;
    cout << myPow(x, n);
    return 0;
}
// by ad73prem