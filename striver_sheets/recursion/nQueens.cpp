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

bool isSafe(int row, int col, vector<string> &board, int n){
    int duprow=row;
    int dupcol=col;

    // so checking is only must in three directions: NW, W and SW

    // 1. checking diagonlly upwards: NW
    while(duprow>=0 && dupcol>=0){
        if(board[duprow][dupcol]=='Q'){
            return false;
        }
        duprow--;
        dupcol--;
    }

    // 2. checking left side: W
    dupcol=col;
    duprow=row;
    while(dupcol>=0){
        if (board[duprow][dupcol] == 'Q')
        {
            return false;
        }
        dupcol--;
    }

    // 3. checking right side: SW
    dupcol = col;
    duprow = row;
    while(duprow<n && dupcol>=0){
        if (board[duprow][dupcol] == 'Q')
        {
            return false;
        }
        dupcol--;
        duprow++;
    }

    return true;
}

void solve(int col, vector<string> &board, vector<vector<string>> &ans, int n)
{
    //base case
    if(col==n){
        ans.push_back(board);
        return;
    }

    // trying out every row
    for(int row=0;row<n;row++){
        if(isSafe(row, col, board, n)){ // this function will simply check if tis safe to place the queen there or not
            board[row][col]='Q';
            solve(col+1, board, ans, n);
            board[row][col]= '.';    // backtracking...         
        }
    }
}

vector<vector<string>> solveNQueens(int n)
{
    vector<vector<string>> ans;
    vector<string> board(n, string(n, '.'));
    solve(0, board, ans, n);
    return ans;
}

int main()
{
    FAST_IO;
    
    return 0;
}
//by ad73prem