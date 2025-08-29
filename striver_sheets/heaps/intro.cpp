#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define f(i, a, b) for (int i = a; i < b; i++)
#define all(x) x.begin(), x.end()
#define vprint(v)            \
    for (auto &elem : v)     \
        cout << elem << " "; \
    cout << endl;
#define mprint(m)                                       \
    for (auto it : m)                                   \
        cout << it.first << " : " << it.second << endl; \
    cout << endl;
#define vint vector<int>
#define vstring vector<string>
#define vmat vector<vector<int>>
#define FAST_IO                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define pii pair<int, int>
#define pll pair<ll, ll>
#define mii map<int, int>
#define mll map<ll, ll>

const int INF = 1e9;
const ll MOD = 1e9 + 7;

class heap
{
public:
    int arr[100];
    int size = 0;

    heap()
    {
        arr[0] = -1;
        size = 0;
    }
    void insert(int val)
    {
        size = size + 1;
        int index = size;
        arr[index] = val;
        while (index > 1)
        {
            int parentIndex = index / 2;
            if (arr[parentIndex] <= arr[index])
            {
                swap(arr[parentIndex], arr[index]);
            }
            else
            {
                return;
            }
        }
    }

    void print()
    {
        for (int i = 1; i <= size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    void deletefromHeap()
    {
        if (size == 0)
        {
            cout << "Nothing to dlete" << endl;
            return;
        }
        //step 1: to take the last element and put it into the place of the root element
        arr[1]= arr[size];

        //step 2: reduce the size of the heap
        size--;


        //step 3: rearrange the elements into the natural order
        int i=1;
        while(i<size){
            int leftindex= 2*i;
            int rightindex= 2*i+1;

            if(leftindex<size && arr[i]<arr[leftindex]){
                
            }
        }
    }
};

void heapify(int arr[], int n, int i){
    int largest=i; //the number to be heapified
    int left= 2*i;
    int right= 2*1+1;

    if(left<n && arr[largest]<arr[left]){
        largest=left;
    }
    if(right<n && arr[largest]<arr[right]){
        largest=right;
    }

    if(largest != i){
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}

int main()
{
    FAST_IO;
    heap h;
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);
    h.print();

    int arr[6]={-1, 54, 53, 55, 57, 50};
    int n=5;
    for(int i=n/2; i>0 ; i--){
        heapify(arr, n, i);
    }
    for (int i = 1; i <= n; i++)
    {
        cout<<arr[i]<<" ";
    }
    
    return 0;
}
// by ad73prem