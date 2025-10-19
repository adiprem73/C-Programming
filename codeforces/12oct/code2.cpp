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
        int n, k;
        string s;
        cin >> n >> k;
        cin >> s;
        vector<int> pos;
        for (int i = 0; i < n; ++i)
            if (s[i] == '1')
                pos.push_back(i + 1); 
        int m = pos.size();
        int ans = 0;
        int j = 0;
        while (j < m)
        {
            int start = pos[j];
            int limit = start + k - 1;
            int p = j;
            while (p + 1 < m && pos[p + 1] <= limit)
                ++p;
            ++ans;
            int cover_until = pos[p] + k - 1;
            j = p + 1;
            while (j < m && pos[j] <= cover_until)
                ++j;
        }
        cout << ans << '\n';
    }
    return 0;
}
