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

vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
    unordered_set<string> st(wordList.begin(),wordList.end());
    queue<vector<string>> q;
    q.push({beginWord});
    vector<string> usedOnLevel;
    usedOnLevel.push_back(beginWord);
    int level=0;
    vector<vector<string>> ans;

    while(!q.empty()){
        vector<string> vec=q.front();
        q.pop();

        //erase all words that has been used in the previous levels to transform
        if(vec.size() > level){
            level++;
            for(auto it: usedOnLevel){
                st.erase(it);
            }
            usedOnLevel.clear();
        }

        string word=vec.back();
        if(word==endWord){
            if(ans.size()==0){
                ans.push_back(vec);
            }
            else if(ans[0].size()==vec.size()){
                ans.push_back(vec);
            }
        }
        for(int i=0;i<word.size();i++){
            char original = word[i];
            for(char c='a';c<='z';c++){
                word[i]=c;
                if(st.count(word)>0){
                    vec.push_back(word);
                    q.push(vec);
                    usedOnLevel.push_back(word);
                    vec.pop_back();
                }

            }
            word[i] = original;
        }
    }
    return ans;
}

int main() {
    FAST_IO;
    
    return 0;
}
//by ad73prem