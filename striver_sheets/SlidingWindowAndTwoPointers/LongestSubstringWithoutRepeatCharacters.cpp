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

int lengthOfLongestSubstring(string s) {
    int l=0,r=0;
    int maxLen=0;
    int len=0;
    map<char,int> mp;
    while(r<s.length()){
        
        if(mp.find(s[r])!=mp.end()){
            l=max(l,mp[s[r]]+1);
        }

        mp[s[r]]=r;

        len=r-l+1;
        maxLen=max(len,maxLen);

        // cout<<"r: "<<r<<" l: "<<l<<" len: "<<len<<" maxlen: "<<maxLen<<endl;
        r++;
    }
    return maxLen;
}

int main() {
    FAST_IO;
    string s;
    cin>>s;
    cout<<lengthOfLongestSubstring(s);
    return 0;
}
//by ad73prem