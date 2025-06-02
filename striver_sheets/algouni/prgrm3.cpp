#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

typedef long long ll;

struct Castle {
    int h;
    ll g;
};

void generate_sequences(const vector<Castle>& castles, int start, int end, vector<pair<int, ll>>& sequences) {
    int n = end - start;
    for (int mask = 1; mask < (1 << n); ++mask) {
        int last_h = -1;
        ll total_g = 0;
        bool valid = true;
        for (int i = 0; i < n; ++i) {
            if (mask & (1 << i)) {
                if (last_h == -1 || castles[start + i].h >= last_h) {
                    last_h = castles[start + i].h;
                    total_g += castles[start + i].g;
                } else {
                    valid = false;
                    break;
                }
            }
        }
        if (valid) {
            sequences.emplace_back(last_h, total_g);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    ll K;
    cin >> N >> K;

    vector<Castle> castles(N);
    for (int i = 0; i < N; ++i) {
        cin >> castles[i].h >> castles[i].g;
    }

    int mid = N / 2;
    vector<pair<int, ll>> left_sequences, right_sequences;
    generate_sequences(castles, 0, mid, left_sequences);
    generate_sequences(castles, mid, N, right_sequences);

    // Count sequences in left or right that alone satisfy total_g >= K
    ll count = 0;
    for (const auto& seq : left_sequences) {
        if (seq.second >= K) {
            count++;
        }
    }
    for (const auto& seq : right_sequences) {
        if (seq.second >= K) {
            count++;
        }
    }

    // Preprocess right_sequences: group by last_h and sort g's for each h
    map<int, vector<ll>> right_map;
    for (const auto& seq : right_sequences) {
        right_map[seq.first].push_back(seq.second);
    }
    // Sort g's for each h in right_map
    for (auto& entry : right_map) {
        sort(entry.second.begin(), entry.second.end());
    }

    // For each left sequence, find valid right sequences
    for (const auto& left_seq : left_sequences) {
        if (left_seq.second >= K) continue;
        int h_left = left_seq.first;
        ll g_left = left_seq.second;
        ll needed_g = K - g_left;

        // Iterate over all h in right_map >= h_left
        auto it = right_map.lower_bound(h_left);
        for (; it != right_map.end(); ++it) {
            const auto& g_list = it->second;
            // Count number of g in g_list >= needed_g
            auto git = lower_bound(g_list.begin(), g_list.end(), needed_g);
            count += g_list.end() - git;
        }
    }

    cout << count << endl;

    return 0;
}