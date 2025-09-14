

/*
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

int main() {
    FAST_IO;
    int t;
    cin >> t;
    while(t--){
        int n;
        cin>>n;
        vint nums;
        vint nodd,neven;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            nums.push_back(x);
            if(x%2==0){
                neven.push_back(x);
            }else{
                nodd.push_back(x);
            }
        }
        if(nodd.size()==0){
            cout<<0<<endl;
            continue;
        }
        else{
            ll sumEven= accumulate(neven.begin(), neven.end(), 0LL); //sum of all evens
            ll sumOdd=0;
            sort(nodd.rbegin(), nodd.rend());
            for(int i=0;i<nodd.size();i+=2){
                sumOdd+=nodd[i];
            }
            cout<<sumEven+sumOdd<<endl;
        }
    }
    return 0;
}
//by ad73prem

*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    if (!(cin >> t))
        return 0;
    while (t--)
    {
        int n;
        cin >> n;
        vector<ll> evens, odds;
        for (int i = 0; i < n; ++i)
        {
            ll x;
            cin >> x;
            if ((x & 1) == 0)
                evens.push_back(x);
            else
                odds.push_back(x);
        }

        if (odds.empty())
        {
            cout << 0 << '\n';
            continue;
        }

        ll sumEven = 0;
        for (ll v : evens)
            sumEven += v;

        sort(odds.begin(), odds.end(), greater<ll>());
        int take = (int)((odds.size() + 1) / 2); // ceil(m/2)
        ll sumOdd = 0;
        for (int i = 0; i < take; ++i)
            sumOdd += odds[i];

        cout << (sumEven + sumOdd) << '\n';
    }
    return 0;
}
