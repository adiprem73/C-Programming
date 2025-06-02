#include <bits/stdc++.h>
using namespace std;

const int INF = INT_MIN/2;

//made by aditya prem

int n, k;
vector<vector<int>> grid;
int dp[1001][8][1001]; 

int solve(int row, int mask, int tiles_left) {
    if (tiles_left == 0) return 0;
    if (row >= n) return INF;
    int &res = dp[row][mask][tiles_left];
    if (res != -1) return res;
    res = solve(row + 1, 0, tiles_left);

    for (int col = 0; col < 3; ++col) {
        if (!(mask & (1<<col))) {
            if (row + 1 < n && !(mask & (1<<col))) {
                int sum = grid[row][col] + grid[row+1][col];
                res = max(res, sum + solve(row, mask | (1<<col), tiles_left - 1));
            }
           
            if (col + 1 < 3 && !(mask & (1<<(col+1)))) {
                int sum = grid[row][col] + grid[row][col+1];
                res = max(res, sum + solve(row, mask | (1<<col) | (1<<(col+1)), tiles_left - 1));
            }
        }
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    grid.assign(n, vector<int>(3));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < 3; ++j)
            cin >> grid[i][j];

    memset(dp, -1, sizeof(dp));
    int ans = solve(0, 0, k);
    cout << ans << '\n';
    return 0;
}