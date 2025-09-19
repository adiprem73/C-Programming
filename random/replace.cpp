#include<bits/stdc++.h>
#include<numeric>
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

vector<int> replaceNonCoprimes(vector<int> &nums)
{
    stack <ll> st;// to stroe the array after merging
    st.push(1LL*nums[0]);
    for(int i=1;i<nums.size();i++){
        ll cur= (ll)nums[i];

        while(!st.empty()){
            ll top= st.top();
            ll g= __gcd(top, cur);
            if(g==1) break; //coprime--> stop merging
            st.pop();

            cur= (top/g) * cur;
        }
        st.push(cur);
    }
    vector<int> ans;
    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }
    reverse(ans.begin(), ans.end());
    // vprint(ans);
    return ans;
}

int main()
{
    FAST_IO;
    vint nums = {287, 41, 49, 287, 899, 23, 23, 20677, 5, 825};
    vprint(replaceNonCoprimes(nums));
    return 0;
}
//by ad73prem