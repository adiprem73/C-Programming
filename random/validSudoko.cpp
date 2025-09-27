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

bool chechHash(vector<int> nums){
    for(int i=0;i<9;i++){
        if(nums[i]>1){
            return false;
        }
    }return true;
}


bool isValidSudoku(vector<vector<char>> &board)
{
    // row and column check
    vector<int> row(9);
    for(int i=0;i<9;i++){
        vector<int> row(9);
        for(int j=0;j<9;j++){
            row[board[i][j]-'0']++;
        }
        if(chechHash(row)==false){
            return false;
        }
        vector<int> col(9);
        for(int j=0;j<9;j++){
            col[board[j][i] - '0']++;
        }
        if(chechHash(col)== false){
            return false;
        }
    }

    for(int k=0;k<=6;k=k+3){
        vector<int> hash(9);
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                hash[board[i + k][j + k] - '0']++;
            }
        }
        if(chechHash(hash)==false){
            return false;

        }
    }
    return true;
}

int main()
{
    FAST_IO;
    
    return 0;
}
//by ad73prem