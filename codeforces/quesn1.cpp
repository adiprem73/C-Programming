#include <iostream>
#include <string>

using namespace std;

bool willMeet(int n, int a, int b, string s) {
    int dx = 0, dy = 0;
    int x = 0, y = 0;

    for (char c : s) {
        if (c == 'N') dy++;
        else if (c == 'S') dy--;
        else if (c == 'E') dx++;
        else dx--;

        if (x == a && y == b) return true;
    }

    // Check for future intersections using the net change
    return (a - x) * dy == (b - y) * dx;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, a, b;
        cin >> n >> a >> b;
        string s;
        cin >> s;

        cout << (willMeet(n, a, b, s) ? "YES" : "NO") << endl;
    }

    return 0;
}