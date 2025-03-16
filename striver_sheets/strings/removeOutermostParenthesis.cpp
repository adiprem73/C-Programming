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

string removeOuterParentheses(string s) {
    int counter=0;
    string substring;
    vector<string> res;
    for(int i=0;i<s.length();i++){
        char ch=s[i];
        substring+=ch;
        if(ch=='('){
            counter++;
        }
        else if(ch==')'){
            counter--;
        }
        if(counter==0){
            res.push_back(substring);
            substring="";
        }
    }
    string finres;
    for(int i=0;i<res.size();i++){
        string temp=res[i].substr(1,res[i].length()-2);
        finres+=temp;
    }
    return finres;    
}

int main() {
    FAST_IO;
    string s="(()())(())(()(()))";
    cout<<removeOuterParentheses(s);

    return 0;
}
//by ad73prem