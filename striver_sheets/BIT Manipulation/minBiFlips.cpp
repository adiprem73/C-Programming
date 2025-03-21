#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define push(a) push_back(a)
#define f(i, a, b) for(int i=a;i<b;i++)
#define all(x) x.begin(),x.end()
#define vprint(v) for (auto& elem : v) cout << elem << " "; cout << endl;
#define vmatprint(vv) for (auto& row : vv) { for (auto& elem : row) cout << elem << " "; cout << endl; } cout << endl;
#define mprint(m) for (auto it : m) cout << it.first << " : " << it.second << endl; cout << endl;
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

string toBinary(int n){
    string s="";
    while(n>0){
        int x=n%2;
        n/=2;
        s+=to_string(x);
    }
    reverse(s.begin(),s.end());
    return s;
}

string addLeadingZeroes(string binary,int n){
    while(binary.length()!=n){
        binary="0"+binary;
    }
    return binary;
}

int minBitFlips(int start, int goal) {
    string binStart=toBinary(start);
    string binGoal=toBinary(goal);
    int startLen=binStart.length();
    int goalLen=binGoal.length();

    if(startLen<goalLen){
        binStart=addLeadingZeroes(binStart,binGoal.length());

    }
    else{
        binGoal=addLeadingZeroes(binGoal, binStart.length());
    }
    // cout<<binStart<<endl;
    // cout<<binGoal<<endl;
    int count=0;
    for(int i=0;i<binGoal.length();i++){
        if(binGoal[i]!=binStart[i]){
            count++;
        }
    }
    return count;
}

int main() {
    FAST_IO;
    string s ="111";
    // cout<<addLeadingZeroes(s,5)<<endl;
    cout<<minBitFlips(10,7);
    return 0;
}
//by ad73prem