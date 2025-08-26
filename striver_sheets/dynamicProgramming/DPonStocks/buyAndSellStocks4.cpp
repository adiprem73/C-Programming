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

int maxProfit(int k, vector<int>& prices)
{
    int n = prices.size();
    vector<vector<int>>after(2, vector<int>(k+1, 0));
    vector<vector<int>>curr(2, vector<int>(k+1, 0));
   

    for (int ind = n-1; ind >= 0; ind--) //running the loop form n will make prices[n] og out of bounds
    {
        for (int buy = 0; buy <= 1; buy++)
        {
            for (int cap = 1; cap <= k; cap++) //cap msu tbe gretaer than 0
            {
                if (buy)
                {
                    curr[buy][cap] = max(-prices[ind] +after[0][cap], after[1][cap]);
                }

                // if its the time to sell then we will take the max of sell and not sell
                else
                {
                    curr[buy][cap] = max(prices[ind] + after[1][cap-1], after[0][cap]);
                }
            }
        }
        after = curr;
    }
    return after[1][k];
}

int func(int ind, int tranNo, vector<int> & prices, int n, int k){
    if(ind ==n || tranNo== 2*k)return 0;

    if(tranNo%2==0){//buy
         return max(-prices[ind]+func(ind+1, tranNo+11, prices, n, k) , func(ind+1, tranNo, prices, k, n));
    }

    return max(prices[ind] + func(ind+1, tranNo+1, prices, n, k) , func(ind+1, tranNo, prices, n, k));
}

int main() {
    FAST_IO;
    
    return 0;
}
//by ad73prem