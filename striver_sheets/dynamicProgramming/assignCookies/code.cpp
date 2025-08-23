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

int findContentChildren(vector<int> &g, vector<int> &s)
{
    int n=g.size(); //number of children
    int m=s.size(); //number of cookies
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());
    int cnt=0;
    int i=0,j=0;
    while(i<n && j<m){
        if(g[i]<=s[j]){
            cnt++;
            i++;
            j++;
        }else{
            j++; //its madatory to do j++ here, since if this cookie cantt satisfy this children witht he least greed as of now, the upcoming children will have higher greed only. so this cookie is basically useless.
        }
    }
    return cnt;
}

int main()
{
    FAST_IO;
    vint g={1,2};
    vint s={1,2,3};
    cout<<findContentChildren(g, s);

    return 0;
}
// by ad73prem