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


void parentheses(vector<string>& str,int n, int open,int close,string s){
    // cout<<s<<endl;
    if(2*n==s.length()){
        
        str.push_back(s);
    }
    else{
        if(open<n){
            
            parentheses(str,n,open+1,close,s+'(');

        }
        if(close<open){
            
            parentheses(str,n,open,close+1,s+')');
        }
    }
}


vector<string> generateParenthesis(int n) {
    vector<string> str={};
    string s="";
    int open=0;
    int close=0;
    parentheses(str,n,open,close,s);
    return str;
}

int main() {
    FAST_IO;
    vector<string> res=generateParenthesis(3);
    for(int i=0;i<res.size();i++){
        cout<<res[i]<<" ";
    }
    return 0;
}
//by ad73prem