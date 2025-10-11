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

vector<int> successfulPairs2(vector<int> &spells, vector<int> &potions, long long success)
{
    int n=spells.size();
    int m= potions.size();
    vector<int> pairs(n);
    for(int i=0;i<n;i++){
        int cnt=0;
        for(int j=0;j<m;j++){
            if(spells[i]*potions[j]>=success){
                cnt++;
            }
        }
        pairs[i]=cnt;
    }
    return pairs;
}

vector<int> successfulPairs(vector<int> &spells, vector<int> &potions, long long success)
{
    int n = spells.size();
    int m = potions.size();
    vector<int> pairs(n);
    sort(potions.begin(), potions.end());
    for(int i=0;i<n;i++){
        long long val= spells[i];
        long long target= (success + val -1)/ val;
        // cout<<"tagert : "<<target<<endl; //7
        // now we will search for this element using binary search
        int s=0;
        int e=m;
        while(s<e){
            // cout<<"s : "<<s<<" e : "<<e<<endl;
            int mid= s+(e-s)/2;
            if(potions[mid]<target){
                s=mid+1;
            }
            else{
                e=mid;
            }
        }
        // cout<<"found at : "<<s<<endl;
        pairs[i]= m-s;
    }
    return pairs;
}

int main()
{
    FAST_IO;
    vint spells= {15,8,19};
    vint potions= {38,36,23};
    vint ans= successfulPairs(spells, potions, 328);
    vprint(ans);
    return 0;
}
//by ad73prem