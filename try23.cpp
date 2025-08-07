#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct SuffixAutomaton {
    struct State { int next[26]; int link, len; State() { fill(begin(next), end(next), -1); link = -1; len = 0;} };
    vector<State> st;
    int last;
    SuffixAutomaton(int maxlen = 10000) { st.reserve(2 * maxlen); st.push_back(State()); last = 0; }
    void extend(char cc) {
        int c = cc - 'a';
        int cur = st.size(); st.push_back(State()); st[cur].len = st[last].len + 1;
        int p = last;
        while (p != -1 && st[p].next[c] == -1) {
            st[p].next[c] = cur;
            p = st[p].link;
        }
        if (p == -1) {
            st[cur].link = 0;
        } else {
            int q = st[p].next[c];
            if (st[p].len + 1 == st[q].len) {
                st[cur].link = q;
            } else {
                int clone = st.size(); st.push_back(st[q]);
                st[clone].len = st[p].len + 1;
                while (p != -1 && st[p].next[c] == q) {
                    st[p].next[c] = clone;
                    p = st[p].link;
                }
                st[q].link = st[cur].link = clone;
            }
        }
        last = cur;
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string X, Y;
    if (!(cin >> X)) return 0;
    cin >> Y;
    ll S, R;
    cin >> S >> R;
    int n = X.size();
    SuffixAutomaton samY(Y.size()), samR(Y.size());
    for (char c: Y) samY.extend(c);
    string revY = Y;
    reverse(revY.begin(), revY.end());
    for (char c: revY) samR.extend(c);
    vector<int> L1(n), L2(n);
    
    for (int i = 0; i < n; ++i) {
        int state = 0, length = 0;
        for (int j = i; j < n; ++j) {
            int c = X[j] - 'a';
            if (samY.st[state].next[c] != -1) {
                state = samY.st[state].next[c];
                ++length;
            } else break;
        }
        L1[i] = length;
    }
    for (int i = 0; i < n; ++i) {
        int state = 0, length = 0;
        for (int j = i; j < n; ++j) {
            int c = X[j] - 'a';
            if (samR.st[state].next[c] != -1) {
                state = samR.st[state].next[c];
                ++length;
            } else break;
        }
        L2[i] = length;
    }
    
    int i = 0;
    ll k = 0;
    ll forced_rev = 0, tie = 0;
    while (i < n) {
        int l1 = L1[i], l2 = L2[i];
        int maxl = max(l1, l2);
        if (maxl <= 0) {
            cout << "Impossible";
            return 0;
        }
        if (l1 > l2) {
        } else if (l2 > l1) {
            forced_rev++;
        } else {
            tie++;
        }
        i += maxl;
        k++;
    }
    ll revCount;
    if (R > S) {
        revCount = forced_rev;
    } else if (R < S) {
        revCount = forced_rev + tie;
    } else {
        revCount = forced_rev; 
    }
    ll result = (k - revCount) * S + revCount * R;
    cout << result;
    return 0;
}
