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

int numberOfSubstrings(string s)
{
    int n=s.length();
    int cnt=0;

    vector<int> zro;

    for(int i=0;i<n;i++){
        if(s[i]=='0')zro.push_back(i); //this will store all the indexes of 0 in the string
    }

    if(zro.empty()) return n*(n+1)/2; //if there are no zeroes then every substring is dominant

    int zro_ind=0;

    for(int l=0;l<n;l++){
        while(zro_ind< zro.size() && zro[zro_ind]<l) zro_ind++;

        vector<int> valid_zro;

        for(int z= zro_ind; z<zro.size() && z<(zro_ind+201);z++){
            valid_zro.push_back(zro[z]);
        }
        valid_zro.push_back(n);

        int zro_cnt=0;
        int last=l;

        for(auto ind : valid_zro){
            int min_one = zro_cnt* zro_cnt;
            int min_ind = max(l + min_one +zro_cnt -1, last);

            if(min_ind < ind) cnt+= (ind - min_ind);

            last = ind;
            zro_cnt++;
        }
    }
    return cnt;
}

int main()
{
    FAST_IO;
    cout << numberOfSubstrings("101101");
    return 0;
}
// by ad73prem