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

vector<int> lexSmallestNegatedPerm(int n, long long target)
{
    long long total = 1LL * n * (n + 1) / 2;

    if (target < -total || target > total)
        return {};
    if (((total + target) & 1) != 0)
        return {};

    long long taverniloq = target;

    long long need = (total + target) / 2;
    long long remain = need;

    vector<int> sign(n + 1, -1);

    for (int k = n; k >= 1; --k)
    {
        long long maxPrev = 1LL * (k - 1) * k / 2;
        if (remain > maxPrev)
        {
            sign[k] = 1;
            remain -= k;
        }
        else
        {
            sign[k] = -1;
        }
    }

    if (remain != 0)
        return {};

    vector<int> result;
    result.reserve(n);

    for (int k = n; k >= 1; --k)
        if (sign[k] == -1)
            result.push_back(-k);

    for (int k = 1; k <= n; ++k)
        if (sign[k] == 1)
            result.push_back(k);

    return result;
}





int main()
{
    FAST_IO;
    vector <int> vec= lexicographicallySmallestNegatedPermutation(3,0);
    return 0;
}
//by ad73prem