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

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// vector<int> rightSideView(TreeNode* root) {
//     map<int, map<int, multiset<int>>> nodes;
//     queue <pair<TreeNode*, pair<int,int>>> todo;
//     todo.push({root,{0,0}});
//     while(!todo.empty()){
//         auto p= todo.front();
//         TreeNode* node=p.first;
//         todo.pop();
//         int lvl= p.second.first;
//         int ver= p.second.second;
//         nodes[lvl][ver].insert(node->val);
//         if(node->left){
//             todo.push({node->left,{ lvl+1, ver-1}});
//         }
//         if(node->right){
//             todo.push({node->right,{ lvl+1, ver+1}});
//         }
//     }
//     vector<int> ans;
//     for(auto p:nodes){
//         auto it = prev(p.second.end());
//         int x= *(prev(it->second.end()));
//         ans.push_back(x);
//     }
//     return ans;
// }

vector<int> rightSideView(TreeNode *root)
{
    if(!root)return{};
    // normal level order traversal
    queue<TreeNode *> q;
    vector<vector<int>> ans;
    q.push(root);
    while (!q.empty())
    {
        int size = q.size();
        vector<int> lvl;

        for (int i = 0; i < size; i++)
        {
            TreeNode *node = q.front();
            q.pop();

            lvl.push_back(node->val);

            if (node->left != nullptr)
            {
                q.push(node->left);
            }
            if (node->right != nullptr)
            {
                q.push(node->right);
            }
        }
        ans.push_back(lvl);
    }
    vector<int> final;
    for (int i = 0; i < ans.size(); i++)
    {
        final.push_back(ans[i][ans[i].size() - 1]);
    }
    return final;
}
int main()
{
    FAST_IO;
    // TreeNode* root= new TreeNode(1);
    // root->left = new TreeNode(2);
    // root->right = new TreeNode(3);
    // root->left->left = new TreeNode(4);
    // root->left->right = new TreeNode(5);
    // root->left->right->left = new TreeNode(6);
    // root->right->right = new TreeNode(7);
    TreeNode *root = new TreeNode(0);
    root->left = new TreeNode(1);
    root->right = new TreeNode(2);
    root->left->right = new TreeNode(3);
    root->left->right->right = new TreeNode(5);
    root->left->right->right->right = new TreeNode(6);
    root->right->left = new TreeNode(4);
    root->right->left->left = new TreeNode(9);
    root->right->left->left->left = new TreeNode(10);
    vint ans = rightSideView(root);
    vprint(ans);
    return 0;
}
// by ad73prem