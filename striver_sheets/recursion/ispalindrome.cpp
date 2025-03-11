#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define push(a) push_back(a)
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

bool isPalindrome(string s) {
    int left=0;
    int right=s.length()-1;
    while(left<right){
        // cout<<left<<" "<<right<<endl;
        while((left<right)&& !isalnum(s[left])){
            left++;
        }
        while((left<right)&& !isalnum(s[right])){
            right--;
        }
        if(tolower(s[left])!=tolower(s[right])){
            cout<<"sleft : "<<s[left]<<"  sright : "<<s[right];
            return false;

        }
        left++;
        right--;
    }
    return true;
}

int main() {
    FAST_IO;
    string s="A man, a plan, a canal: Panama";
    cout<<isPalindrome(s);
    return 0;
}
//by ad73prem