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
    priority_queue<int> pq;
    int K;
    int curKth;

    KthLargest(int k, vector<int> &nums)
    {
        K = k;
        for (auto it : nums)
        {
            pq.push(it);
        }

        priority_queue<int> temp = pq;
        int cnt = 1;
        while (!temp.empty())
        {
            if (cnt == k)
            {
                curKth = temp.top();
                break;
            }
            cnt++;
            temp.pop();
        }
    }

    int add(int val)
    {
        if (val <= curKth)
        {
            pq.push(val);
        }
        else
        {
            pq.push(val);
            priority_queue<int> temp = pq;
            int cnt = 1;
            while (!temp.empty())
            {
                if (cnt == K)
                {
                    curKth = temp.top();
                    break;
                }
                cnt++;
                temp.pop();
            }
        }
        return curKth;
    }
};

int main()
{
    FAST_IO;
    vector<int> nums = {7,7,7,7,8,3};
    KthLargest* kthLargest = new KthLargest(4, nums);
    cout << kthLargest->add(2) << endl;  // return 4
    cout << kthLargest->add(10) << endl;  // return 5
    cout << kthLargest->add(9) << endl; // return 5
    cout << kthLargest->add(9) << endl;  // return 8
    return 0;
}
// by ad73prem