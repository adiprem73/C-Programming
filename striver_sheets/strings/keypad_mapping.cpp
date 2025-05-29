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

int minimumPushes(string word) {
    map<char,int> mp;
    int len=word.length();
    for(int i=0;i<len;i++){
        mp[word[i]]++;
    }
    int count=0;
    int ans=0;
    for(auto it:mp){
        count++;
        if(count<=8){
            ans=ans+(it.second);
        }
        else if(count>8&&count<=16){
            ans=ans+(it.second*2);
        }
        else if(count>16&&count<=24){
            ans=ans+(it.second*3);
        }
        else{
            ans=ans+(it.second*4);
        }
    }
    return ans;
}

int main() {
    FAST_IO;
    string word;
    cin>>word;
    cout<<minimumPushes(word);
    return 0;
}
//by ad73prem