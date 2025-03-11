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

vector<int> insertionSort(vector<int> arr){
    int n=arr.size();
    for(int i=1;i<n;i++){   //rounds 1 to n
        int temp=arr[i];
        int j=i-1;   //so that it can be used in the outer loop as well
        for(;j>=0;j--){
            if(arr[j]>temp){    //agar ye condition hota hai to hi shifting karna hota hai
                arr[j+1]=arr[j];   //shifting 
            }
            else{
                break;
            }
        }
        arr[j+1]=temp;
    }
    return arr;
}

int main() {
    FAST_IO;
    vint v={1,4,2,9,6,0,4};
    vint sv=insertionSort(v);
    vprint(sv);
    return 0;
}
//by ad73prem