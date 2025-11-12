#include <bits/stdc++.h>
using namespace std;

vector<long long> encryptionValidity(long long instructionCount,
                                     long long validityPeriod,
                                     const vector<int> &keys)
{
    if (keys.empty())
        return {0, 0};

    const int MAXA = 100000;
    vector<int> freq(MAXA + 1, 0);


    for (int x : keys)
    {
        if (x >= 1 && x <= MAXA)
            freq[x]++;
    }

    vector<int> divCnt(MAXA + 1, 0);
    for (int d = 2; d <= MAXA; ++d)
    {
        if (freq[d] == 0)
            continue;
        for (int m = d; m <= MAXA; m += d)
        {
            divCnt[m] += freq[d];
        }
    }

    int bestDegree = 0;
    for (int x : keys)
    {
        bestDegree = max(bestDegree, divCnt[x]);
    }

    long long encryption_strength = static_cast<long long>(bestDegree) * 100000LL;
    long long attempts = instructionCount * validityPeriod; 
    long long success = (attempts >= encryption_strength) ? 1LL : 0LL;

    return {success, encryption_strength};
}

int main()
{
    long long instructionCount = 1000;
    long long validityPeriod = 10000;
    vector<int> keys = {2, 4, 8, 5, 2};

    auto ans = encryptionValidity(instructionCount, validityPeriod, keys);
    cout << ans[0] << " " << ans[1] << "\n"; // Expected: 1 400000
    return 0;
}
