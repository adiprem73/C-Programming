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

bool canConstruct(string ransomNote, string magazine) {
    map<char,int> ranmap;
    map<char,int> magmap;
    for(int i=0;i<ransomNote.length();i++){
        ranmap[ransomNote[i]]++;
    }
    for(int i=0;i<magazine.length();i++){
        magmap[magazine[i]]++;
    }
    bool ans=true;
    for (auto it:ranmap){
        if(magmap.find(it.first)==magmap.end()){
            ans=false;
            break;
        }
        if(magmap[it.first]<it.second){
            ans=false;
            break;
        }
    }
    return ans;
}

int main() {
    FAST_IO;
    string ransomNote="aa";
    string magazine="aab";
    cout<<canConstruct(ransomNote,magazine);
    return 0;
}
//by ad73prem