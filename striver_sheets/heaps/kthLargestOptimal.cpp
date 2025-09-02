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

class KthLargest
{
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    int K;
    KthLargest(int k, vector<int> &nums)
    {
        K = k;
        for (auto it : nums)
        {
            if (pq.size() < k)
            {
                pq.push(it);
            }
            else
            {
                if (it > pq.top())
                {
                    pq.pop();
                    pq.push(it);
                }
            }
        }
    }

    int add(int val)
    {
        if (pq.size() >= K)
        {
            if (val > pq.top())
            {
                pq.pop();
                pq.push(val);
            }
            return pq.top();
        }
        else{
            pq.push(val);
        }
        return pq.top();
    }
};

int main()
{
    FAST_IO;
    vint nums={};
    KthLargest* kthlargest= new KthLargest(1, nums);
    cout<<kthlargest->add(-3);
    return 0;
}
// by ad73prem