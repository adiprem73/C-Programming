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

int feasibleSpeed(vector<int> &piles, int k, int h)
{
    int totalTime = 0;
    int n = piles.size();
    for (int i = 0; i < n; i++)
    {
        totalTime += piles[i] / k;
        if (piles[i] % k != 0)
        {
            totalTime += 1;
        }
    }
    return totalTime;
}

int minEatingSpeed(vector<int> &piles, int h)
{
    int s = 1; // minimum eating speed
    auto e = *max_element(piles.begin(), piles.end());
    if (piles.size() == 1)
    {
        // cout << ceil(piles[0] / h) << endl;
        return ceil((piles[0] + h - 1) / h);
    }

    while (s < e)
    {
        int mid = s + (e - s) / 2;
        int totalTime = feasibleSpeed(piles, mid, h);

        if (totalTime <= h)
        {
            e=mid;
        }
        else
        {
            s = mid + 1;
        }
    }
    return s;
}

int main()
{
    FAST_IO;
    vint piles = {312884470};
    int h = 312884469;
    cout << minEatingSpeed(piles, h);
    return 0;
}
// by ad73prem