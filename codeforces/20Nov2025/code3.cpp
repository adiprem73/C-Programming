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

int main() {
    FAST_IO;
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        int xa = 0, xb = 0;
        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
            xa ^= a[i];
        }
        for (int i = 0; i < n; ++i)
        {
            cin >> b[i];
            xb ^= b[i];
        }
        if (xa==xb)
        {
            cout << "Tie\n";
            continue;
        }
        int lastDiff = -1;
        for (int i = n - 1; i >= 0; --i)
            if (a[i] != b[i])
            {
                lastDiff = i;
                break;
            }

        if ((lastDiff + 1) % 2 == 1)
            cout << "Ajisai\n";
        else
            cout << "Mai\n";
    }
    return 0;
}
//by ad73prem