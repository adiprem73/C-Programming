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

void inorderHelper(TreeNode* root, vector<int> &nums){
    if(root==NULL){
        return;
    }

    inorderHelper(root->left, nums);
    nums.push_back(root->val);
    inorderHelper(root->right,nums);
}

vector<int> inorderTraversal(TreeNode* root) {
    vector<int> nums;
    inorderHelper(root, nums);
    return nums;
}

int main() {
    FAST_IO;
    struct TreeNode* root= new TreeNode(1);
    root->left= new TreeNode(2);
    root->right= new TreeNode(3);
    root->left->left= new TreeNode(4);
    root->left->right= new TreeNode(5);
    root->right->right= new TreeNode(8);
    root->left->right->left= new TreeNode(6);
    root->left->right->left= new TreeNode(7);
    root->right->right->left= new TreeNode(9);
    vprint(inorderTraversal(root));
    return 0;
}
//by ad73prem