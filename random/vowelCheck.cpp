#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define f(i, a, b) for (int i = a; i < b; i++)
#define all(x) x.begin(), x.end()
#define vprint(v)            \
    for (auto &elem : v)     \
        cout << elem << " "; \
    cout << endl;
#define mprint(m)                                       \
    for (auto it : m)                                   \
        cout << it.first << " : " << it.second << endl; \
    cout << endl;
#define vint vector<int>
#define vstring vector<string>
#define vmat vector<vector<int>>
#define FAST_IO                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define pii pair<int, int>
#define pll pair<ll, ll>
#define mii map<int, int>
#define mll map<ll, ll>

const int INF = 1e9;
const ll MOD = 1e9 + 7;

bool check1(vector<string> queries, string str){
    for(char ch: str){
        ch=tolower(ch);
    }
    for (string s : queries)
    {
        for (char ch : s)
        {
            ch = tolower(ch);
        }
    }
    for(string s: queries){
        if(find(queries.begin(), queries.end(), str)!= queries.end()){
            return true;
        }
    }
    return false;
}

bool compareStrings(string s1, string s2){
    if(s1.size()!= s2.size())return false;
    for(int i=0;i<s1.size();i++){
        if(tolower(s1[i])!= tolower(s2[i]))return false;
    }
    return true;
}

bool compareStringVowels(string s1, string s2){
    if (s1.size() != s2.size())
        return false;
    for (int i = 0; i < s1.size(); i++)
    {
        if ()
            return false;
    }
    return true;
}

vector<string> spellchecker(vector<string> &wordlist, vector<string> &queries)
{
    vector<string> ans;
    
    for(string query : queries){
        if(find(queries.begin(), queries.end(), query)!=queries.end()){
            ans.push_back(query);
        }
        else {
            bool flag=false;
            for(string s : wordlist){
                if(compareStrings(s, query)){
                    ans.push_back(s);
                    flag=true;
                    break;
                }
            }
            if(flag==true){
                continue;
            }


        }


    }
}

int main()
{
    FAST_IO;
    cout<<compareStrings("Aditya", "aDitYA");
    return 0;
}
// by ad73prem