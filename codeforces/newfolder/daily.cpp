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



    int numberOfBeams(vector<string> &bank)
    {
        vector<int> devices;
        for (string s : bank)
        {
            int cnt = 0;
            for (char ch : s)
            {
                if (ch == '1')
                {
                    cnt++;
                }
            }
            devices.push_back(cnt);
        }
        // vprint(devices);
        int ind=-1;
        for(int i=0;i<devices.size();i++){
            if(devices[i]!=0){
                ind=i;
                break;
            }
        }
        // cout<<i<<endl;
        if (ind == -1)
        {
            return 0;
        }
        int count = 0;
        int current = devices[ind];
        ind++;
        // cout<<current<<endl;
        // cout << "hello" << endl;

        while (ind < devices.size())
        {
            if (devices[ind] == 0)
            {
            }
            else
            {
                count += devices[ind] * current;
                current = devices[ind];
            }
            // cout<<"count : "<<count<<endl;
            ind++;
        }
        return count;
    }


int main() {
    FAST_IO;
    vector<string> vec = {"000", "111", "000"};
    cout<<numberOfBeams(vec);
     return 0;
}
//by ad73prem