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

void merge(int *arr, int s, int e){
    int mid=(s+e)/2;
    int len1=mid-s+1;
    int len2=e-mid;

    //divide the array into two

    int *first=new int[len1];
    int *second=new int[len2];

    int mainArrayIndex=s;
    for(int i=0;i<len1;i++){
        first[i]=arr[mainArrayIndex++];
    }

    mainArrayIndex=mid+1;
    for(int i=0;i<len2;i++){
        second[i]=arr[mainArrayIndex++];
    }

    //merge two sorted arrays
    int index1=0;
    int index2=0;
    mainArrayIndex=s;
    while(index1<len1&&index2<len2){
        if(first[index1]<second[index2]){
            arr[mainArrayIndex++]=first[index1++];
        }
        else{
            arr[mainArrayIndex++]=second[index2++];
        }
    }

    while(index1<len1){
        arr[mainArrayIndex++]=first[index1++];
    }

    while(index2<len2){
        arr[mainArrayIndex++]=second[index2++];
    }

    delete []first;
    delete []second;

}

void mergeSort(int *arr, int s, int e){
    //base case
    if(s>=e){
        return;
    }
    int mid=(s+e)/2;

    mergeSort(arr,s,mid);
    mergeSort(arr,mid+1,e);

    merge(arr,s,e);
}

int main() {
    FAST_IO;
    int arr[8]={1,5,2,7,4,9,3,0};
    mergeSort(arr, 0,7);

    for(int i=0;i<8;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
//by ad73prem