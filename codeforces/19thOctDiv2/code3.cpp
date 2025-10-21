#include <bits/stdc++.h>
using namespace std;
using int64 = long long;
const int64 INF64 = (int64)4e18;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    if (!(cin >> T))
        return 0;
    while (T--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        int maxA = 0;
        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
            maxA = max(maxA, a[i]);
        }
        // b_i == 1 for all in this easy version -> cost = number of increments
        // Build frequency of values and sorted distinct values
        unordered_map<int, int> freqMap;
        freqMap.reserve(n * 2);
        for (int v : a)
            freqMap[v]++;

        vector<int> vals;
        vals.reserve(freqMap.size());
        for (auto &pr : freqMap)
            vals.push_back(pr.first);
        sort(vals.begin(), vals.end());
        int U = (int)vals.size();
        vector<int> freq(U);
        for (int i = 0; i < U; ++i)
            freq[i] = freqMap[vals[i]];

        // prefix counts (for quickly computing total count in an index range)
        vector<int> pref(U + 1, 0);
        for (int i = 0; i < U; ++i)
            pref[i + 1] = pref[i] + freq[i];

        // Sieve primes up to limit
        int limit = maxA + 200; // small buffer to allow primes slightly above maxA
        vector<char> isPrime(limit + 1, true);
        isPrime[0] = isPrime[1] = false;
        for (int p = 2; (int64)p * p <= limit; ++p)
            if (isPrime[p])
                for (int q = p * p; q <= limit; q += p)
                    isPrime[q] = false;
        vector<int> primes;
        for (int p = 2; p <= limit; ++p)
            if (isPrime[p])
                primes.push_back(p);

        int64 answer = INF64;

        // For each prime p, collect up to two smallest costs (i.e. two smallest M - v)
        for (int p : primes)
        {
            // We'll keep two smallest costs found so far for this prime
            int64 best1 = INF64, best2 = INF64;

            // iterate multiples M = p, 2p, 3p, ... up to maxA + p (cover intervals that include all present values)
            for (int64 M = p; M <= (int64)maxA + p; M += p)
            {
                int L = (int)max<int64>(1, M - p + 1); // interval [L .. M] of values assigned to this M
                int R = (int)min<int64>(M, maxA);

                // find indices in vals: first idx >= L, last idx <= R
                auto itL = lower_bound(vals.begin(), vals.end(), L);
                if (itL == vals.end())
                    continue;
                int idxL = (int)(itL - vals.begin());
                if (vals[idxL] > R)
                    continue; // no value in this interval
                auto itR = upper_bound(vals.begin(), vals.end(), R);
                int idxR = (int)(itR - vals.begin()) - 1; // last index <= R

                // total items in this interval
                int total_in_interval = pref[idxR + 1] - pref[idxL];

                if (total_in_interval <= 0)
                    continue;

                // fetch up to two largest present values in [idxL..idxR] taking multiplicities into account
                // largest value
                int v1_idx = idxR;
                int v1 = vals[v1_idx];
                int64 c1 = M - v1; // smallest cost within this interval
                if (freq[v1_idx] >= 2)
                {
                    // we can take two copies of this same value
                    // consider c1 twice
                    if (c1 < best1)
                    {
                        best2 = best1;
                        best1 = c1;
                    }
                    else if (c1 < best2)
                        best2 = c1;
                    if (c1 < best1)
                    {
                        best2 = best1;
                        best1 = c1;
                    } // ensure both updated properly
                    else if (c1 < best2)
                        best2 = c1;
                }
                else
                {
                    // only one copy of v1
                    // find second largest (if exists in this interval)
                    int64 c2 = INF64;
                    if (idxR - 1 >= idxL)
                    {
                        int v2_idx = idxR - 1;
                        int v2 = vals[v2_idx];
                        c2 = M - v2;
                        // But if freq[v2_idx] >= 2 we might want two copies of v2 instead? Already covered in next intervals.
                        // We'll consider up to two candidates per interval: c1 and c2 (if exist)
                    }
                    else
                    {
                        // no second distinct value in this interval
                        // but maybe freq[v1_idx] >=2 handled earlier
                    }
                    // insert candidates c1 and c2 (if finite) into best1,best2
                    if (c1 < best1)
                    {
                        best2 = best1;
                        best1 = c1;
                    }
                    else if (c1 < best2)
                        best2 = c1;
                    if (c2 != INF64)
                    {
                        if (c2 < best1)
                        {
                            best2 = best1;
                            best1 = c2;
                        }
                        else if (c2 < best2)
                            best2 = c2;
                    }
                }

                // small pruning: if best1 is 0 and best2 is 0 then answer is 0 and we can break
                if (best1 == 0 && best2 == 0)
                    break;
            } // end multiples M loop

            if (best2 != INF64)
            {
                answer = min(answer, best1 + best2);
                if (answer == 0)
                    break; // can't do better
            }
        } // end primes loop

        // Edge case: if answer stayed INF64, it means we couldn't form two elements divisible by same prime
        // That shouldn't happen for n>=2 because with enough increments we can raise elements to same p (primes exist),
        // but in practice set a fallback large value: hello
        if (answer == INF64)
            answer = (int64)1e18;

        cout << answer << '\n';
    }
    return 0;
}
