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

int maxDepth(string s) {
    int counter=0;
    int max_counter=0;
    for(int i=0;i<s.length();i++){
        char ch=s[i];
        if(ch=='(') {
            counter++;
            max_counter=max(max_counter,counter);
        }
        else if(ch==')') counter--;
    }
    return max_counter;
}


int main() {
    FAST_IO;
    string s="()(())((()()))";
    cout<<maxDepth(s);
    return 0;
}
//by ad73prem