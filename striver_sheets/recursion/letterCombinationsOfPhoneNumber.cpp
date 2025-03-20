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

map<char, string> mp = {
    {'2', "abc"},
    {'3', "def"},
    {'4', "ghi"},
    {'5', "jkl"},
    {'6', "mno"},
    {'7', "pqrs"},
    {'8', "tuv"},
    {'9', "wxyz"},
};

void generateCombinations(int index, string digits, string curr, vector<string> &ans)
{
    // base case
    if (index >= digits.size() && digits != "")
    {
        ans.push_back(curr);
        return;
    }

    for (int i = 0; i < mp[digits[index]].size(); i++)
    {
        curr += mp[digits[index]][i];
        generateCombinations(index + 1, digits, curr, ans);
        curr.pop_back();
    }
}

vector<string> letterCombinations(string digits)
{

    vector<string> ans;
    string curr = "";
    generateCombinations(0, digits, curr, ans);
    return ans;
}

int main()
{
    FAST_IO;
    string digits = "";
    vector<string> ans = letterCombinations(digits);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << endl;
    }
    return 0;
}
// by ad73prem