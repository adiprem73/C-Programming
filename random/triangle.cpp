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

int triangleNumber(vector<int>& nums) {
    int n= nums.size();
    int cnt=0;
    // what we will do is sort the array. them we will start by fixing biggest side k fromthe back side of the array. then we will take i and then j. i and j will be two pointers pointing at index i=0 and j=k-1;... then we willl simply check if nums[i]+nums[j]>nums[k]... if yes then we can simply say that cnt+=(j-1)... since anynumber ahead of i will obiviously be bigger thant the element at i. hence the conditionw ill hold for that also and  simply got so many contributuons. in this case we will subtract j to move it back by one place in order to look for a smaller sum

    // if that condition wasnt true then we could have simply increaseed i one place ahead and simply increasesthe sum and then tried again while(i<j)
    sort(nums.begin(),nums.end());
    for(int k=n-1;k>=2;k--){
        // cout<<"k : "<<k<<endl;
        int i=0;
        int j=k-1;
        while(i<j){
            if((nums[k]<nums[i]+nums[j])&& (nums[k]!=0)&& (nums[i]!=0)&& (nums[j]!=0)){
                cnt+=(j-i);
                j--;
            }else {
                i++;
            }
        }
    }

    return cnt;
}

int main() {
    FAST_IO;
    vint nums = {48, 66, 61, 46, 94, 75};
    cout<<triangleNumber(nums);
    return 0;
}
//by ad73prem