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

void find(vector<int> a){
    mii mp;
    for(int i=0;i<a.size();i++){
        mp[a[i]]++;
    }
    int mx=0;
    int hfreq,lfreq;
    int mn=INT16_MAX;
    for(auto it:mp){
        if(mx<it.second){
            mx=it.second;
            hfreq=it.first;
        }
        if(mn>it.second){
            mn=it.second;
            lfreq=it.first;
        }
    }
    cout<<"highest frequency : "<<hfreq<<endl;
    cout<<"lowest frequebncy : "<<lfreq<<endl;
    // cout<<"max : "<<mx<<endl;
    // mprint(mp);
}

int main() {
    FAST_IO;
    vint v={1,2,3,3,3,4,5,5,5,5};
    find(v);
    return 0;
}
//by ad73prem