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


bool lemonadeChange(vector<int>& bills) {
    map<int, int> mp;
    bool flag=true;
    for(int i=0;i<bills.size();i++){
        if(bills[i]==5){
            mp[5]++;
        }
        else if(bills[i]==10){
            mp[10]++;
            if(mp[5]){
                mp[5]--;
            }else{
                flag=false;
                break;
            }
        }
        else{
            mp[20]++;
            if(mp[10]>=1&& mp[5]>=1){
                mp[10]--;
                mp[5]--;
            }
            else if(mp[5]>=3){
                mp[5]-=3;
            }
            else{
                flag=false;
                break;
            }
        }
    }  
    return flag;
}


int main() {
    FAST_IO;
    vint nums={5,5,10,10,20};
    cout<<lemonadeChange(nums);
    return 0;
}
//by ad73prem