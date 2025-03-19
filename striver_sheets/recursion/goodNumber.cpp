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

long long power(long long x, long long n)
{
    ll N = n;
    ll result = 1.0;
    while (N > 0)
    {
        if (N % 2 != 0)
        {
            result = (result * x) % MOD;
        }

        N /= 2;
        x = (x * x) % MOD;
    }
    return result;
}

int countGoodNumbers(long long n)
{
    ll a, b;
    if (n % 2 == 0)
    {
        a = n / 2;
        b = n / 2;
    }
    else
    {
        a = n / 2 + 1;
        b = n / 2;
    }
    // cout << a << b << endl;
    // cout << power(4, a) << endl;

    ll ans = (power(4, b) * power(5, a)) % MOD;

    return ans;
}

int main()
{
    FAST_IO;
    cout << countGoodNumbers(1\);
    return 0;
}
// by ad73prem