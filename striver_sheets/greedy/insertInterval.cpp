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

vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
    int n = intervals.size();
    // if(n==0){
    //     intervals.push_back(newInterval);
    //     return intervals;
    // }
    // for(int i=0;i<n;i++){
    //     if(intervals[i][0]<=newInterval[0] && intervals[i][1]>=newInterval[0]){
    //         intervals[i][1] = max(intervals[i][1], newInterval[1]);
    //     }
    //     else{
    //         intervals.push_back(newInterval);
    //         sort(intervals.begin(), intervals.end());
    //     }
    // }   

    intervals.push_back(newInterval);
    sort(intervals.begin(), intervals.end());
    //now we need to fix the issue of overlapping intervals
    for(int i=0;i<intervals.size()-1;i++){
        if(intervals[i][1]>=intervals[i+1][0]){
            intervals[i][1]= max(intervals[i][1], intervals[i+1][1]);
            intervals.erase(intervals.begin()+i+1);
            i--;
        }
    }  
    return intervals;
}

int main() {
    FAST_IO;
    vmat nums={{1,2},{3,5},{6,7},{8,10},{12,16}};
    vint in={4,8};
    vmat ans=insert(nums,in);
    for(auto it: ans){
        vprint(it);
    }
    return 0;
}
//by ad73prem