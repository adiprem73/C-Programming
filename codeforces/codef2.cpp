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
        int n;
        cin>>n;
        vint nums;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            nums.push_back(x);
        }
        bool flag=true;
        for(int i=0;i<n-1;i++){
            int a=abs(nums[i]-nums[i+1]);
            if(a==5||a==7){

            }
            else{
                flag=false;
                break;
            }
        }
        if(flag==true){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}
//by ad73prem