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

bool checkZero(int n){
    while(n>0){
        int d=n%10;
        if(d==0){
            return true;
        }
        n=n/10;
    }
    return false;
}

// vector<int> getNoZeroIntegers(int n)
// {
//     vint ans;
//     for (int i = 1; i <= n / 2; i++)
//     {
//         // cout<<"hello";
//         // cout<<endl<<i<<endl;
//         int x = n - i;
//         string s = to_string(i);
//         string t = to_string(x);
//         if(s.find('0')==string ::npos && t.find('0')==string:: npos){
//             // cout<<"hello";
//             ans.push_back(stoi(s));
//             ans.push_back(stoi(t));
//             break;
//         }
//     }
//     return ans;
// }

vector<int> getNoZeroIntegers(int n)
{
    vint ans;
    for (int i = 1; i < n ; i++)
    {
        int x=n-i;
        if(checkZero(x)==false && checkZero(i)==false){
            // cout<<"hello";
            ans.push_back(i);
            ans.push_back(x);
            break;
        }
    }
    return ans;
}

int main()
{
    FAST_IO;
    vint nums={1,4,3,2};
    vprint(getNoZeroIntegers(11));
    cout<<checkZero(9);
    return 0;
}
//by ad73prem