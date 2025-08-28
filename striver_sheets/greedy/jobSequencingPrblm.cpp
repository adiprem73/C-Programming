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

        return a[2]>b[2];
    
}

vector<int> JobScheduling(vector<vector<int>>& Jobs) { 
    sort(Jobs.begin(), Jobs.end(), comp);
    for(auto it: Jobs){
        vprint(it);
    }
    int n=Jobs.size();

    int i=0;
    int time=0;
    int profit=0;
    while(i<n){
        if(Jobs[i][1]>time){
            time+=1;
            profit+=Jobs[i][2];
            i++;
        }
        else{
            i++;
        }
    }
    cout<<profit<<endl<<time;

} 

int main() {
    FAST_IO;
    vmat jobs={{1,4,20},{2,1,10},{3,1,40},{4,1,30}};
    // vmat jobs={{1,2,100},{2,1,19},{3,2,27},{4,1,25},{5,1,15}};

    JobScheduling(jobs);
    return 0;
}
//by ad73prem