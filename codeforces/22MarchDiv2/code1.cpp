#include<bits/stdc++.h>
using namespace std;

#define ll long long
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

int main() {
    FAST_IO;
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        string s;
        cin>>s;
        string r=s;
        reverse(r.begin(),r.end());

        if(n==1){
            cout<<"NO"<<endl;
            continue;
        }

        if(s<r){
            cout<<"YES"<<endl;
            continue;
        }

        if(k==0){
            cout<<"NO"<<endl;
            continue;
        }

        else{
            cout<<s<<endl;
            int start=0;
            int end=n-1;
            bool flag=false;
            while(k-- && start<end){
                if(s[start]>s[end]){
                    flag=true;
                    break;
                }

            }
            if(flag=false){
                cout<<"NO"<<endl;
            }
            else{
                cout<<"YES"<<endl;
            }
        }
        // cout<<s<<endl;
    }
    return 0;
}
//by ad73prem