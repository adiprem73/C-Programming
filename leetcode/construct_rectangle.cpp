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

vector<int> constructRectangle(int area) {
    vector<pair<int,int>> vp;
    for(int i=1;i<sqrt(area);i++){
        pii p;
        if(area%i==0){
            p.first=i;
            p.second=area/i;
            vp.push_back(p);
        }
        
    }
    pii ans;
    int diff=INT_MAX;
    vector<int> ans;
    for(int i=0;i<vp.size();i++){
        cout<<vp[i].first<<" "<<vp[i].second<<endl;
        int diff1=abs(vp[i].first-vp[i].second);
        if(diff1<diff){
            diff=diff1;
            ans={};
            ans.push_back()
        }
        
    }
    cout<<diff;

}

int main() {
    FAST_IO;
    cout<<constructRectangle(12);
    return 0;
}
//by ad73prem