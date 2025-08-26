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

bool compare(string &s1, string &s2)
{
    int n = s1.length();
    int m = s2.length();

    if (n - m != 1)
        return false;

    int i = 0, j = 0;
    while (i < n)
    {
        if (s1[i] == s2[j])
        {
            i++;
            j++;
        }
        else
        {
            i++;
        }
    }
    if (i == n && j == m)
        return true;
    return false;
}

bool comp(string &s1, string &s2){
    return s1.size()<s2.size();
}

int longestStrChain(vector<string> &words)
{
    int maxi = INT_MIN;
    int n = words.size();
    sort(words.begin(), words.end(), comp);

    vector<int> dp(n, 1);
    for (int i = 0; i < n; i++)
    {
        for (int prev = 0; prev < i; prev++)
        {
            if (compare(words[i], words[prev]) && dp[i] < 1 + dp[prev])
            {
                dp[i] = 1 + dp[prev];
            }
        }
        if (dp[i] > maxi)
        {
            maxi = dp[i];
        }
    }
    return maxi;
}

int main()
{
    FAST_IO;
    vector<string> words = {"xbc", "pcxbcf", "xb", "cxbc", "pcxbc"};
    cout << longestStrChain(words);
    return 0;
}
// by ad73prem