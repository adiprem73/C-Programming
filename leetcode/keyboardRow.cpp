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

vector<string> findWords(vector<string>& words){
    string r1="qwertyuiop";
    string r2="asdfghjkl";
    string r3="zxcvbnm";
    vector<string> ans;
    string x;
    

    for(int i=0;i<words.size();i++){
        if(i==0){
            for(int j=0;j<3;j++){
                
            }
        }
        for(int j=0;j<words[i].length();j++){
            if((r1.find(words[i][j])!= string::npos))
        }
    }
}

int main() {
    FAST_IO;
    
    return 0;
}
//by ad73prem