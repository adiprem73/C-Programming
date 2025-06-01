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

int minimumSum(int num) {
    string s=to_string(num);
    vector<char> digits;
    digits.push_back(s[0]);
    digits.push_back(s[1]);
    digits.push_back(s[2]);
    digits.push_back(s[3]);
    sort(digits.begin(),digits.end());
    int count;
    for(int i=0;i<4;i++){
        if(digits[i]=='0'){
            count++;
        }
    }
    if(count==3){
        return digits[3]-'0';
    }
    else if(count==2){
        return (digits[2]-'0')+(digits[3]-'0');
    }
    else if(count==1){
        int a=digits[1]-'0';
        int b=digits[2]-'0';
        int c=digits[3]-'0';
        return min(min((10*a+b)+c, (10*b+c)+a), (10*c+a)+b);
    }
    else {
        int a=digits[0]-'0';
        int b=digits[1]-'0';
        int c=digits[2]-'0';
        int d=digits[3]-'0';
        return min(a*10+c+b*10+d , a*10+d+b*10+c);
    }

}

int main() {
    FAST_IO;
    int n;
    cin>>n;
    cout<<minimumSum(n);
    return 0;
}
//by ad73prem