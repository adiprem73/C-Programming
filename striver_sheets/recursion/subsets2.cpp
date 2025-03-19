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

void subsetGenerate(vmat &ans, vint curr, int i, vint nums)
{
    if (i == nums.size())
    {
        ans.push_back(curr);
        return;
    }

    curr.push_back(nums[i]);
    subsetGenerate(ans, curr, i + 1, nums);
    curr.pop_back();
    subsetGenerate(ans, curr, i + 1, nums);
}

vector<vector<int>> subsetsWithDup(vector<int> &nums)
{
    vint curr;
    vmat ans;
    subsetGenerate(ans, curr, 0, nums);
    set<vector<int>> setA;
    for (int i = 0; i < ans.size(); i++)
    {
        sort(ans[i].begin(),ans[i].end());
        setA.insert(ans[i]);
    }
    ans = {};
    for (auto it : setA)
    {
        ans.push_back(it);
    }
    return ans;
}

int main()
{
    FAST_IO;
    vint nums = {4,4,4,1,4};
    vmat res = subsetsWithDup(nums);
    vmatprint(res);
    return 0;
}
// by ad73prem