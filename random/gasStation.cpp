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

// gas[i]= gas at station i     1  2  3  4  5
// cost [i]= cost of going from i to i+1 station   3  4  5  1  2

/*

int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
{
    int n = gas.size();

    vector<int> copy=gas;
    gas.insert(gas.end(), copy.begin(), copy.end());
    vector<int> copy2= cost;
    cost.insert(cost.end(), copy2.begin(), copy2.end());
    // int n= gas.size();
    // cout << "ello" << endl;
    for(int s=0;s<n;s++){
        // cout<<"s : "<<s<<endl;
        int curGas=gas[s];
        int curStation=s;
        while (curGas>0){
            if(curGas>=cost[curStation]){
                // cout<<"curStation : "<<curStation<<endl;
                curGas-=cost[curStation];
                curStation++;
                curGas+=gas[curStation];
            }else{
                break;
            }
            if(curStation%n==s){
                return s;
            }
        }
    }return -1;
}

*/

//intuition: if the sum of all the gasstation gas which gives the total gas is less than the total cost then its just not possible and we return -1
// or else we can simply od O(n) traversal and find the correct station by maintaining a bucket. if some bucket becomes negative start with the next station and then set the bucket to zero

int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
{
    int n=gas.size();
    if(n==0) return -1;
    long long total_tank=0;
    long long curr_tank=0;
    int start=0;

    for(int i=0;i<n;i++){
        long long diff= (long long)gas[i]- (long long ) cost[i];
        total_tank+=diff;
        curr_tank+=diff;

        if(curr_tank<0){
            start=i+1;
            curr_tank=0;
        }
    }

    return (total_tank>=0)? start%n:-1;

}

int main()
{
    FAST_IO;
    vint gas={2,3,4};
    vint cost={3,4,3};
    cout<<canCompleteCircuit(gas, cost);
    return 0;
}
//by ad73prem