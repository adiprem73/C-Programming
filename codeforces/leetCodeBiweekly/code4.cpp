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

int binSerach(vector<int>& nums, int start, int end, int val){
    vector<int> temp;
    for(int i=start;i<=end;i++){
        temp.push_back(nums[i]);
    }

    // vprint(temp);
    int s=0;
    int e= temp.size()-1;
    sort(temp.begin(), temp.end());
    while(s<=e){
        int mid= s+(e-s)/2;
        // cout<<"mid : "<<mid<<endl;
        // cout<<temp[mid]<<endl;

        if(temp[mid]==val){
            return mid;
        }
        else if(temp[mid]<val){
            s=mid+1;
        }
        else{
            e=mid-1;
        }
    }
    return -1; // not found
}

int countInRange(vector<int> & nums, int start, int end, int val){
    vector<int> temp;
    for(int i=start; i<=end;i++){
        temp.push_back(nums[i]);
    }
    // vprint(temp);

    sort(temp.begin(), temp.end());

    int low = lower_bound(temp.begin(), temp.end(), val)- temp.begin();

    int high = upper_bound(temp.begin(), temp.end(), val) - temp.begin();

    return high-low;
}



int specialTriplets2(vector<int>& nums) {
    int cnt=0;
    for(int j=1;j<nums.size()-1;j++){

        int val = nums[j]*2;

        int leftCount = countInRange(nums, 0, j-1, val);
        int rightCount= countInRange(nums, j+1, nums.size()-1, val);

        cnt+=(leftCount*rightCount);
    }
    return cnt;
}

int specialTriplets(vector<long long> &nums)
{
    long long cnt = 0;
    long long n= nums.size();
    unordered_map<long long , long long> left, right;
    for(long long i=0;i<nums.size();i++){
        right[nums[i]]++;
    }

    for(long long j=0;j<nums.size();j++){
        right[nums[j]]--;

        if (j > 0 && j < n - 1)
        {
            long long val = 2 * nums[j]; // 2*nums[j] may overflow long long, so long long

            long long leftCount = left[val];
            long long rightCount = right[val];

            cnt += leftCount * rightCount;
        }

        // current element ko left side me add kar do
        left[nums[j]]++;
    }
    return cnt;
}

int main() {
    FAST_IO;
    vint nums = {84, 2, 93, 1, 2, 2, 26};

    // cout<<countInRange(nums, 0, 4, 2);
    cout<<specialTriplets(nums);
    return 0;
}
//by ad73prem