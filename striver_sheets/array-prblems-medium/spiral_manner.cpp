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

vector<int> spiralOrder(vector<vector<int>> &matrix)
{
    int left=0,top=0;
    int right=matrix[0].size()-1;
    int bottom=matrix.size()-1;
    vint ans;
    while(top<=bottom && left<=right){
        for(int i=left;i<=right;i++){
            ans.push(matrix[top][i]);
        }
        top++;

        for(int i=top;i<=bottom;i++){
            ans.push(matrix[i][right]);
        }
        right--;

        if(top<=bottom){
            for(int i=right;i>=left;i--){
                ans.push(matrix[bottom][i]);
            }
            bottom--;
        }

        if(left<=right){
            for(int i=bottom;i>=top;i--){
                ans.push_back(matrix[i][left]);
            }
            left++;
        }
    }
    return ans;
}

int main()
{
    FAST_IO;
    vmat matrix={{1,2,3,4},{5,6,7,8},{9,10,11,12}};
    vint ans=spiralOrder(matrix);
    vprint(ans);
    return 0;
}
// by ad73prem