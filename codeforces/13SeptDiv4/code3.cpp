#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    if (!(cin >> t))
        return 0;
    while (t--)
    {
        int n;
        long long m;
        cin >> n >> m;
        vector<long long> a(n);
        vector<int> b(n);
        for (int i = 0; i < n; ++i)
            cin >> a[i] >> b[i];
        long long ans = 0;
        long long prev_time = 0;
        int prev_side = 0; 
        for (int i = 0; i < n; ++i)
        {
            long long len = a[i] - prev_time;
            int parity_needed = (b[i] != prev_side) ? 1 : 0;
            long long runs = len;
            if ((len % 2) != parity_needed)
                runs = len - 1;
            ans += runs;
            prev_time = a[i];
            prev_side = b[i];
        }
        ans += (m - prev_time);
        cout << ans << '\n';
    }
    return 0;
}
