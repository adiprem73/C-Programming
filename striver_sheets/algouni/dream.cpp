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
//made by aditya prem
const int INF = 1e9;
const ll MOD = 1e9+7;

int main() {
    FAST_IO;
    int n, k;
    cin >> n >> k;

    vector<pair<int, int>> vp(n);
    for (int i = 0; i < n; ++i) {
        cin >> vp[i].first >> vp[i].second;
    }

    // Function to generate all non-empty subsets (power set except empty set)
    auto getAllSubsets = [](const vector<pair<int, int>>& arr) {
        vector<vector<pair<int, int>>> res;
        int n = arr.size();
        for (int mask = 1; mask < (1 << n); ++mask) {
            vector<pair<int, int>> temp;
            for (int i = 0; i < n; ++i) {
                if (mask & (1 << i)) temp.push_back(arr[i]);
            }
            res.push_back(temp);
        }
        return res;
    };

    vector<vector<pair<int, int>>> allSubarrays = getAllSubsets(vp);

    // Example: print all subsets
    for (const auto& sub : allSubarrays) {
        for (const auto& p : sub) {
            // cout << "(" << p.first << "," << p.second << ") ";
        }
        // cout << endl;
    }

    // Filter subsets where the first values of pairs are in ascending order
    vector<vector<pair<int, int>>> filteredSubarrays;
    for (const auto& sub : allSubarrays) {
        bool isAscending = true;
        for (size_t i = 1; i < sub.size(); ++i) {
            if (sub[i].first < sub[i - 1].first) {
                isAscending = false;
                break;
            }
        }
        if (isAscending) {
            filteredSubarrays.push_back(sub);
        }
    }

    // Example: print filtered subsets
    // cout << "Filtered subsets (first values strictly ascending):" << endl;
    for (const auto& sub : filteredSubarrays) {
        for (const auto& p : sub) {
            // cout << "(" << p.first << "," << p.second << ") ";
        }
        // cout << endl;
    }

    // Print subsets where the sum of the pairs' second elements is k
    int count=0;
    // cout << "Subsets where sum of second elements is " << k << ":" << endl;
    for (const auto& sub : filteredSubarrays) {
        int sum = 0;
        for (const auto& p : sub) {
            sum += p.second;
        }
        if (sum >= k) {
            count++;
            for (const auto& p : sub) {
                // cout << "(" << p.first << "," << p.second << ") ";
            }
            // cout << endl;
        }
    }
    cout<<count;

    return 0;
}
//by ad73prem