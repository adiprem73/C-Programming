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

struct Node{
    Node* links[26]; //referebce bode
    bool flag=false;

    bool containsKey(char ch){
        return links[ch-'a']!= NULL;
    }

    void put(char ch, Node* node){
        links[ch-'a']= node;
    }

    Node* get(char ch){
        return links[ch-'a'];
    }

    bool setEnd(){
        flag=true;
    }

    bool isEnd(){
        return flag;
    }
};

class Trie{
    private:
    Node* root;
    public:
    Trie(){
        root = new Node();
    }

    void insert(string word){
        Node* node=root;
        //dummy variable
        for(int i=0;i<word.length();i++){
            if(!node->containsKey(word[i])){
                node->put(word[i], new Node());
            }
            //moves to the reference trie
            node = node-> get(word[i]);
        }

        node->setEnd();
    }

    bool search(string word){
        Node* node= root;
        for(int i=0;i<word.length();i++){
            if(!node->containsKey(word[i])){
                return false;
            }
            node= node->get(word[i]);
        }
        return node->isEnd();
    }

    bool startswith(string prefix){
        Node* node = root;
        for(int i=0;i<prefix.length();i++){
            if(!node->containsKey(prefix[i])){
                return false;
            }
            node=node->get(prefix[i]);
        }
    }
};

int main() {
    FAST_IO;
    
    return 0;
}
//by ad73prem