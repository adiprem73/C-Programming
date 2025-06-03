#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define f(i, a, b) for (int i = a; i < b; i++)
#define all(x) x.begin(), x.end()
#define vprint(v)            \
    for (auto &elem : v)     \
        cout << elem << " "; \
    cout << endl;
#define vmatprint(vv)            \
    for (auto &row : vv)         \
    {                            \
        for (auto &elem : row)   \
            cout << elem << " "; \
        cout << endl;            \
    }                            \
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

vector<string> findRelativeRanks(vector<int> &score)
{
    int n = score.size();
    vector<int> temp = score;
    sort(score.begin(), score.end());
    reverse(score.begin(), score.end());
    map<int, string> mp;
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            mp[score[i]] = "Gold Medal";
        }
        else if (i == 1)
        {
            mp[score[i]] = "Silver Medal";
        }
        else if (i == 2)
        {
            mp[score[i]] = "Bronze Medal";
        }
        else
        {
            mp[score[i]] = to_string(i + 1);
        }
    }
    vector<string> ans;
    for (int i = 0; i < n; i++)
    {
        ans.push_back(mp[temp[i]]);
}
return ans;
}

int main()
{
    FAST_IO;
    // vint nums={5,4,3,2,1};
    vint nums = {10, 3, 8, 9, 4};

    findRelativeRanks(nums);
    return 0;
}
// by ad73prem