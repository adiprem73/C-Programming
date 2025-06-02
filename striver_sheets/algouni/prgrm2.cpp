#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

bool isFeasible(ll D, const vector<pair<ll, ll>>& islands, ll N) {
    ll count = 0;
    ll last_pos = -1e18; // Initialize to a very small number

    for (const auto& island : islands) {
        ll L = island.first;
        ll R = island.second;

        // The first position in the current island that is at least D away from last_pos
        ll start = max(L, last_pos + D);

        if (start > R) {
            continue; // No positions available in this island
        }

        // Number of people that can be placed in this island starting at 'start' with step D
        ll num = (R - start) / D + 1;
        count += num;

        // Update last_pos to the last position used in this island
        last_pos = start + (num - 1) * D;

        if (count >= N) {
            return true;
        }
    }

    return count >= N;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll N, M;
    cin >> N >> M;

    vector<pair<ll, ll>> islands(M);
    for (ll i = 0; i < M; ++i) {
        cin >> islands[i].first >> islands[i].second;
    }

    // Sort islands based on their starting position
    sort(islands.begin(), islands.end());

    // Binary search for the maximum possible D
    ll low = 1;
    ll high = 1e18; // A sufficiently large upper bound
    ll answer = 1;

    while (low <= high) {
        ll mid = low + (high - low) / 2;

        if (isFeasible(mid, islands, N)) {
            answer = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    cout << answer << endl;

    return 0;
}