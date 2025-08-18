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

#include <vector>
using namespace std;


int solution(vector<int> readings, int k) {
    long long kl = k;
    int count = 0;

    for (int r : readings) {
        long long x = r;
        // skip non-positive numbers: 0 or negatives can't be k^n for k>2 (n>=0)
        if (x <= 0) continue;

        // repeatedly divide while divisible by k
        while (x % kl == 0) {
            x /= kl;
        }

        if (x == 1) ++count; // reduced to 1 => r was a power of k
    }

    return count;
}


int main() {
    FAST_IO;
    vector<int> reading={2,4,7,8,16,32,120};
        vector<int> reading2={10201,101,1030301,101,101};

    cout<<solution(reading, 2);
    return 0;
}
//by ad73prem