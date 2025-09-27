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

vector<int> convert(string s){
    vector<int> ans;
    int n=0;
    for(int i=0;i<s.length();i++){
        char ch=s[i];
        if(ch=='.'){
            ans.push_back(n);
            n=0;
        }else{
            n=n*10+(ch-'0');
        }
    }
    if(n)ans.push_back(n);
    return ans;
}

int compareVersion(string version1, string version2)
{
    vector<int> nums1;
    vector<int> nums2;
    nums1=convert(version1);
    nums2=convert(version2);
    // vprint(nums1);
    // vprint(nums2);
    
    int s=min(nums1.size(), nums2.size());
    // cout<<"s : "<<s<<endl;
    for(int i=0;i<s;i++){
        if(nums1[i]>nums2[i]){
            return 1;
        }else if(nums1[i]<nums2[i]){
            return -1;
        }
    }
    vector<int> x=(nums1.size()>nums2.size())?nums1:nums2;
    for(int i=s;i<x.size();i++){
        if(x[i]!=0){
            cout<<"hello"<<endl;
            return nums1.size() > nums2.size()?1:-1;
        }
    }
    return 0;
    
}

int main()
{
    FAST_IO;
    cout<<compareVersion("1.0", "1.0.0.0");
    return 0;
}
//by ad73prem