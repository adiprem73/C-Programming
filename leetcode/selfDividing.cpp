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

vector<int> selfDividingNumbers(int left, int right) {
    vector<int> ans;
    for(int i=left; i<=right;i++){
        int n=i;
        bool flag=true;
        while( n>0 ){
            int d=n%10;
            if(d==0){
                flag= false;
                break;
            }
            else if(i%d!=0){
                flag=false;
                break;
            }
            n/=10;
        }
        if(flag){
            ans.push_back(i);
        }
    }
    return ans;
}

int main() {
    FAST_IO;
    vint ans= selfDividingNumbers(1,22);
    vprint(ans);
    return 0;
}
//by ad73prem