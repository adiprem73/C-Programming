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

int func(int i, int j, vector<vector<int>>& triangle){
    // base case :  sinc this time we are going from top to botom in recruson we must have base case for hte last row
    int n=triangle.size();

    if(i== n-1){
        return triangle[i][j];
    }

    // int left= triangle[i+1][j];
    // int right = triangle[i+1][j+1];

    int down= func(i+1, j, triangle);
    int diag= func(i+1, j+1, triangle);

    return min(down, diag)+ triangle[i][j];

}

int minimumTotal(vector<vector<int>>& triangle) {
    return func(0,0, triangle);

}

int main() {
    FAST_IO;
    vmat mat={{-10}};
    cout<<minimumTotal(mat);
    return 0;
}
//by ad73prem