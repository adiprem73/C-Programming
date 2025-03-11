#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
#include <set>
#include <tuple>
using namespace std;

struct Circle {
  int cx, cy, r;
};

bool isValidPoint(int x, int y, int X, int Y, const vector<vector<bool>>& isBlockedByCircle) {
  return x >= 0 && x <= X && y >= 0 && y <= Y && !isBlockedByCircle[x][y];
}

bool bfs(int X, int Y, const vector<vector<bool>>& isBlockedByCircle) {
  queue<pair<int, int>> q;
  set<pair<int, int>> visited;
  q.push({0, Y});
  visited.insert({0, Y});
  vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

  while (!q.empty()) {
    pair<int, int> current = q.front();
    int x = current.first;
    int y = current.second;
    q.pop();

    if (x == X && y == 0) return true;

    for (const auto& dir : directions) {
      int newX = x + dir.first;
      int newY = y + dir.second;

      if (isValidPoint(newX, newY, X, Y, isBlockedByCircle) && visited.find({newX, newY}) == visited.end()) {
        visited.insert({newX, newY});
        q.push({newX, newY});
      }
    }
  }

  return false;
}

int main() {
  int T;
  cin >> T;

  while (T--) {
    int X, Y, N;
    cin >> X >> Y >> N;

    vector<Circle> circles(N);

    // Read in circle data
    for (int i = 0; i < N; ++i) {
      cin >> circles[i].cx >> circles[i].cy >> circles[i].r;
    }

    // Pre-compute circle influence areas
    vector<vector<bool>> isBlockedByCircle(X + 1, vector<bool>(Y + 1, false));
    for (const Circle& circle : circles) {
      for (int x = circle.cx - circle.r; x <= circle.cx + circle.r; ++x) {
        for (int y = circle.cy - circle.r; y <= circle.cy + circle.r; ++y) {
          if (isValidPoint(x, y, X, Y, isBlockedByCircle)) { // Check if point is within rectangle bounds
            isBlockedByCircle[x][y] = true;
          }
        }
      }
    }

    // Perform BFS to determine if we can reach the destination
    if (bfs(X, Y, isBlockedByCircle)) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }

  return 0;
}