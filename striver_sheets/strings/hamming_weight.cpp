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

string toBinary(int n){
    string s;
    while(n>0){
        int x=n%2;
        s=s+to_string(x);
        n/=2;
    }
    reverse(s.begin(),s.end());
    return s;
}

int hammingWeight(int n) {
    string b=toBinary(n);
    int count=0;
    for(int i=0;i<b.length();i++){
        if(b[i]=='1'){
            count++;
        }
    }
    return count;
}

int main() {
    FAST_IO;
    
    return 0;
}
//by ad73prem