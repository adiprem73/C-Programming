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

int findMaxConsecutiveOnes(vector<int>& nums) {
    int count=0;
    int maxCount=0;
    bool flag=false;
    for(int i=0;i<nums.size();i++){
        if(nums[i]==1){
            flag=true;
            count++;
        }
        else{
            flag = false;
            count=0;
        }


        if(count>maxCount){
            maxCount=count;
        }
    } 
    return maxCount;
}

int main() {
    FAST_IO;
    vint nums={1,1,0,1,1,0,1};
    cout<<findMaxConsecutiveOnes(nums);
    return 0;
}
//by ad73prem