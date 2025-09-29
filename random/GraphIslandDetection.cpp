#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define f(i, a, b) for (int i = a; i < b; i++)
#define all(x) x.begin(), x.end()
#define vprint(v)            \
    for (auto &elem : v)     \
        cout << elem << " "; \
    cout << endl;
#define mprint(m)                                       \
    for (auto it : m)                                   \
        cout << it.first << " : " << it.second << endl; \
    cout << endl;
#define vint vector<int>
#define vstring vector<string>
#define vmat vector<vector<int>>
#define FAST_IO                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define pii pair<int, int>
#define pll pair<ll, ll>
#define mii map<int, int>
#define mll map<ll, ll>

const int INF = 1e9;
const ll MOD = 1e9 + 7;

vector<int> dx = {-1, 0, 1, -1, 1, -1, 0, 1};
vector<int> dy = {-1, -1, -1, 0, 0, 1, 1, 1};

void dfs(int r, int c, vector<vector<char>> &grid, vector<vector<int>> &visit)
{
    visit[r][c] = 1;
    int n = grid.size();
    int m = grid[0].size();
    
    for (int i = 0; i < 8; i++)
    {
        int nrow = r + dx[i];
        int ncol = c + dy[i];
        if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && visit[nrow][ncol] == 0 && grid[nrow][ncol] == '1')
        {
            dfs(nrow, ncol, grid, visit);
        }
    }
}

int numIslands(vector<vector<char>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> visit(n, vector<int>(m, 0));
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!visit[i][j] && grid[i][j] == '1')
            {
                dfs(i, j, grid, visit);
                cnt++;
            }
        }
    }
    return cnt;
}

int main()
{
    FAST_IO;

    return 0;
}
// by ad73prem