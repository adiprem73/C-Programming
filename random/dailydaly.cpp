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

int countPalindromicSubsequence(string s) {
    vector<int> hash(26);
    int n= s.length();

    for(char ch:s){
        hash[ch-97]++;
    }

    int count=0;

    for(int i=0;i<26;i++){
        if(hash[i]>=2){
            char ch= (char)(i+97);

            int start=0;
            int end=n-1;

            while(start<n){
                if(s[start]==ch){
                    break;
                }
                start++;
            }

            while(end>=0){
                if(s[end]==ch){
                    break;
                }
                end--;
            }

            unordered_set<char> st;
            for(int j=start+1;j<end;j++){
                if(st.count(s[j])==0){
                    st.insert(s[j]);
                    count++;
                }
            }
        }
    }
    return count;
}

int main() {
    FAST_IO;
    
    return 0;
}
//by ad73prem