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


// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

Node *cloneGraph(Node *node)
{
    if(!node) return nullptr;
    // lets use bfs to traverse through the graph
    queue<Node*> q;
    unordered_map<Node*, bool> visit;
    unordered_map<Node*, Node*> copied; // this map accounts which node has alreayd been cloned so that we dont clone it twice
    Node* clone= new Node(node->val);
    copied[node]=clone;
    q.push(node);
    visit[node]=1;
    while(!q.empty()){
        auto it = q.front();
        auto clone_it= copied[it];
        q.pop();
        // cout<<"node : "<<it->val<<endl;
        auto nit= it->neighbors;
        // cout<<"neighbourse : "<<endl;
        for(auto iter: nit){
            // cout << iter->val << endl;

            // cretae the new neighbour node
            if (copied.find(iter) == copied.end())
            {
                Node *neighbour = new Node(iter->val);
                copied[iter]= neighbour;
                clone_it->neighbors.push_back(neighbour);
            }
            else
            {
                clone_it->neighbors.push_back(copied[iter]);
            }

            if (!visit.count(iter))
            {                
                visit[iter]=1;
                q.push(iter);
            }
        }
    }
    return clone;
}

int main()
{
    FAST_IO;
    
    return 0;
}
//by ad73prem