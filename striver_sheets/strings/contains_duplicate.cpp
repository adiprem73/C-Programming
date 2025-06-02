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

bool containsDuplicate(vector<int>& nums) {
    set<int> s;
    for(int i=0;i<nums.size();i++){
        if(s.find(nums[i])!= s.end()){
            return true; // Duplicate found
        }
        s.insert(nums[i]); // Insert the number into the set

    }
}

bool containsDuplicate(vector<int> nums){
    sort(nums.begin(), nums.end());
    for(int i=0;i<nums.size()-1;i++){
        if(nums[i]==nums[i+1]){
            return true;
        }
        return false;
    }
}

bool containsDuplicate2(vector<int>& nums) {
        map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        for(auto i:mp){
            if(i.second>1){
                return true;
            }
        }return false;
}

int main() {
    FAST_IO;
    
    return 0;
}
//by ad73prem