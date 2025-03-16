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

int beautySum(string s){
    int ans=0;
    for(int i=0;i<s.length();i++){
        int* freq=new int [26];
        for(int j=i;j<s.length();j++){
            char ch=s[j];
            freq[ch-'a']++;
            int mx=INT_MIN;
            int mn=INT_MAX;
            for(int k=0;k<26;k++){
                if(freq[k]>0){
                    mn=min(mn,freq[k]);
                    mx=max(mx,freq[k]);
                }
            }
            ans+=mx-mn;
        }

    
}
return ans;
}

int main() {
    FAST_IO;
    
    return 0;
}
//by ad73prem