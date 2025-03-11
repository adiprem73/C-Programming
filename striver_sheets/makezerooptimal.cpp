#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define push(a) push_back(a)
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
//this fucntion will make that particular row which is passed to be all zero.
void rows(vector<vector<int>>& matrix,int r){
    f(i,0,matrix[0].size()){
        matrix[r][i]=0;
    }
}

//this function will make that particular col which is passed to be all zero.
void cols(vector<vector<int>>& matrix,int c){
    f(i,0,matrix.size()){
        matrix[i][c]=0;
    }
}
void setZeroes(vector<vector<int>>& matrix) {
    int col0=1;
    f(i,0,matrix.size()){
        if(matrix[i][0]==0){
                col0=0;
            }
        f(j,0,matrix[i].size()){
            
            if(matrix[i][j]==0){
                matrix[0][j]=0;
                matrix[i][0]=0;
            }
        }
    
    }
    cout<<col0<<endl;
    if(col0==0){
        cols(matrix,0);
    }
    // f(i,0,matrix.size()){
    //     vprint(matrix[i]);
    // }
    f(i,0,matrix.size()){
        if(matrix[i][0]==0){
            rows(matrix,i);
        }
    }
    f(i,0,matrix[0].size()){
        if(matrix[0][i]==0){
            cols(matrix,i);
        }
    }
    f(i,0,matrix.size()){
        vprint(matrix[i]);
    }
}

int main() {
    FAST_IO;
    // vmat matrix={{1,1,1},{1,0,1},{1,1,1}};
    vmat matrix={{0,1,2,0},{3,4,5,2},{1,3,1,5}};
    setZeroes(matrix);
    // cols(matrix,1);

    
    // f(i,0,matrix.size()){
    //     vprint(matrix[i]);
    // }
    return 0;
}
//by ad73prem