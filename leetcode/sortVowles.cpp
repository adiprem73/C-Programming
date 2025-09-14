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

string sortVowels(string s)
{
    // since we only need to sort the vowels we can use counting sort or hashing
    string order="AEIOUaeiou";
    vector<int> hash(256, 0);

    for(char ch:s){
        if(order.find(ch)!= string::npos){
            hash[ch]++;
        }
    }

    int idx=0;
    for(int i=0;i<s.length();i++){
        if(order.find(s[i])!=string :: npos){
            while(hash[order[idx]]==0) idx++; // we move the idx ptr to the next vowel whos count is non zero in hash... now idx has the number of the next smallest vowel
            s[i]= order[idx];
            hash[order[idx]]--;

        }
    }
    return s;
}

int main()
{
    FAST_IO;
    
    return 0;
}
//by ad73prem