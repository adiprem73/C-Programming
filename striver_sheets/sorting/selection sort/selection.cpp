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

vector<int> selectionSort(vector<int> nums){
    int n=nums.size();
    for(int i=0;i<n-1;i++){
        int minIndex=i;
        for(int j=i+1;j<n;j++){
            if(nums[j]<nums[minIndex]){
                minIndex=j;
            }
        }
        swap(nums[minIndex],nums[i]);
    }
    return nums;
}

int main() {
    FAST_IO;
    vint v={1,4,2,9,6,0,4};
    vint sv=selectionSort(v);
    vprint(sv);
    return 0;
}
//by ad73prem