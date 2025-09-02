#include <bits/stdc++.h>
using namespace std;

static inline long long makeKey(int dAB, int dCD, int offset, int mult) {
    long long x = (long long)(dAB + offset);
    long long y = (long long)(dCD + offset);
    return x * mult + y;
}

long long getConjugatePairs(string s) {
    int n = s.size();
    int offset = n; 
    int mult = 2*offset + 1;  

    unordered_map<long long, long long> freq;
    freq.reserve(n*2);
    freq.max_load_factor(0.7f);

    long long initKey = makeKey(0, 0, offset, mult);
    freq[initKey] = 1;

    int diffAB = 0, diffCD = 0;
    long long answer = 0;

    for (char c : s) {
        switch (c) {
            case 'a': diffAB++; break;
            case 'b': diffAB--; break;
            case 'c': diffCD++; break;
            case 'd': diffCD--; break;
            default: break; 
        }

        long long key = makeKey(diffAB, diffCD, offset, mult);
        auto it = freq.find(key);
        if (it != freq.end()) {
            answer += it->second;
            it->second++;
        } else {
            freq[key] = 1;
        }
    }
    return (int)answer;
}




int main() {
    cout << getConjugatePairs(string("abcdad")) << "\n"; // prints 4
    cout << getConjugatePairs(string("a")) << "\n";   // prints 2
    return 0;
}


