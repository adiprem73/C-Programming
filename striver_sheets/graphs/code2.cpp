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
        long long k;
        cin >> n >> k;
        long long N = 1LL * n * n;
        long long s = N - k; 

        if (s == 1)
        {
            cout << "NO\n";
            continue;
        }

        vector<pair<int, int>> order;
        order.reserve(N);
        for (int i = 0; i < n; ++i)
        {
            if (i % 2 == 0)
            {
                for (int j = 0; j < n; ++j)
                    order.push_back({i, j});
            }
            else
            {
                for (int j = n - 1; j >= 0; --j)
                    order.push_back({i, j});
            }
        }

        auto dirTo = [&](pair<int, int> a, pair<int, int> b) -> char
        {
            int ar = a.first, ac = a.second, br = b.first, bc = b.second;
            if (br == ar - 1 && bc == ac)
                return 'U';
            if (br == ar + 1 && bc == ac)
                return 'D';
            if (br == ar && bc == ac - 1)
                return 'L';
            if (br == ar && bc == ac + 1)
                return 'R';
            return '?';
        };

        vector<string> g(n, string(n, '?'));

        if (s == 0)
        {
            for (long long i = 0; i + 1 < N; ++i)
            {
                auto a = order[i], b = order[i + 1];
                g[a.first][a.second] = dirTo(a, b);
            }
            auto last = order.back();
            int r = last.first, c = last.second;
            if (r == 0)
                g[r][c] = 'U';
            else if (r == n - 1)
                g[r][c] = 'D';
            else if (c == 0)
                g[r][c] = 'L';
            else
                g[r][c] = 'R'; 
        }
        else
        {
            auto v1 = order[0], v2 = order[1];
            g[v1.first][v1.second] = dirTo(v1, v2);
            g[v2.first][v2.second] = dirTo(v2, v1);
            for (long long i = 2; i < s; ++i)
            {
                auto a = order[i], b = order[i - 1];
                g[a.first][a.second] = dirTo(a, b);
            }
            if (s < N)
            {
                for (long long i = s; i + 1 < N; ++i)
                {
                    auto a = order[i], b = order[i + 1];
                    g[a.first][a.second] = dirTo(a, b);
                }
                auto last = order.back();
                int r = last.first, c = last.second;
                if (r == 0)
                    g[r][c] = 'U';
                else if (r == n - 1)
                    g[r][c] = 'D';
                else if (c == 0)
                    g[r][c] = 'L';
                else
                    g[r][c] = 'R';
            }
        }

        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                if (g[i][j] == '?')
                {
                    if (i + 1 < n)
                        g[i][j] = 'D';
                    else
                        g[i][j] = 'U';
                }

        cout << "YES\n";
        for (int i = 0; i < n; ++i)
            cout << g[i] << '\n';
    }
    return 0;
}
