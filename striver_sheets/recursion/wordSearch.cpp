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

bool func(int ind, int x, int y, vector<vector<char>> &board, string word)
{


    if (ind == word.size() - 1)
    {
        // cout << "executed" << endl;
        return true;
    }

    // to prevent same cell being counted twise we can mark the visited as '#'
    char temp = board[x][y];
    board[x][y]='#';


    int n = board.size();    // no. of rows
    int m = board[0].size(); // no. of columns
    // cout<<"no. of rows : "<<n<<endl;
    // cout<<"no. of cols : "<<m<<endl;
    vector<int> dx = {0, 1, 0, -1};
    vector<int> dy = {1, 0, -1, 0};
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 0 && nx < n && ny >= 0 && ny < m)
        {
            if (word[ind+1] == board[nx][ny])
            {
                if (func(ind + 1, nx, ny, board, word))
                {
                    board[x][y]= temp; // backtracking before returning
                    return true;
                }
            }
        }
    }
    board[x][y]= temp; //backtracking... 
    return false;
}

bool exist(vector<vector<char>> &board, string word)
{
    bool flag;

    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[0].size(); j++)
        {

            if (word[0] == board[i][j])
            {
                // cout << "x : " << i << endl
                //      << "y : " << j << endl;
                // cout<<"character is : "<<word[ind]<<endl;
                flag = func(0, i, j, board, word);
                if (flag == true)
                {
                    return flag;
                }
            }
        }
    }

    return flag;
}

int main()
{
    FAST_IO;
    vector<vector<char>> board = {
        {'A', 'B', 'C', 'E'},
        {'S', 'F', 'C', 'S'},
        {'A', 'D', 'E', 'E'}};
    string word = "ABCB";
    cout << exist(board, word);
    return 0;
}
// by ad73prem