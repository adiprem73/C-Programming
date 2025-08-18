#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> firstArray, vector<int> secondArray) {
    if (firstArray.empty() || secondArray.empty()) return 0;

    size_t totalPrefixes = 0;
    vector<string> secondStrs;
    secondStrs.reserve(secondArray.size());
    for (int num : secondArray) {
        string s = to_string(num);
        secondStrs.push_back(s);
        totalPrefixes += s.size();
    }

    unordered_set<string> prefixes;
    prefixes.reserve(max<size_t>(16, totalPrefixes * 2)); // reduce rehashes

    for (const string &s : secondStrs) {
        string p;
        p.reserve(s.size());
        for (char c : s) {
            p.push_back(c);
            prefixes.insert(p);
        }
    }

    int best = 0;
    for (int num : firstArray) {
        string s = to_string(num);
        if ((int)s.size() <= best) continue;

        for (int len = (int)s.size(); len > 0; --len) {
            if (len <= best) break; // cannot improve further for this number
            if (prefixes.find(s.substr(0, len)) != prefixes.end()) {
                best = len;
                break; // no need to check shorter prefixes for this number
            }
        }
        if (best == 10) break;
    }

    return best;
}

int main() {
    vector<int> a1 = {25, 288, 2655, 54546, 54, 555};
    vector<int> b1 = {2, 255, 266, 244, 26, 5, 54547};
    cout << solution(a1, b1) << " (expected 4)\n";

    vector<int> a2 = {25, 288, 2655, 544, 54, 555};
    vector<int> b2 = {2, 255, 266, 244, 26, 5, 5444444};
    cout << solution(a2, b2) << " (expected 3)\n";

    vector<int> a3 = {817, 99};
    vector<int> b3 = {1999, 1901};
    cout << solution(a3, b3) << " (expected 0)\n";

    // some edge cases
    cout << solution({}, {1,2,3}) << " (expected 0 - empty firstArray)\n";
    cout << solution({1,2,3}, {}) << " (expected 0 - empty secondArray)\n";

    return 0;
}
