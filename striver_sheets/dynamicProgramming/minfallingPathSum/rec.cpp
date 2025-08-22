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

int func(int i, int j, vector<vector<int>>& matrix){
    //here the starting point and the end point are both variable in the grid. so we need to choose where do we start. or we can do one thing, we can write the recursive function of starting from one of the staring point and then retae a for loop and take minimum of all the iteratins

    if(i==0) return matrix[i][j]; //base case

    int up= (i>0)? func(i-1, j, matrix) : 1e9;
    int upleft= (j>0)? func(i-1, j-1, matrix) : 1e9;
    int upright= (i>0 && j+1< matrix.size())? func(i-1, j+1, matrix) : 1e9;

    return min(up, min(upleft, upright))+ matrix[i][j];

}

int minFallingPathSum(vector<vector<int>>& matrix) {
    int n=matrix.size() ;
    int mini=INT_MAX;
    //we need to call the function form every elelmnt of the last row
    for(int j=0;j<n;j++){
        mini=min(mini, func(n-1, j, matrix));
    }
    return mini;     
}

int main() {
    FAST_IO;
    vector<vector<int>> matrix= {{2,1,3},{6,5,4},{7,8,9}};
    cout<<minFallingPathSum(matrix);
    return 0;
}
//by ad73prem