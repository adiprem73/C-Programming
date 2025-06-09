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

void multiply(double& ans, double x, long long n){
    if(n%2==0){
        ans=ans*ans;
        multiply(ans, x, n/2);
    }

    if(n==1){
        ans*=x;
        return;
    }

    ans*=x;
    multiply(ans,x,n-1);

}

double myPow(double x, int n) {
    if(n==0 || x==1){
        return 1;
    }
    double ans=1;
    if(n<0){
        long long temp=n;
        multiply(ans,x,temp*-1);
        return 1/ans;
    }
    long long temp=n;
    multiply(ans,x,temp);
    return ans;
}

int main() {
    FAST_IO;
    cout<<myPow(2,-2147483648);
    return 0;
}
//by ad73prem