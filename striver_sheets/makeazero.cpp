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

void setZeroes(vector<vector<int>>& matrix) {
    vector<pii> v;
    f(i,0,matrix.size()){
        f(j,0,matrix[i].size()){
            if(matrix[i][j]==0){
                v.push(make_pair(i,j));
            }
        }
    }
    set <int> a;//rows to be made zero
    set <int> b;//columns to be made zero

    for(auto it: v){
        a.insert(it.first);
        b.insert(it.second);
    }
    // for(auto it:a){
    //     cout<<it<<endl;
    // }
    // cout<<endl;
    // for(auto it:b){
    //     cout<<it<<endl;
    // }
    for(auto it:a){
        for(int j=0;j<matrix[it].size();j++){
            matrix[it][j]=0;
        }
    }
    for(auto it:b){
        for(int j=0;j<matrix.size();j++){
            matrix[j][it]=0;
        }
    }
    f(i,0,matrix.size()){
        vprint(matrix[i]);
    }
    // vprint(a);
    // vprint(b);
    // f(i,0,a.size()){
    //     f(j,0,matrix[a[i]].size()){
    //         matrix[a[i]][j]=0;
    //     }
    // }
    //  f(i,0,a.size()){
    //     f(j,0,matrix[b[i]].size()){
    //         matrix[j][b[i]]=0;
    //     }
    // }
    // f(i,0,matrix.size()){
    //     vprint(matrix[i]);
    // }
}

int main() {
    FAST_IO;
    // vmat matrix={{1,1,1},{1,0,1},{1,1,1}};
    vmat matrix={{1,1,1},{1,0,1},{1,1,1}};
    setZeroes(matrix);
    return 0;
}
//by ad73prem