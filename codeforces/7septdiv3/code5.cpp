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

// if the given array is a permutation then any number of operation wont change the rrray. hence we cna jsut gie sum of the arrya

// if the marrya has all the numebrs same, then the patern will be 0,0,0,,0 tp 1,1,1,1, to 0,0,0,0, to 1,1,1,1,1

// for general array : the permutation part remains constant. the elemetn which break the permutation replcaes all the elements that are greater than that number

// ther are three cases:
// Case 01: 0,1,2,.....i each element has frequency of 1 each and then i+1 has freq=0. means missing:

// splution for this: after one operation all the elements i+2, i+3, ......n will become i+1. the msising number ---> so this means after this operation you will either end up in case 2 or case 3

// Case 02: 0,1,2,.....i each element has frequency of 1 each and then i+1 has freq>1. means repeats
// solution: thse numbers will be replaced by an elemetn j which is missing from the array. after this operation wil weill get back to case 1

// Case 03: its a permutation
// solution: it doesnt change whatever be the number of operations
int main()
{
    FAST_IO;
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        vector<vector<int>> pos(n + 1);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            pos[a[i]].push_back(i); // storing the index of the number thatt it is present oon fo reahc numebr.
        }
        if (k == 1)
        {
            int mex;
            for (int i = 0; i <= n; i++)
            {
                if (pos[i].size() == 0)
                {
                    mex = i;
                    break;
                }
            }
            ll ans = 0;
            for (int i = 0; i < n; i++)
            { // looping throught e array
                if (a[i] > mex)
                {
                    ans += mex;
                }
                else if (pos[a[i]].size() == 1)
                { // i f alement only comes one time sthen its mex willbe itlsef
                    ans += a[i];
                }
                else
                {
                    ans += mex;
                }
            }
            cout << ans << endl;
            continue;
        }

        for (int i = 0; i <= n; i++)
        {
            if (pos[i].size() == 1)
                continue; // if the permuttion is continue we will follow here.
            else
            {
                ll ans = 1LL * i * (i - 1) / 2; // the order breaks in the position i so we take the sum of the all the previous lelements which where in the form of permutation that is... 0 + 1+2+3+4.....+i-1
                if (i == n - 1)
                {
                    ans += 1LL * n - 1; //integer overflow was the culprit in giving wrong ansers
                }
                else if (pos[i].size() == 0)
                { // case 01
                    if (k % 2)
                    {
                        ans += 1LL * (n - i) * i;
                    }
                    else
                    {
                        ans += 1LL * (n - i) * (i + 1);
                    }
                }
                else
                { // case 02
                    if (k % 2 == 0)
                    {
                        ans += 1LL * (n - i) * i;
                    }
                    else
                    {
                        ans += 1LL * (n - i) * (i + 1);
                    }
                }
                cout << ans << endl;
                break;
            }
        }
    }
    return 0;
}
// by ad73prem