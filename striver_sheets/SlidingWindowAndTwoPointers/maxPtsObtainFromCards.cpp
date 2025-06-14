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

int maxScore(vector<int>& cardPoints, int k) {
    int l=0,r=0,sum=0,minSum=INT_MAX,totalSum=0;

    while(r<cardPoints.size()){

        //sliding window
        if(r-l+1>cardPoints.size()-k){
            sum-=cardPoints[l];
            l++;
        }

        // for(int i=l;i<=r;i++){
        //     cout<<cardPoints[i]<<" ";
        // }
        // cout<<endl;

        sum+=cardPoints[r];
        if(r-l+1==cardPoints.size()-k){
            minSum=min(minSum,sum);
            // cout<<"current sum : "<<sum<<endl;
            // cout<<"current min sum : "<<minSum<<endl;
        }

        r++;
    }

    for(int i=0;i<cardPoints.size();i++){
        totalSum+=cardPoints[i];
    }

    return totalSum-minSum;

}

int main() {
    FAST_IO;
    vint pts={9,7,7,9,7,7,9};
    cout<<maxScore(pts,7);
    return 0;
}
//by ad73prem