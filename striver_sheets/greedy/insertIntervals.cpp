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
    vector<vector<int>> res;
    int i=0;
    //left part
    int n=intervals.size();
    while(i<n && intervals[i][1]<newInterval[0]){
        res.push_back(intervals[i++]);
    }  
    
    //overlapping part
    while(i<n && intervals[i][0]<=newInterval[1]){
        newInterval[0]= min(newInterval[0], intervals[i][0]);
        newInterval[1]= max(newInterval[1], intervals[i][1]);
        i++;
    }  
    res.push_back(newInterval);
    //right part
    while(i<n){
        res.push_back(intervals[i++]);
    }
    return res;
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
    return 0;
}
//by ad73prem