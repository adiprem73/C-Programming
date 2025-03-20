#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define push(a) push_back(a)
#define f(i, a, b) for (int i = a; i < b; i++)
#define all(x) x.begin(), x.end()
#define vprint(v)            \
    for (auto &elem : v)     \
        cout << elem << " "; \
    cout << endl;
#define vmatprint(vv)            \
    for (auto &row : vv)         \
    {                            \
        for (auto &elem : row)   \
            cout << elem << " "; \
        cout << endl;            \
    }                            \
    cout << endl;
#define mprint(m)                                       \
    for (auto it : m)                                   \
        cout << it.first << " : " << it.second << endl; \
    cout << endl;
#define vint vector<int>
#define vstring vector<string>
#define vmat vector<vector<int>>
#define FAST_IO                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define pii pair<int, int>
#define pll pair<ll, ll>
#define mii map<int, int>
#define mll map<ll, ll>

const int INF = 1e9;
const ll MOD = 1e9 + 7;

void generateCombination(int index, int target, vint &curr, vint &nums, vmat &ans)
{
    if(target==0){
        ans.push_back(curr);
        return;
    }

    for(int i=index; i<nums.size();i++){
        if(i>index &&  nums[i]==nums[i-1]){
            continue;
        }
        if(nums[i]>target){
            break;
        }

        curr.push_back(nums[i]);
        generateCombination(i+1,target-nums[i],curr,nums,ans);
        curr.pop_back();
    }
}

vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
{
    vint curr;
    vmat ans;
    sort(candidates.begin(),candidates.end());
    generateCombination(0, target, curr, candidates, ans);
    return ans;
}

int main()
{
    FAST_IO;
    vint candidates = {2,5,2,1,2};
    int target = 5;
    vmat ans = combinationSum2(candidates, target);
    vmatprint(ans);
    return 0;
}
// by ad73prem