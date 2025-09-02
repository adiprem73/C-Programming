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


class MedianFinder {
public:
    priority_queue<int> mxHeap; //for the lower half of the array
    priority_queue<int, vector<int>, greater<int>> mnHeap; //for the larger half of the array
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(mxHeap.empty() || num<=mxHeap.top()){
            mxHeap.push(num);
        }
        else{
            mnHeap.push(num);
        }

        //rebalancing of sizes

        if(mxHeap.size()>mnHeap.size()+1){
            mnHeap.push(mxHeap.top());
            mxHeap.pop();
        }else if(mnHeap.size()>mxHeap.size()+1){
            mxHeap.push(mnHeap.top());
            mnHeap.pop();
        }
    }
    
    double findMedian() {
        if(mxHeap.size()==mnHeap.size()){ //even number of elements int he array right now
            return ((mxHeap.top()+mnHeap.top()) / 2.0);
        }else if(mxHeap.size()>mnHeap.size()){
            return mxHeap.top();
        }else{
            return mnHeap.top();
        }
    }
};

int main() {
    FAST_IO;
    
    return 0;
}
//by ad73prem