#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define f(i, a, b) for(int i=a;i<b;i++)
#define all(x) x.begin(),x.end()
#define vprint(v) for (auto& elem : v) cout << elem << " "; cout << endl;
#define mprint(m) for (auto it:m) cout<<it.first<<" : "<<it.second<<endl; cout<<endl;
#define vint vector<int>
#define vstring vector<string>
#define vmat vector<vector<int>>
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define pii pair<int,int>
#define pll pair<ll,ll>
#define mii map<int,int>
#define mll map<ll,ll>

const int INF = 1e9;
const ll MOD = 1e9+7;


string solution(string a, string b) {
    int na = (int)a.size();
    int nb = (int)b.size();
    int L = max(na, nb);

    vector<string> parts;
    parts.reserve(L);

    for (int i = 0; i < L; ++i) {
        int da = (i < na) ? (a[na - 1 - i] - '0') : 0;
        int db = (i < nb) ? (b[nb - 1 - i] - '0') : 0;
        parts.push_back(to_string(da + db));
    }

    string result;
    result.reserve(L * 2); // rough reserve, sums can be up to 2 digits each
    for (int i = (int)parts.size() - 1; i >= 0; --i) result += parts[i];

    return result;
}

// Optional quick test
int main() {
    cout << solution("99", "99") << '\n'; // expected "1818"
    cout << solution("11", "9")  << '\n'; // expected "110"
    return 0;
}

//by ad73prem