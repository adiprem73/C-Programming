#include<bits/stdc++.h>
using namespace std;

#define ll long long
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

vector<string> fizzBuzz(int n) {
    vector<string> answer(n);
    for(int i=0;i<n;i++){
        if((i+1)%3==0 && (i+1)%5==0){
            answer[i]=="FizzBuzz";;
        }
        else if((i+1)%3==0){
            answer[i]="Fizz";
        }
        else if((i+1)%5==0){
            answer[i]="Buzz";
        }
        else{
            answer[i]=to_string(i+1);
        }
    }
    return answer;
}

int main() {
    FAST_IO;
    
    return 0;
}
//by ad73prem