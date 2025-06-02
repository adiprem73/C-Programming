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

const int INF = 1e9;
const ll MOD = 1e9+7;

bool wordPattern(string pattern, string s) {
    map<char, string> mp;
    map<string, char> rev_mp;
    vector<string> sen;
    string word = "";
    for (int i = 0; i < s.length(); i++) {
        char ch = s[i];
        if (ch == ' ') {
            sen.push_back(word);
            word = "";
        } else {
            word += ch;
        }
    }
    sen.push_back(word);

    if (pattern.size() != sen.size()) return false;

    for (int i = 0; i < pattern.size(); i++) {
        char p = pattern[i];
        string w = sen[i];
        if (mp.count(p)) {
            if (mp[p] != w) return false;
        } else {
            if (rev_mp.count(w)) return false;
            mp[p] = w;
            rev_mp[w] = p;
        }
    }
    return true;
}

int main() {
    FAST_IO;
    string s="dog cat cat dog";
    cout<<wordPattern("abba",s);
    return 0;
}
//by ad73prem