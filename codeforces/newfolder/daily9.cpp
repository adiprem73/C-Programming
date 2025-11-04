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

int minCost(string colors, vector<int> &neededTime)
{
    int sum=neededTime[0];
    int maxi = neededTime[0];
    int n= colors.length();
    int ans=0;
    for(int i=1;i<n;i++){
        if(colors[i]==colors[i-1]){
            sum+=neededTime[i];
            maxi= max(maxi, neededTime[i]);
        }else{
            cout<<"hello"<<endl;
            ans+=(sum-maxi);
            sum=neededTime[i];
            maxi= neededTime[i];
        }
    }
    ans+= sum-maxi;
    return ans;
}

int main()
{
    FAST_IO;
    string colors="abc";
    vint neededTime= {1,2,3 };
    cout<<minCost(colors, neededTime);
    return 0;
}
//by ad73prem