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

        if (xa == xb)
        {
            cout << "Tie\n";
            continue;
        }

        int diff = xa ^ xb;
        int k = -1;
        for (int bit = 31; bit >= 0; --bit)
        {
            if ((diff >> bit) & 1)
            {
                k = bit;
                break;
            }
        }
        int lastIdx = -1;
        for (int i = n - 1; i >= 0; --i)
        {
            int ai = (a[i] >> k) & 1;
            int bi = (b[i] >> k) & 1;
            if (ai != bi)
            {
                lastIdx = i;
                break;
            }
        }
        if ((lastIdx + 1) % 2 == 1)
            cout << "Ajisai\n";
        else
            cout << "Mai\n";
    }
    return 0;
}
