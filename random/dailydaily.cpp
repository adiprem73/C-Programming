#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define f(i, a, b) for(int i=a;i<b;i++)
#define all(x) x.begin(),x.end()
#define vprint(v) for (auto& elem : v) cout << elem << " "; cout << endl;
#define mprint(m) for (auto it:m) cout<<it.first<<" : "<<it.second<<endl; cout<<endl;
#define vint vector<int>
#define vstring vector<string>
#define vmat vector<vector<int>>
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define pii pair<int,int>
#define pll pair<ll,ll>
#define mii map<int,int>
#define mll map<ll,ll>

const int INF = 1e9;
const ll MOD = 1e9+7;

vector<vector<int>> rangeAddQueries2(int n, vector<vector<int>>& queries) {
    vector<vector<int>> vec(n, vector<int>(n,0));
    for(auto it: queries){
        int r1= it[0];
        int c1= it[1];
        int r2= it[2];
        int c2= it[3];

        for(int i=r1;i<=r2;i++){
            for(int j=c1;j<=c2;j++){
                vec[i][j]+=1;
            }
        }
    }

    // for(auto it: vec){
    //     vprint(it);
    // }
    return vec;
}

vector<vector<int>> rangeAddQueries(int n, vector<vector<int>> &queries)
{
    vector<vector<int>> diff(n+1, vector<int>(n+1, 0));
    for (auto it : queries)
    {
        int r1 = it[0];
        int c1 = it[1];
        int r2 = it[2];
        int c2 = it[3];
        diff[r1][c1]+=1;
        diff[r1][c2+1]-=1;
        diff[r2+1][c1]-=1;
        diff[r2+1][c2+1]+=1;

        // now we need to use prefix sums to spread the additions of 1 across the table

    }

    // row wise sum
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = 0; j < n; j++)
        {
            sum += diff[i][j];

            diff[i][j] = sum;
        }
    }

    // column wise sum
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = 0; j < n; j++)
        {
            sum += diff[j][i];

            diff[j][i] = sum;
        }
    }

    // for(auto it: diff){
    //     vprint(it);
    // }
    vector<vector<int>> vec(n, vector<int> (n,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            vec[i][j]= diff[i][j];
        }
    }
    // cout<<"Hello"<<endl;
    // for (auto it : vec)
    // {
    //     vprint(it);
    // }
    return vec;
}

int main() {
    FAST_IO;
    vector<vector<int>>queries={{1,1,2,2},{0,0,1,1}};
    rangeAddQueries(3, queries);
    return 0;
}
//by ad73prem