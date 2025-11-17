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
        cin >> n;
        vector<long long> a(n);
        for (int i = 0; i < n; ++i)
            cin >> a[i];
        long long total = 0;
        long long best = 0;
        for (int i = 0; i < n; ++i)
        {
            int j = (i + 1) % n;
            long long w = max(a[i], a[j]);
            total += w;
            best = max(best, w);
        }
        cout << (total - best) << '\n';
    }
    return 0;
}
