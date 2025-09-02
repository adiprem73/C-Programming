#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define f(i, a, b) for (int i = a; i < b; i++)
#define all(x) x.begin(), x.end()
#define vprint(v)            \
    for (auto &elem : v)     \
        cout << elem << " "; \
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

vector<int> maxSumCombinations(vector<int> &nums1, vector<int> &nums2, int k)
{
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < nums1.size(); i++)
    {
        for (int j = 0; j < nums2.size(); j++)
        {
            if (pq.size() < k)
            {
                pq.push(nums1[i] + nums2[j]);
            }
            else
            {
                if (pq.top()<nums1[i]+nums2[j]){
                    pq.pop();
                    pq.push(nums1[i]+nums2[j]);
                }
            }
        }
    }
    vector<int> ans;
    while(!pq.empty()){
        ans.push_back(pq.top());
        pq.pop();
    }
    return ans;
}

int main()
{
    FAST_IO;
    vint nums1={3,4,5};
    vint nums2={2,6,3};
    vint anss=maxSumCombinations(nums1, nums2, 2);
    vprint(anss);
    return 0;
}
// by ad73prem