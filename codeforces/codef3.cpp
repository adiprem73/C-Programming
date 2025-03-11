#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define push(a) push_back(a)
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

int main() {
    FAST_IO;
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        mii mp;
        for(int i=0;i<k;i++){
            int n1,n2;
            cin>>n1>>n2;
            mp[n1]+=n2;
        }
        // mprint(mp);
        int count=0;
        int sum=0;
        for(auto it:mp){
            count++;
            sum+=it.second;
        }
        if(count<n){
            cout<<sum<<endl;
        }
        else{
            vint nums;
            for(auto it:mp){
            nums.push_back(it.second);
        }
        sort(nums.begin(),nums.end());
        reverse(nums.begin(),nums.end());
        int ans=0;
        for(int i=0;i<n;i++){
            ans+=nums[i];
        }
        cout<<ans<<endl;
        }
    }
    return 0;
}
//by ad73prem