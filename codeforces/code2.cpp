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
    cin >> t;
    while(t--){
        int n;
        long long m;
        cin >> n >> m;

        vector<long long> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];

        sort(a.rbegin(), a.rend());

        ll ans = 0, cur = 0;
        int kmax = min((long long)n, m);

        for (int i = 0; i < kmax; i++)
        {
            cur += a[i] * (m - i); // assign oven i to time (m - i)
            ans = max(ans, cur);   // track the best total
        }

        cout << ans << "\n";
    }
    return 0;
}
//by ad73prem