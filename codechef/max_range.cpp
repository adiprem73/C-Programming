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

int findrange(vint nums){
    int mx=-1*INF;
    int mn=INF;
    f(i,0,nums.size()){
        mx=max(mx,nums[i]);
        mn=min(mn,nums[i]);
    }
    int ans=mx-mn;
    return ans;
}

int main() {
    FAST_IO;
    int t;
    cin>>t;
    while(t--){
        vint nums;
        int n;
        cin>>n;
        while(n--){
            int temp;
            cin>>temp;
            nums.push(temp);
        }
        sort(nums.begin(),nums.end());
        vint nums1=nums;
        vint nums2=nums;
        vint nums3=nums;
        vint nums4=nums;
        vint nums5=nums;

        //from both the ends
        nums1.erase(nums1.begin());
        nums1.erase(nums1.end()-1);
        
        //from the begining
        nums2.erase(nums2.begin());
        nums2.erase(nums2.begin());

        //from the ending
        nums3.erase(nums3.end()-1);
        nums3.erase(nums3.end()-1);

        //one from the begining
        nums4.erase(nums4.begin());

        //one from the ending
        nums5.erase(nums5.end()-1);

        int n1=findrange(nums1);
        int n2=findrange(nums2);
        int n3=findrange(nums3);
        int n4=findrange(nums4);
        int n5=findrange(nums5);

        int ans=min(n1,n2);
        ans=min(ans,n3);
        ans=min(ans,n4);
        ans=min(ans,n5);
        cout<<ans<<endl;
        // cout<<n1<<endl;
        // cout<<n2<<endl;
        // cout<<n3<<endl;
        // cout<<n4<<endl;
        // cout<<n5<<endl;

        // int max2=-1*INF;

        // int min2=INF;
        // f(i,0,nums.size()){
        //     if(nums[i]>max2){
        //         max2=nums[i];
        //     }
        //     if(nums[i]<min2){
        //         min2=nums[i];
        //     }
        // }
        // int max1=-1*INF;
        // int min1=INF;
        // f(i,0,nums.size()){
        //     if(nums[i]>max1&&nums[i]!=max2){
        //         max1=nums[i];
        //     }
        //     if(nums[i]<min1&&nums[i]!=min2){
        //         min1=nums[i];
        //     }
        // }
        // cout<<max2<<" "<<min2;
        // cout<<endl;
        // cout<<max1<<" "<<min1;
        // cout<<endl;

        // int a=max2-min2;
        // int b=max2-min1;
        // int c=max1-min2;
        // int d=max1-min1;
        // int ans=min(a,b);
        // ans=min(ans,c);
        // ans=min(ans,d);
        // cout<<"minimum range : "<<ans<<endl;
    }
    return 0;
}
//by ad73prem