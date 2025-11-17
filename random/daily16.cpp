#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];

        // Frequency of each distinct value
        vector<int> freq(n + 1, 0);
        for (int x : a)
            freq[x]++;
        vector<int> f;
        for (int i = 1; i <= n; i++)
            if (freq[i])
                f.push_back(freq[i]);

        // DP: reachable multisets represented by total counts
        vector<char> reachable(n + 1, 0);
        reachable[0] = 1;

        for (int c : f)
        {
            vector<char> nxt(n + 1, 0);
            for (int i = 0; i <= n; i++)
                if (reachable[i])
                {
                    for (int j = 1; j <= c; j++)
                    {
                        if (i + j <= n)
                            nxt[i + j] = 1;
                    }
                    // also allow skipping this value entirely
                    nxt[i] = 1;
                }
            reachable.swap(nxt);
        }

        int ans = 0;
        for (int i = 1; i <= n; i++)
            if (reachable[i])
                ans++;
        cout << ans % MOD << "\n";
    }
    return 0;
}
