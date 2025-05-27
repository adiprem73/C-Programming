#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int easytask(int x, int n, vector<int> a) {
    sort(a.begin(), a.end());
    int count = 0;
    int left = 0, right = n - 1;

    while (left < right) {
        int sum = a[left] + a[right];
        if (sum == x) {
            count++;
            left++;
            right--;
            // Optional: Skip duplicates
            while (left < right && a[left] == a[left - 1]) left++;
            while (left < right && a[right] == a[right + 1]) right--;
        } else if (sum < x) {
            left++;
        } else {
            right--;
        }
    }

    return count;
}


int optimizeHierarchy(int n, int k, int edges_rows, int edges_columns, int** edges) {
    if (n <= 2) return max(0, n - 1 - k);
    
    vector<vector<int>> adj(n + 1);
    vector<int> degree(n + 1, 0);
    for (int i = 0; i < edges_rows; ++i) {
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
        degree[u]++;
        degree[v]++;
    }
    
    queue<int> leaves;
    for (int i = 1; i <= n; ++i) {
        if (degree[i] == 1) {
            leaves.push(i);
        }
    }
    
    int remaining_nodes = n;
    while (k > 0 && remaining_nodes > 2) {
        int sz = leaves.size();
        if (sz == 0) break;
        for (int i = 0; i < sz && k > 0; ++i) {
            int u = leaves.front();
            leaves.pop();
            degree[u] = 0;
            remaining_nodes--;
            for (int v : adj[u]) {
                if (degree[v] > 0) {
                    degree[v]--;
                    if (degree[v] == 1) {
                        leaves.push(v);
                    }
                }
            }
            k--;
        }
    }
    
    if (remaining_nodes <= 2) return remaining_nodes - 1;
    
    // Find the diameter of the remaining tree
    vector<int> dist(n + 1, -1);
    queue<int> q;
    int start_node = -1;
    for (int i = 1; i <= n; ++i) {
        if (degree[i] > 0) {
            start_node = i;
            break;
        }
    }
    if (start_node == -1) return 0;
    
    q.push(start_node);
    dist[start_node] = 0;
    int farthest_node = start_node;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : adj[u]) {
            if (degree[v] > 0 && dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
                if (dist[v] > dist[farthest_node]) {
                    farthest_node = v;
                }
            }
        }
    }
    
    fill(dist.begin(), dist.end(), -1);
    q.push(farthest_node);
    dist[farthest_node] = 0;
    int diameter = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : adj[u]) {
            if (degree[v] > 0 && dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
                if (dist[v] > diameter) {
                    diameter = dist[v];
                }
            }
        }
    }
    
    return diameter;
}

int main() {
    int x=13;
    int n=6;
    vector<int> arr={2,4,9,8,6,1};
    cout<<easytask(x,n,arr);
    
    return 0;
}