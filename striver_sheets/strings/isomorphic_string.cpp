#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define push(a) push_back(a)
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

bool isIsomorphic(string s, string t) {
    map<char,int> mp1,mp2;
    for(int i=0;i<s.size();i++){
        mp1[s[i]]=i;
    }
    for(int i=0;i<t.size();i++){
        mp2[t[i]]=i;
    }
    mprint(mp1);
    mprint(mp2);
    bool flag=true;
    for(int i=0;i<s.length();i++){
        char ch1=s[i];
        char ch2=t[i];
        if(mp1[ch1]!=mp2[ch2]){
            flag=false;
            break;
        }
    }
    return flag;
}

int main() {
    FAST_IO;
    string s="paper";
    string t="title";
    cout<<isIsomorphic(s,t);
    return 0;
}
//by ad73prem