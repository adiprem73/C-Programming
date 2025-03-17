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

int main() {
    FAST_IO;
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vint nums;
        int temp=n ;
        while(temp--){
            int x;
            cin>>x;
            nums.push_back(x);
        }
        vint copy=nums;

        if (k==1){
            int maxElelemnt=0;
            int maxIndex=0;
            // cout<<nums[0]<<endl;
            for(int i=0;i<n;i++){
                if(maxElelemnt<nums[i]){
                    maxElelemnt=nums[i];
                    maxIndex=i;
                }
            }
            // cout<<"max element : "<<maxElelemnt<<endl;
            if(maxIndex==0||maxIndex==n-1){
                sort(nums.begin(),nums.end());
                reverse(nums.begin(),nums.end());
                cout<<nums[0]+nums[1]<<endl;
            }
            else{
                cout<<maxElelemnt+max(nums[0],nums[n-1]);
            }
        }
        else{
            sort(nums.begin(),nums.end());
            int sum=0;
            sum=0;
            for(int i=0;i<=k;i++){
                sum+=nums[nums.size()-i-1];
            }
            // cout<<"hii"<<endl;
            cout<<sum<<endl;
        }

        
    }
    return 0;
}
//by ad73prem