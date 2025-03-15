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

vector<int> leaders(vector<int>& arr) {
    int n=arr.size();
    int maxElement=arr[n-1];
    vint lead;
    lead.push_back(arr[n-1]);
    for(int i=n-2;i>=0;i--){
        if(arr[i]>maxElement){
            lead.push_back(arr[i]);
        }

        if(arr[i]>maxElement){
            maxElement=arr[i];
        }
    }
    return lead;
}

int main() {
    FAST_IO;
    vint arr={16, 17, 4, 3, 5, 2};
    vprint(leaders(arr));
    return 0;
}
//by ad73prem