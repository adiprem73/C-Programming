#include <bits/stdc++.h>
using namespace std;

#define ll long long
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

int func(int i, int j1, int j2, vector<vector<int>> &g)
{
    int n = g.size();
    int m = g[0].size();

    // base cases
    // base case #1 :  since we do recursion by moving j downwards we must check whether its  goin out of bounds
    if (j1 < 0 || j1 >= m || j2 < 0 || j2 >= m)
    {
        return -1e8;
    }

    // base case#2: this is to check whether the recursion has reached the last row
    if (i == n - 1)
    {
        if (j1 == j2)
            return g[i][j1];

        else
            return g[i][j1] + g[i][j2];
    }

    // now we can start exploring all the paths
    int maxi = -1e8;
    for (int dj1 = -1; dj1 <= 1; dj1++)
    {
        for (int dj2 = -1; dj2 <= 1; dj2++)
        {
            // if both end up in the same cell
            if (j1 == j2)
            {
                maxi = max(maxi, (g[i][j1] + func(i + 1, j1 + dj1, j2 + dj2, g)));
            }

            else{
                maxi = max(maxi, g[i][j1]+g[i][j2]+ func(i+1, j1+dj1, j2+dj2, g));
            }
        }
    }
    return maxi;
}

int maxChocolates(vector<vector<int>> &g)
{
    int n = g.size();
    int m = g[0].size();
    return func(0, 0, m-1,g);
}

int main()
{
    FAST_IO;
    vmat g={{2,3,1,2},{3,4,2,2},{5,6,3,5}};
    cout<<maxChocolates(g);
    return 0;
}
// by ad73prem