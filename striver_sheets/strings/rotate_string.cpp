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

bool rotateString(string s, string goal) {
    int k=s.size();
    for(int i=0;i<k;i++){
        string news=s.substr(1);
        news+=s[0];
        s=news;
        if(s==goal){
            return true;
        }
    }   
    return false; 
}

int main() {
    FAST_IO;
    string s="abcde";
    rotateString(s,s);
    return 0;
}
//by ad73prem