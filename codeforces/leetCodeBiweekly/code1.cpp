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

string toBinary(long long n) {
    if (n == 0) return "0";
    bool neg = n < 0;
    unsigned long long x = neg ? (~(unsigned long long)n) + 1ULL : (unsigned long long)n;
    string s;
    while (x) {
        s.push_back(char('0' + (x & 1ULL)));
        x >>= 1;
    }
    if (neg) s.push_back('-');
    reverse(s.begin(), s.end());
    return s;
}

int minimumFlips(int n) {
    string s= toBinary(n);
    string t=s;
    int len= s.length();
    int cnt=0;
    reverse(s.begin(), s.end());
    for(int i=0;i<len;i++){
        if(s[i]!=t[i]){
            cnt++;
        }
    }
    return cnt;

}

int main() {
    FAST_IO;
    cout<<minimumFlips(10);
    return 0;
}
//by ad73prem