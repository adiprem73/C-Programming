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

void heapify(int arr[], int n, int i){
    int largest=i; //the number to be heapified
    int left= 2*i;
    int right= 2*1+1;

    if(left<=n && arr[largest]<arr[left]){
        largest=left;
    }
    if(right<=n && arr[largest]<arr[right]){
        largest=right;
    }

    if(largest != i){
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n){
    int size=n;
    while(size>1){
        swap(arr[size], arr[1]);
        size--;

        heapify(arr, size, 1);
    }
}

int main() {
    FAST_IO;
    int arr[6]={-1, 54, 53, 55, 52, 50};
    int n=5;

    // for(int i=n/2;i>0;i--){
    //     heapify(arr, n, i);
    // }

    heapSort(arr, n);
    for(int i=1;i<=n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
//by ad73prem