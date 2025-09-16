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

// start from the highest number in th array. that way each can have atleast one ook. then keep on increasing this number and then check how many students are getting assigned a book. if it exceeds the number of students given then increase the number of pages.

int check(vector<int> nums, int pages){
    int student=nums[0];
    int cnt=1;
    for(int i=1;i<nums.size();i++){
        if(student+ nums[i]<=pages){
            student+=nums[i];
        }else{
            cnt++;
            student=nums[i];
        }
    }
    return cnt;
}

/*
int findPages(vector<int> & nums, int m){
    int n=nums.size();
    if(m>n)return -1;

    int sum=accumulate(nums.begin(), nums.end(), 0);

    int low= *max_element(nums.begin(), nums.end());
    int  high= sum;

    for(int i=low;i<=high;i++){
        if(check(nums, i)==m){
            return i;
        }
    }
    return -1;
}

*/

int findPages(vector<int> &nums, int m)
{
    int n = nums.size();
    if (m > n)
        return -1;

    int sum = accumulate(nums.begin(), nums.end(), 0);

    int low = *max_element(nums.begin(), nums.end());
    int high = sum;

    while(low<=high){
        int mid= low +(high-low)/2;
        int d= check(nums, mid);

        if(d<m){
            high=mid-1;
        }else{
            low=mid+1;
        }
    }
    return low;
}

int main() {
    FAST_IO;
    // vint nums={12,34,67,90};
    vint nums = {25,46,28,49,24};
    int m=2;
    cout<<findPages(nums, 4);
    return 0;
}
//by ad73prem