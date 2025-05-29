#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    
    vector<vector<int>> grid(N, vector<int>(M));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> grid[i][j];
        }
    }
    
    vector<vector<bool>> visited(N, vector<bool>(M, false));
    int peaks = 0;
    
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (!visited[i][j]) {
                bool is_peak = true;
                queue<pair<int, int>> q;
                q.push({i, j});
                visited[i][j] = true;
                
                while (!q.empty()) {
                    auto current = q.front();
                    q.pop();
                    int x = current.first;
                    int y = current.second;
                    
                    for (int dx = -1; dx <= 1; ++dx) {
                        for (int dy = -1; dy <= 1; ++dy) {
                            if (abs(dx) + abs(dy) != 1) continue; // Only 4 directions
                            int nx = x + dx;
                            int ny = y + dy;
                            
                            if (nx >= 0 && nx < N && ny >= 0 && ny < M) {
                                if (grid[nx][ny] > grid[x][y]) {
                                    is_peak = false;
                                }
                                if (grid[nx][ny] == grid[x][y] && !visited[nx][ny]) {
                                    visited[nx][ny] = true;
                                    q.push({nx, ny});
                                }
                            }
                        }
                    }
                }
                
                if (is_peak) {
                    peaks++;
                }
            }
        }
    }
    
    cout << peaks << endl;
    return 0;
}