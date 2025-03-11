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

void bubbleSort(int *arr, int n){
    if(n==1){
        return;
    }

    for(int i=0;i<=n-2;i++){
        if( arr[i]>arr[i+1]){
            swap(arr[i],arr[i+1]);
        }
    }
    bubbleSort(arr,n-1);
}

int main() {
    FAST_IO;
    int arr[]={4,6,1,1,2,5,3,32,8,9,10};
    bubbleSort(arr,11);
    for(int i=0;i<11;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
//by ad73prem