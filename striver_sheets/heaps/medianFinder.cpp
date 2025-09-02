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
    multiset<int> st;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        st.insert(num);
    }
    
    double findMedian() {
        int n=st.size();
        if(n%2!=0){  //odd number of elements
            int x=n/2;
            auto it=st.begin();
            advance(it, x);
            return *it;
        }
        else{
            int x=n/2;
            int y=x-1;
            auto it= st.begin();
            advance(it, x);
            auto it1= st.begin();
            advance(it1, y);
            double ans= ((*it)+(*it1))/2.0;
            return ans;
        }
    }   
};

int main() {
    FAST_IO;
    MedianFinder* mf= new MedianFinder();
    mf->addNum(1);
    mf->addNum(2);
    cout<<mf->findMedian()<<endl;
    mf->addNum(3);
    cout<<mf->findMedian()<<endl;
    return 0;
}
//by ad73prem