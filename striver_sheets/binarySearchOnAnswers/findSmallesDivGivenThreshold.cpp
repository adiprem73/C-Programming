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

// the basic idea is to apply binary searc on serach spcae and everytime the number comes out to be >thrshold we can increase the divisor and if it comes < threshold we can try a smaller diviser

int answer(vector<int>& nums, int x, int limit){
    int sum=0;
    for(int y: nums){
        sum+=(y+x-1)/x; //ceil division

        if(sum>limit){
            return sum;
        }
    }
    return sum;
}


// mid decreses... ans increases

int smallestDivisor(vector<int> &nums, int threshold)
{
    int s=1; //always start with s=1
    int e=INT_MIN;
    for(int x: nums){
        e=max(e, x);
    }


    while(s<e){
        int mid=s +(e-s)/2;
        // cout<<"mid : "<<mid<<endl;

        int ans= answer(nums, mid, threshold);
        // cout<<"answer : "<<ans<<endl;
        if(ans<=threshold){ //yes this divisor does give less than or equal to the threshold. try even smaller since we need the smallest divisor
            e=mid;
        }else{ //the current sum is greater then threshold to reduce the sum we must increase the divisor. 
            s=mid+1;
        }

    }
    return s;
}

int main()
{
    FAST_IO;
    vint nums = {1, 2, 5, 9};
    cout<<smallestDivisor(nums, 6);

    return 0;
}
//by ad73prem