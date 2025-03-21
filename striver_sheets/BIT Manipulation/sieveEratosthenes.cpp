#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define push(a) push_back(a)
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

int countPrimes(int n){
    vector<int> prime(n+1,1);
    // for(int i=2;i<=n;i++){
    //     prime[i]=1;
    // }

    for(int i=2;i*i<=n;i++){
        if(prime[i]==1){
            for(int j=i*2;j<=n;j+=i){
                prime[j]=0;
            }
        }
    }

    int count=0;
    for(int i=2;i<n;i++){
        if(prime[i]==1){
            count++;
        }
    }
    return count;
}

int main() {
    FAST_IO;
    cout<<countPrimes(10);
    return 0;
}
//by ad73prem