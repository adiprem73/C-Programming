#include <bits/stdc++.h>
using namespace std;
using int64 = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    if (!(cin >> T))
        return 0;
    while (T--)
    {
        int n;
        cin >> n;
        vector<int64> a(n + 1);
        for (int i = 1; i <= n; ++i)
            cin >> a[i];

        vector<int64> P(n + 1);
        for (int i = 1; i <= n; ++i)
        {
            if (i == 1)
                P[i] = a[i];
            else
                P[i] = max(P[i - 1], a[i]);
        }

        const int64 INF = (int64)4e18;
        int64 ans = 0;

        for (int i = 1; i <= n; ++i)
        {
            if (i % 2 == 1)
            { 
                int64 leftPeak = (i - 1 >= 1) ? P[i - 1] : INF;
                int64 rightPeak = (i + 1 <= n) ? P[i + 1] : INF;
                int64 mn = min(leftPeak, rightPeak);
                int64 need = mn - 1;
                if (need < 0)
                    need = 0; 
                if (a[i] > need)
                    ans += (a[i] - need);
            }
        }

        cout << ans << '\n';
    }
    return 0;
}
