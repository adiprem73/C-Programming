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

void func(string& s, int ind, vector<string> &path, vector<vector<string>> &res){

    //this is the base case: once we reacht the end of the sting that means that all the partition upto that point were indeed pallindrome and hence ww can push it inside the res
    if(ind==s.length()){
        res.push_back(path);
        return ;
    }

    for(int i=ind;i<s.length();i++){
        if(palindromeCheck(s, ind, i)){
            path.push_back(s.substr(ind, i-ind+1));
            func(s, i+1, path, res);
            path.pop_back();
        }
    }
}

bool palindromeCheck(string s, int start, int end){
    while(start<end){
        if(s[start++]!=s[end--]){
            return false;
        }
    }return true;
}

vector<vector<string>> partition(string& s)
{
    vector<vector<string>> res;
    vector<string> path;

    func(s, 0, path, res);
    return res;

}

int main() {
    FAST_IO;
    
    return 0;
}
//by ad73prem