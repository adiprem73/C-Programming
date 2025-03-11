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

bool check1100(string s){
    if (s.length()<4){
        return false;
    }
    else{
        for(int i=0;i<s.length()-3;i++){
            if(s[i]=='1'&&s[i+1]=='1'&&s[i+2]=='0'&&s[i+3]=='0'){
                return true;
            }

        }
    }
}

int main() {
    FAST_IO;
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        int q;
        cin>>q;
        vector<char> st;
        for(int i=0;i<s.length();i++){
            
        }
        for(int i=0;i<q;i++){
            int n1,n2;
            cin>>n1>>n2;

        }

    }
    return 0;
}
//by ad73prem