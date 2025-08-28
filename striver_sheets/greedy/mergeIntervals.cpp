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

vector<vector<int>> merge(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end());
    for(int i=0;i<intervals.size()-1;i++){
        if(intervals[i][1]>=intervals[i+1][0]){
            intervals[i][1]= max(intervals[i][1], intervals[i+1][1]);
            intervals.erase(intervals.begin()+i+1);
            i--;
        }
    } 
    return intervals;
}

vector<vector<int>> mergeOptimal(vector<vector<int>> & intervals){
    int n=intervals.size();
    vector<vector<int>> mergedIntervals;
    if(n==0){
        return mergedIntervals;
    }
    vector<int> tempInterval;
    sort(intervals.begin(), intervals.end());

    tempInterval = intervals[0];

    for(auto it: intervals){
        if(it[0]<=tempInterval[1]){
            tempInterval[1]= max(it[1], tempInterval[1]);
        }
        else{
            mergedIntervals.push_back(tempInterval);
            tempInterval=it;
        }
    }
    mergedIntervals.push_back(tempInterval);
    return mergedIntervals;
}

int main() {
    FAST_IO;
    vmat nums={{1,4},{0,4}};
    vmat ans=merge(nums);
    for(auto it: ans){
        vprint(it);
    }
    return 0;
}
//by ad73prem