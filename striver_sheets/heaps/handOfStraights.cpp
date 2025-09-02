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

bool isNStraightHand(vector<int> &hand, int groupSize)
{
    int n = hand.size();
    if (n % groupSize != 0)
        return false;

    map<int, int> mp;
    for (auto it : hand)
    {
        mp[it]++;
    }
    priority_queue<pair<int, int>> pq;
    for (auto it : mp)
    {
        pq.push({it.first, it.second}); //(number, freq)
    }

    vector<int> cycle;
    vector<vector<int>> ans;
    vector<pair<int, int>> temp;
    while (!pq.empty())
    {
        for (int i = 0; i < groupSize; i++)
        {
            auto it = pq.top();
            pq.pop();

            cycle.push_back(it.first);
            it.second--;

            if (it.second > 0)
            {
                temp.push_back(it);
            }
        }
        reverse(cycle.begin(), cycle.end());
        for(int i=0;i<cycle.size()-1;i++){
            if(cycle[i]!=cycle[i+1]-1){
                return false;
            }
        }
        ans.push_back(cycle);
        cycle={};
        for (auto it : temp)
        {
            pq.push(it);
        }
        temp.clear();

        // cout << "pq : " << endl;
        // auto temp = pq; // make a copy (so we don’t destroy original)
        // while (!temp.empty())
        // {
        //     cout << temp.top().first << " " << temp.top().second << endl;
        //     temp.pop();
        // }
    }
    return true;
    // for (auto it : ans)
    // {
    //     vprint(it);
    // }
}

int main()
{
    FAST_IO;
    vint nums = {1, 2, 3, 6, 2, 3, 4, 7, 8};
    cout<<isNStraightHand(nums, 3);
    return 0;
}
// by ad73prem