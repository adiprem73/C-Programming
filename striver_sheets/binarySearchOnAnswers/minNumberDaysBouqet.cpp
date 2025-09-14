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

int minDays(vector<int> &bloomDay, int m, int k)
{
    if(m*k>bloomDay.size()){
        return -1;
    }
    int mini=INT_MAX;
    int maxi= INT_MIN;
    for(int i=0;i<bloomDay.size();i++){
        mini= min(mini, bloomDay[i]);
        maxi= max(maxi, bloomDay[i]);
    }

    for(int i=mini;i<=maxi; i++){
        int cnt=0; //count the consecutive bloomed flowers
        int b=0; //no. of bouqets being made
        //when bloomday[i]>= i then we can say that the flower is bloomed

        // cout<<"currenlty i : "<<i<<endl;
        for(int j=0;j<bloomDay.size();j++){
            // cout << "j : " << j << endl;
            if(i>=bloomDay[j]){
                cnt++;
            }else{
                int x=cnt/k;
                b+=x;
                cnt=0; //rest the counter since consecutivity has been broken
            }
        }
        if(cnt){
            b+=(cnt/k);
        }
        if(b>=m){
            return i;
        }
    }

}

int main()
{
    FAST_IO;
    vint bloomday={1,10,3,10,2};
    cout<<minDays(bloomday, 3, 1);
    return 0;
}
//by ad73prem