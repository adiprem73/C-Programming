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

string filter(string s){
    string ans;
    for(int i=0;i<s.length();i++){
        if((s[i]>='a'&&s[i]<='z')||(s[i]>='A'&&s[i]<='Z')||(s[i]>='0'&&s[i]<='9')){
            ans+=tolower(s[i]);
        }
    }
    return ans;
}

string reverse_string(string s,int start, int end){
    // cout<<"hello"<<s;
    if(start>=end){
        // cout<<s;
        // cout<<"break"<<endl;
        return s;
    }
    char c=s[start];
    s[start]=s[end];
    s[end]=c;
    return reverse_string(s,start+1,end-1);
}

bool isPalindrome(string s){
    // cout<<"s : "<<s<<endl;
    // cout<<"reverse s : "<<reverse_string(s,0,s.length()-1);
    s=filter(s);
    if(s==reverse_string(s,0,s.length()-1)){
        return true;
    }
    return false;
}

int main() {
    FAST_IO;
    string st="Aditya";
    // cout<<reverse_string(st,0,st.length()-1);
    
    cout<<filter("A man, a plan, a canal: Panama");
    cout<<isPalindrome(filter("A man, a plan, a canal: Panama"));
    return 0;
}
//by ad73prem