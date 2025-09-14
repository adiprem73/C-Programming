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

int shipWithinDays(vector<int> &weights, int days)
{
    int maxi=INT_MIN;
    int sum=accumulate(weights.begin(), weights.end(), 0);
    for(int x: weights){
        maxi=max(maxi,x);
    }
    int s=maxi;
    int e=sum;
    while(s<e){
        int mid= s+ (e-s)/2;

        int ship=0;
        int d=0;
        for(int i=0;i<weights.size();i++){
            if(ship+weights[i]<=mid){
                ship=ship+weights[i];
            }
            else{
                d++;
                ship=weights[i];
            }
        }
        ship++;
        if(d>=days){
            s=mid+1;
        }
        else{
            e=mid;
        }
    }
    return s;

}

int main()
{
    FAST_IO;
    vint nums = {1, 2, 3, 1, 1};
    cout<<shipWithinDays(nums, 4);
    return 0;
}
//by ad73prem