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

void heapify(vector<int> & nums, int n, int i){
    int left= 2*i+1;
    int right= 2*i+2;
    int largest=i;

    if(left<n && nums[largest]<nums[left]){
        largest=left;
    }
    if(right<n && nums[largest]<nums[right]){
        largest=right;
    }
    if(largest!=i){
        swap(nums[largest], nums[i]);
        heapify(nums, n , largest);

    }
}

vector<int> minToMaxHeap(vector<int> nums) {
    //we just need to heapify the non leaf nodes with the maxHea version of heapify
    int n=nums.size();
    for(int i=(n-2)/2;i>=0;i--){
        heapify(nums, n, i);
    }
    return nums;
}

int main() {
    FAST_IO;
    vint nums={10, 20, 30, 21, 23};
    vint ans=minToMaxHeap(nums);
    vprint(ans);
    return 0;
}
//by ad73prem