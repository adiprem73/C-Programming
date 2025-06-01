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


int wordCount(string s){
    int count=0;
    for(int i=0;i<s.length();i++){
        if(s[i]==' '){
            count++;
        }
    }
    // cout<<count+1;
    return count+1;
}


int mostWordsFound(vector<string>& sentences) {
    int ans=0;
    for(int i=0;i<sentences.size();i++){
        ans=max(ans,wordCount(sentences[i]));
        // cout<<wordCount(sentences[i]);
        // cout<<"ans : "<<ans<<endl;
    }
    return ans;
}

int main() {
    FAST_IO;
    vector<string> sen={"alice and bob love leetcode", "i think so too", "this is great thanks very much"};
    cout<<mostWordsFound(sen);
    return 0;
}
//by ad73prem