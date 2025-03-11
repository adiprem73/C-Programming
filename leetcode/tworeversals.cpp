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

int reverseNum(int num){
    int rev=0;
    while(num>0){
        int d=num%10;
        cout<<d<<endl;
        rev=rev*10+d;
        num=num/10;
    }
    return rev;
}

bool isSameAfterReversals(int num){
    int rev1=reverseNum(num);
    int rev2=reverseNum(rev1);
    bool flag=rev2==num;
    return flag;
}

int main() {
    FAST_IO;
    cout<<reverseNum(1200);
    return 0;
}
//by ad73prem