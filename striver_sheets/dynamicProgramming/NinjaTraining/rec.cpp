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

int func(int ind, int last, vector<vector<int>>& matrix){ //here last is the index 0,1 or 2 of the last task that was performed in the calling previous recusrion, the recursion that is calling this recursion
    // cout<<ind<<" "<<last<<endl;
    int maxi=0;


    //base case
    if(ind==0){
        for(int i=0;i<=2;i++){
            if(i!=last){
                maxi=max(maxi, matrix[0][i]);
            }
        }
        return maxi;
    }

    for(int i=0;i<3;i++){
        if(i!=last){
            int pts= matrix[ind][i]+ func(ind-1, i, matrix); //recurisve calls the funciton for the day before and with last set as to tell it the taskthat is beignodne here.

            maxi=max(maxi, pts);
        }
    }

    return maxi;
}

int ninjaTraining(vector<vector<int>>& matrix) {
    int n=matrix.size();
     return func(n-1, 3, matrix);
}

int main() {
    FAST_IO;
    vector<vector<int>> mat={{10, 40, 70},{20, 50, 80},{30, 60, 90}};
    cout<<ninjaTraining(mat);
    return 0;
}
//by ad73prem