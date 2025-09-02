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

int leastInterval(vector<char>& tasks, int n) {
    map<char,int> mp;
    for(auto it: tasks){
        mp[it]++;
    }

    priority_queue<pair<int, char>> pq;
    for(auto it: mp){
        pq.push({it.second, it.first});
    }
    int cnt=0;

    while(!pq.empty()){
        vector<pair<int, char>> temp;  //this stores the pairs which still ahe freq left so that we can push them back in the pq after the cycle completes
        int cycle=n+1; //if n=2, then three tasks can be schedules inside the sma ecycle since this way the distance bwteen two same tasks will be atleast 2

        while(cycle>0 && !pq.empty()){
            auto it= pq.top(); 
            pq.pop();

            cnt++; 
            it.first--;

            if(it.first>0) temp.push_back(it);

            cycle--;
        }

        for(auto t: temp)pq.push(t); //here we push the elements of the temp back into the pq

        if (!pq.empty())cnt+=cycle;
    }
    return cnt;
    
}

int main() {
    FAST_IO;
    vector<char> ch={'A','A','A','B','B','B'};
    cout<<leastInterval(ch, 2);
    return 0;
}
//by ad73prem