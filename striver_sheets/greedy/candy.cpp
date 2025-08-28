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

int candy(vector<int>& ratings) {
    int sum=1;
    int i=1;
    int n=ratings.size();
    while(i<n){
        //flat surface
        if(ratings[i]==ratings[i-1]){
            sum+=1;
            i++;
            continue;
        }

        //upward slope
        int peak=1;
        while(i<n&& ratings[i]>ratings[i-1]){
            peak+=1;
            sum +=peak;
            i++;
        }

        //downward slope
        int down=0;
        while(i<n && ratings[i]<ratings[i-1]){
            down+=1;
            sum+=down;
            i++;
        }
        
        down++;
        if(down>peak){
            sum+=down-peak;
        }
    } 
    return sum;       
}

int main() {
    FAST_IO;
    
    return 0;
}
//by ad73prem