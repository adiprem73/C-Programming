#include <bits/stdc++.h>
using namespace std;

#define ll long long
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

string rev(string s)
{

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(')
        {
            s[i] = ')';
        }
        if (s[i] == ')')
        {
            s[i] = '(';
        }
    }
    reverse(s.begin(), s.end());
    return s;
}

int priority(char c)
{
    if (c == '^')
    {
        return 3;
    }
    else if (c == '*' || c == '/')
    {
        return 2;
    }
    if (c == '+' || c == '-')
    {
        return 1;
    }
    return -1;
}

string infixToPrefix(string s)
{
    s = rev(s);
    int i = 0;
    stack<char> st;
    string ans = "";

    while (i < s.length())
    {

        // operand
        if ((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9'))
        {
            ans += s[i];
        }

        // opening bracket
        else if (s[i] == '(')
        {
            st.push(s[i]);
        }

        // closing bracket
        else if (s[i] == ')')
        {
            while (!st.empty() || st.top() != '(')
            {
                ans = ans + st.top();
                st.pop();
            }
            st.pop();
        }

        else
        {
            if (s[i] == '^')
            {
                while (!st.empty() && priority(s[i]) < priority(st.top()))
                {
                    ans = ans + st.top();
                    st.pop();
                }
            }

            else
            {
                while (!st.empty() && priority(s[i]) < priority(st.top()))
                {
                    ans += st.top();
                    st.pop();
                }
                st.push(s[i]);
            }
            
        }
        i++;
        while (!st.empty())
        {
            ans += st.top();
            st.pop();
        }

        ans = rev(ans);
        return ans;
    }
}

int main()
{
    FAST_IO;
    string s = "((A-(B/C))*((A/K)-L))";
    string sin = infixToPrefix(s);
    cout << sin;
    return 0;
}
// by ad73prem