#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define f(i, a, b) for(int i=a;i<b;i++)
#define all(x) x.begin(),x.end()
#define vprint(v) for (auto& elem : v) cout << elem << " "; cout << endl;
#define vmatprint(vv) for (auto& row : vv) { for (auto& elem : row) cout << elem << " "; cout << endl; } cout << endl;
#define mprint(m) for (auto it : m) cout << it.first << " : " << it.second << endl; cout << endl;
#define vint vector<int>
#define vstring vector<string>
#define vmat vector<vector<int>>
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define pii pair<int,int>
#define pll pair<ll,ll>
#define mii map<int,int>
#define mll map<ll,ll>

const int INF = 1e9;
const ll MOD = 1e9+7;

int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
    int n = status.size();
    vector<bool> visited(n, false);
    queue<int> q;
    for (int box : initialBoxes) {
        if (status[box] == 1) {
            q.push(box);
            visited[box] = true;
        }

        
    }
    int totalCandies = 0;
    while (!q.empty()) {
        int box = q.front();
        q.pop();
        totalCandies += candies[box];

        // Open the box and get keys
        for (int key : keys[box]) {
            status[key] = 1; // Mark the key as available
            if (!visited[key] && status[key] == 1) {
                q.push(key);
                visited[key] = true;
            }
        }

        // Check contained boxes
        for (int containedBox : containedBoxes[box]) {
            if (!visited[containedBox] && status[containedBox] == 1) {
                q.push(containedBox);
                visited[containedBox] = true;
            }
        }
    }
    return totalCandies;
}

int main() {
    FAST_IO;
    
    return 0;
}
//by ad73prem