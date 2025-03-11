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


void func(vector<int> a, int start, int end){
    if(start>end){
        vprint(a)
        return;
    }
    int temp=a[start];
    a[start]=a[end];
    a[end]=temp;
    func(a, start+1, end-1);
}

int main() {
    FAST_IO;
    vector <int> x={1,2,3,4,5,6,7};
    func(x,0,x.size()-1);
    return 0;
}
//by ad73prem