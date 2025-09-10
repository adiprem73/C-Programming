#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define FAST_IO                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

// IF WE WANT a + b as even, there are only two cases: after iperations  a and b both even or both odd

// the larger the value of k the larger will be the value of a.k
//  so we need to tak eas big as k as possible

/*
// Case 1: a even... will remain even after mutlipliation by k   b even hence b/k must be even only
 ----->so b must have 2 here. so lets keep the 2 there and take the rest as k. hence we take k=b/2

// Case 2: a odd : k must also be odd so thatt when we take a.k it rmeains odd   b odd : we will take k=b which will make b/k as 1 and hence we will have a.k maximum as a.b

------> k=b

// Case 3: a even : we cannot make this odd by multiplying anythign to it since mutliplying anything wills tillleave the reaminder 2 factor....    b odd : we cannot make this even by dividing by anything since its just not possible

------> hence we cannot mathc the parities of these two numbers. hence the final ans can never be even. sopwe return -1

// Case 4: a odd : here if we take k=b then a.b will become even and b will become odd that will make the total answer to be odd whic we do not want.....

hence we will have to take k=b/2. this way if k is even then a.k becomes even b becoms 2 and we get out answer happiyl. but if k is odd then odd  into odd will remain odd and hence we will not get the answe that we want


b = k since that will make b/k also odd and maximise a.b+1

---->k=b;

// taking allt he divisors is giving tle
// so our appraoch will be to take cases:
// case 1: a is odd and b is also odd:
*/

int main()
{
    FAST_IO;
    int t;
    cin >> t;
    ll k;
    while (t--)
    {
        ll a, b;
        cin >> a >> b;

        if (a % 2 == 0 && b % 2 == 0)
        {
            k = b / 2;
        }
        else if (a % 2 != 0 && b % 2 == 1)
        {
            k = b;
        }
        else if (a % 2 == 1 && b % 2 == 0)
        {
            k = b / 2;
            if (k % 2 == 0)
            {
            }
            else
            {
                cout << -1 << endl;
                continue;
            }
        }
        else
        {
            cout << -1 << endl;
            continue;
        }

        cout << a * k + b / k << endl;
    }
    return 0;
}
