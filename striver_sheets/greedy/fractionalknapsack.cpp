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

bool comp(pair<int,int>&p1, pair<int,int>&p2){
    double a= (double)p1.first/p1.second;
    double b= (double)p2.first/ p2.second;
    return a>b;
}

double fractionalKnapsack(vector<pair<int,int>> &items, int w){
    sort(items.begin(), items.end(), comp);
    //soritng based on fracitnal done
    double ans=0;
    for(int i=0;i<items.size();i++){
        if(items[i].second<=w){
            ans+=items[i].first;
            w-=items[i].second;
        }else{
            ans+=((double)items[i].first/items[i].second)*w;
            break;
        }
    }
    return ans;
}

int main() {
    FAST_IO;
    vector<pair<int,int>> item={{100, 20},{60,10},{100,50},{200, 50}};
    fractionalKnapsack(item , 90);
    return 0;
}
//by ad73prem