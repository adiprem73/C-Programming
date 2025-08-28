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

bool comp(vector<int>&a, vector<int>&b){
    return a[1]<b[1];
}

int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end(), comp);
    int freeTime= intervals[0][1];
    int n=intervals.size();
    int cnt=1;
    for(auto it: intervals){
        vprint(it);
    }
    for(int i=1;i<n;i++){
        if(intervals[i][0]>=freeTime){
            cnt++;
            freeTime=intervals[i][1];
        }
    }  
    return n-cnt;     
}

int main() {
    FAST_IO;
    vmat inter={{1,2},{2,3}};
    cout<<eraseOverlapIntervals(inter);
    return 0;
}
//by ad73prem