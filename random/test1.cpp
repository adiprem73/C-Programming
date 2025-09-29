#include <bits/stdc++.h>
using namespace std;

// Function required by the problem/platform
int getDistinctPairs(vector<int> stocksProfit, long target)
{
    long long t = (long long)target;
    unordered_map<long long, long long> freq;
    freq.reserve(stocksProfit.size() * 2 + 10);

    for (int v : stocksProfit)
        ++freq[(long long)v];

    long long distinct = 0;
    for (const auto &p : freq)
    {
        long long x = p.first;
        long long y = t - x;
        if (x < y)
        {
            if (freq.find(y) != freq.end())
                ++distinct;
        }
        else if (x == y)
        {
            if (p.second >= 2)
                ++distinct;
        }
        // x > y pairs are counted when iterating y
    }
    return (int)distinct;
}

// Optional: small main to test locally (matches typical judge input format)
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n;
    if (!(cin >> n))
        return 0;
    vector<int> arr;
    arr.reserve(n);
    for (long long i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        arr.push_back(x);
    }
    long target;
    cin >> target;

    cout << getDistinctPairs(arr, target) << '\n';
    return 0;
}