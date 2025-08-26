#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    if (!(cin >> t))
        return 0;
    while (t--)
    {
        long long n, a, b;
        cin >> n >> a >> b;

        if ((n - b) % 2 == 0)
        {
            if (a <= b)
            {
                cout << "yes" << endl;
            }
            else if ((a - b) % 2 == 0)
            {
                cout << "yes" << endl;
            }
            else
            {
                cout << "no" << endl;
            }
        }
        else
        {
            cout << "no" << endl;
        }
    }
    return 0;
}
