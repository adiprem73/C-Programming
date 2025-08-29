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

class Solution{
    public:
        vector<int> arr;
        int size=0;


        void heapify(vector<int>& arr, int n, int i){
            int smallest=i;
            int left=2*i;
            int right=2*i+1;

            if(left<n && arr[smallest]>arr[left]){
                smallest=left;
            }
            if(right<n && arr[smallest]>arr[right]){
                smallest=right;
            }

            if(smallest!=i){
                swap(arr[smallest], arr[i]);
                heapify(arr, n, smallest);
            }
        }

        void initializeHeap(){
            arr.clear(); //empty the heap
            arr.push_back(-1);  //dummy value at 0 iondex so that it becomes 1 indexed
            size=0;
        }

        void insert(int key){
            size=size+1;
            int index=size;
            arr[index]=key;
            while(index>1){
                int parentIndex= index/2;
                if(arr[parentIndex]>arr[index]){
                    swap(arr[parentIndex], arr[index]);
                    index=parentIndex;
                }
                else{
                    return;
                }
            }
        }

        void changeKey(int index, int new_val){
            if(new_val<arr[index+1]){
                //bubble upwards
                for(int i=index;i>0;i--){
                    heapify(arr, n, i);
                }
            }
            else if(new_val>arr[index+1]){
                //bubble downwards
                for(int i=index; i<=size;i++){
                    heapify(arr, n, i);
                }
            }
            else{
                return ;
            }
        }


        void extractMin(){
            if(size==0){
                return;
            }

            //take last element to the root
            arr[1]= arr[size];

            size--;

            heapify(arr, size, 1);
        }

        bool isEmpty(){
            if(size==0)return true;
            return false;
        }

        int getMin(){
            if(size==0)return -1;

            return arr[1];
        }

        int heapSize(){
            return size;
        }
};

int main() {
    FAST_IO;
    
    return 0;
}
//by ad73prem