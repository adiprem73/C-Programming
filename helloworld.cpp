#include <bits/stdc++.h>
using namespace std;

int mirror_map[10][5] = {
     {0, 0, 0, 0, 0},
     {1, 1, 1, 1, 1},
     {5, 5, 5, 5, 2},
     {-1, -1, 3, 3, 3},
     {-1, -1, -1, -1, 4},
     {2, 2, 2, 2, 5},
     {-1, -1, -1, -1, 6},
     {-1, -1, -1, -1, 7},
     {8, 8, 8, 8, 8},
     {-1, -1, -1, -1, 9}};

int op_index(char c)
{
    
    if (c == 'L')
        return 0;
    if (c == 'R')
        return 1;
    if (c == 'D')
        return 2;
    if (c == 'U')
        return 3;
    if (c == 'S')
        return 4;
    return -1; 
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string digits, ops;
    if (!(cin >> digits))
        return 0;
    cin >> ops;

    int n = digits.size();
    vector<char> kept;
    kept.reserve(n);

    for (int i = 0; i < n; ++i)
    {
        int d = digits[i] - '0';
        int col = op_index(ops[i]);
        if (col == -1)
            continue; 
        int mapped = mirror_map[d][col];
        if (mapped != -1)
        {
            kept.push_back(char('0' + mapped));
        }
    }

    if (kept.empty())
    {
        cout << 0 << '\n';
        return 0;
    }

    sort(kept.begin(), kept.end()); 

    if (kept[0] == '0')
    {
        int idx_nonzero = -1;
        for (int i = 1; i < (int)kept.size(); ++i)
        {
            if (kept[i] != '0')
            {
                idx_nonzero = i;
                break;
            }
        }
        if (idx_nonzero != -1)
        {
            swap(kept[0], kept[idx_nonzero]);
        }
        else
        {
            cout << 0 << '\n';
            return 0;
        }
    }

    for (char c : kept)
        cout << c;
    cout << '\n';
    return 0;
}
