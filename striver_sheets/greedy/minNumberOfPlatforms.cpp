#include<bits/stdc++.h>
using namespace std;

#define ll long long
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

int findPlatform(vector<int>& Arrival, vector<int>& Departure){
    int n=Arrival.size();
    vector<int>ans;
    ans.push_back(Departure[0]);
    for(int i=1;i<n;i++){
        bool flag=false;
        for(int j=0;j<ans.size();j++){
            if(ans[j]<Arrival[i]){
                // cout<<"inside loop"<<endl;
                // vprint(ans);
                flag=true;
                ans[j]=Departure[i];
                break;
            }
        }
        if(flag==false){
            ans.push_back(Departure[i]);
        }
        // cout<<"aarray : "<<endl;
        // vprint(ans);
    }
    return ans.size();
}

int main() {
    FAST_IO;
    vint arr={900, 1100, 1235};
    vint dep={1000, 1200, 1240};
    cout<<findPlatform(arr, dep);
    return 0;
}
//by ad73prem