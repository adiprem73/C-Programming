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

int ninjaTraining(vector<vector<int>> & matrix){
    int n=matrix.size();

    vector<vector<int>> dp(n, vector<int>(4, -1));
    //for the base case
    dp[0][0]= max(matrix[0][1], matrix[0][2]);
    dp[0][1]= max(matrix[0][0], matrix[0][2]);
    dp[0][2]= max(matrix[0][0], matrix[0][1]);
    dp[0][3]= max(matrix[0][0], matrix[0][1], matrix[0][2]);

    for(int day=1;day<n;day++){
        for(int last=0;last<4;last++){
            dp[day][last]=0;
            int maxi=0;

            for(int task=0;task<3;task++){
                int point = matrix[day][task]+ dp[day-1][task];
                dp[day][last]= max(dp[day][last], point);
            }


            dp[day][last]=maxi;
        }
    }

    return dp[n-1][3];

}

int ninjaTrainingSO(vector<vector<int>> & matrix){
    int n=matrix.size();

    vector<int> prev(4,0);
    //for the base case
    prev[0]= max(matrix[0][1], matrix[0][2]);
    prev[1]= max(matrix[0][0], matrix[0][2]);
    prev[2]= max(matrix[0][0], matrix[0][1]);
    prev[3]= max(matrix[0][0], matrix[0][1], matrix[0][2]);

    for(int day=1;day<n;day++){
        vector<int> curr(4,0);
        for(int last=0;last<4;last++){
            curr[last]=0;
            int maxi=0;

            for(int task=0;task<3;task++){
                int point = matrix[day][task]+ prev[task];
                curr[last]= max(curr[last], point);
            }


            prev=curr;

        }
    }

    return prev[3];

}

int main() {
    FAST_IO;
    
    return 0;
}
//by ad73prem