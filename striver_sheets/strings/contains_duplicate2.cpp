#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define f(i, a, b) for(int i=a;i<b;i++)
#define all(x) x.begin(),x.end()
#define vprint(v) for (auto& elem : v) cout << elem << " "; cout << endl;
#define vmatprint(vv) for (auto& row : vv) { for (auto& elem : row) cout << elem << " "; cout << endl; } cout << endl;
#define mprint(m) for (auto it : m) cout << it.first << " : " << it.second << endl; cout << endl;
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

bool containsNearbyDuplicate(vector<int>& nums, int k) {
    map<int, int> mp; // Map to store the last index of each element
    for (int i = 0; i < nums.size(); i++) {
        if (mp.find(nums[i]) != mp.end() && i - mp[nums[i]] <= k) {
            return true; // Found a duplicate within the range k
        }
        mp[nums[i]] = i; // Update the last index of the current element
    }
    return false; // No duplicates found within the range k
        
}


int candy(vector<int>& ratings) {
    int n = ratings.size();
    vector<int> candies(n, 1);

    // Left to right
    for (int i = 1; i < n; ++i) {
        if (ratings[i] > ratings[i - 1])
            candies[i] = candies[i - 1] + 1;
    }

    // Right to left
    for (int i = n - 2; i >= 0; --i) {
        if (ratings[i] > ratings[i + 1])
            candies[i] = max(candies[i], candies[i + 1] + 1);
    }

    return accumulate(candies.begin(), candies.end(), 0);
}

int main() {
    FAST_IO;
    vint nums={1,0,1,1};
    int k=1;
    cout << (containsNearbyDuplicate(nums, k) ? "true" : "false") << endl;
    return 0;
}
//by ad73prem