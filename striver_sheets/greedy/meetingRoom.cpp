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

bool comp(vector<int>& a, vector<int>& b){
    int x= a[1];
    int y= b[1];
    return x<y;
}

int maxMeetings(vector<int>& start, vector<int>& end){
    vector<vector<int>>dsa (start.size(), vector<int>(3));
    for(int i=0;i<start.size();i++){
        dsa[i][0]=start[i];
        dsa[i][1]=end[i];
        dsa[i][2]=i; //we also stroe the position in the og array so that we can backtrack it and print the meeting list as well
    }
    sort(dsa.begin(), dsa.end(), comp);
    for(auto it: dsa){
        vprint(it);
    }
    int freeTime=dsa[0][1];
    int cnt=1; //1st meeting always starts
    for(int i=1;i<start.size();i++){
        if(dsa[i][0]>freeTime){
            cnt++; //meet happens
            freeTime=dsa[i][1];
        }
    }
    return cnt;
}

int main() {
    FAST_IO;
    vint start={10, 12, 20};
    vint end={20, 25, 30};
    cout<<maxMeetings(start, end);
    return 0;
}
//by ad73prem