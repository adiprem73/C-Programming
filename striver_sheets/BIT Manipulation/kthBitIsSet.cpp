#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define push(a) push_back(a)
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
    string s="";
    while(n>0){
        int x=n%2;
        n/=2;
        s+=to_string(x);
    }
    reverse(s.begin(),s.end());
    return s;
}

bool checkKthBit(int n, int k) {
    string s=toBinary(n);
    cout<<"lenght : "<<s.length()<<endl;
    
    if(s.length()<k+1){
        return false;
    }
    reverse(s.begin(),s.end());
    char ch=s[k];
    if(ch=='0'){
        return false;
    }
    return true;
}

int main() {
    FAST_IO;
    int x=975;
    int k=10;
    cout<<toBinary(x)<<endl;
    cout<<checkKthBit(x,k);
    return 0;
}
//by ad73prem