#include <bits/stdc++.h>
using namespace std;

int maximumFinal(vector<int> arr)
{
    if (arr.empty())
        return 0; 

    sort(arr.begin(), arr.end());

    long long want = 1; 
    for (long long x : arr)
    {
        if (x >= want)
        {
            want++;
        }
        else
        {
        }
    }
    return (int)(want - 1);
}

#ifndef ONLINE_JUDGE
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n))
        return 0;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    cout << maximumFinal(arr) << "\n";
    return 0;
}
#endif