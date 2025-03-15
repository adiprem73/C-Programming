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

int main() {
    FAST_IO;
    int t;
    cin>>t;
    while(t--){
        int x;
        cin>>x;
        int ans;
        bool flag;
        for(int i = 3*x/4;i<x;i++){
            int xy=x^i;
            // cout<<"x : "<<x<<" y : "<<i<<" xor : "<<xy<<endl;
            flag=false;
            if(((x+i)>xy)&&((x+xy)>i)&&((i+xy)>x)){
                ans=i;
                flag=true;
                break;
            }
        }
        if(flag==true){
            cout<<ans<<endl;
        }
        else{
            cout<<-1<<endl;
        }
    }
    return 0;
}
//by ad73prem