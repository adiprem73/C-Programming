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

class Solution
{
public:
    vector<int> findEvenNumbers(vector<int> &digits)
    {
        vector<int> ans;
        int n = digits.size();
        vector<int> freq(10,0);
        for(int i: digits){
            freq[i]++;
        }

        for (int a=1;a<=9;a++){
            if(freq[a]==0)continue;

            for(int b=0;b<=9;b++){
                if(freq[b]==0 && )
            }
        }
        {
            
        }
        return ans;
    }
};

int main() {
    FAST_IO;
    
    return 0;
}
//by ad73prem