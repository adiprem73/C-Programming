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

vector<int> getFloorAndCeil(int x, vector<int> &arr)
{
    sort(arr.begin(),arr.end());
    int s = 0;
    int e = arr.size() - 1;
    int mid = s + (e - s) / 2;
    int floor = -1;
    int ceil = -1;
    while (s <= e)
    {
        if(arr[mid]==x){
            floor =mid;
            break;
        }
        if (arr[mid] <= x)
        {
            floor = mid;
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
        mid = s + (e - s) / 2;
    }

    s = 0;
    e = arr.size() - 1;
    mid = s + (e - s) / 2;

    while (s <= e)
    {
        if(arr[mid]==x){
            ceil=mid;
            break;
        }
        if (arr[mid] > x)
        {
            ceil = mid;
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
        mid = s + (e - s) / 2;
    }

    if(floor!=-1){
        floor=arr[floor];
    }
    if(ceil!=-1){
        ceil=arr[ceil];
    }

    return {floor,ceil};
}

int main()
{
    FAST_IO;
    vint arr = {36, 82 ,88 ,56 ,21, 17 ,73, 86};
    int x = 17;
    vprint(getFloorAndCeil(x, arr));
    return 0;
}
// by ad73prem