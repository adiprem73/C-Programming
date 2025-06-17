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

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void preorderTraversalHelper(TreeNode* root, vector<int> &nums){
    if(root==nullptr){
        return;
    }
    nums.push_back(root->val);
    preorderTraversalHelper(root->left, nums);
    preorderTraversalHelper(root->right, nums);
}

vector<int> preorderTraversal(TreeNode* root) {
    vector<int> nums;
    preorderTraversalHelper(root, nums);
    return nums;
}

int main() {
    FAST_IO;
    struct TreeNode* root=new TreeNode(1);
    root->right= new TreeNode(2);
    root->right->left= new TreeNode(3);
    vprint(preorderTraversal(root));
    return 0;
}
//by ad73prem