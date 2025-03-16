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


int findFirstOccurence(vector<int> & arr, int target){
    int s=0;
    int e=arr.size()-1;
    int firstOccurrence=-1;
    while(s<=e){
        int mid=s+(e-s)/2;

        if(arr[mid]==target){
            firstOccurrence=mid;
            e=mid-1; //continue searching in the left half for the very first occurrence
        }

        if(arr[mid]<target){
            s=mid+1;
        }
        else if(arr[mid]>target){
            e=mid-1;
        }
    }
    return firstOccurrence;
}

int findLastOccurence(vector<int> & arr, int target){
    int s=0;
    int e=arr.size()-1;
    int lastOccurrence=-1;
    while(s<=e){
        int mid=s+(e-s)/2;

        if(arr[mid]==target){
            lastOccurrence=mid;
            s=mid+1; //continue searching in the right half for the very last occurrence
        }

        if(arr[mid]<target){
            s=mid+1;
        }
        else if(arr[mid]>target){
            e=mid-1;
        }
        // cout<<"s : "<<s<<" e : "<<e<<" mid : "<<mid<<endl;
    }
    // cout<<"last occurrence is : "<<lastOccurrence<<endl;
    return lastOccurrence;
}

int countFreq(vector<int>& arr, int target) {
    int f=findFirstOccurence(arr,target);
    int l=findLastOccurence(arr,target);
    // cout<<f<<" "<<l<<endl;
    if(f==-1&&l==-1){
        return 0;
    }
    return l-f+1;
}

int main() {
    FAST_IO;
    vint arr={1,1,2,2,2,2,3};
    int target=4;
    cout<<countFreq(arr,target);
    return 0;
}
//by ad73prem