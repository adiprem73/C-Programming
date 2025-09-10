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

/*
for validation of array b freqb[i]%b[i]==0... frq of nay element in array b must be divisible by that element as well.

cos suppose there are 2,2,2,2 in the array b. now we know that we can only have one element appearing 2 times since b[i]=2. but freq[b[i]]
==4  hence we will group them in to two group of two 2s each... if nay number breaks this order we can simply print -1

2,2,1,3,1,1,3,3
convert the array into vector of vectors vec[i]---> list of indexes where element x occurs
vec[1]= {2, 4, 5}
vec[2]= {0,1}
vec[3]= {3,6,7}

then check vec[i].size()% i==0

and then formulate the answer
*/

int main() {
    FAST_IO;
    int t;
    cin >> t;
    while(t--){
        int n;
        cin>>n;
        vint nums;
        int maxi=INT_MIN; //the largest number in the array
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            maxi=max(maxi, x);
            nums.push_back(x);
        }
        vector<vector<int>>freq(maxi + 1); // store zero-based indexings, size is maxi+1
        for (int i = 0; i < n; i++)
        {
            freq[nums[i]].push_back(i);
        }
        // for(auto it: freq){
        //     vprint(it);
        // }

        int temp = 1;
        vint ans(n, 0);
        bool ok = true;
        for (int i = 1; i < freq.size(); i++) { // start from 1 to avoid division by zero
            if (freq[i].size() == 0) continue;
            if (freq[i].size() % i != 0) {
                cout << -1;
                ok = false;
                break;
            } else {
                int cnt = 0;
                for (int j = 0; j < freq[i].size(); j++) {
                    ans[freq[i][j]] = temp;
                    cnt++;
                    if (cnt == i) {
                        cnt = 0;
                        temp++;
                    }
                }
            }
        }
        if (ok) vprint(ans);
    }
    return 0;
}
//by ad73prem