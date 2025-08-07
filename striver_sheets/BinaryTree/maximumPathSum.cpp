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

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

int findMaxPath(TreeNode* root, int& maxPath){
    if(root==NULL)return 0;
    int leftsum= max(0,findMaxPath(root->left, maxPath));
    int rightsum= max(0,findMaxPath(root->right, maxPath));
    maxPath= max(maxPath, leftsum+rightsum+root->val);
    return (root->val) + max(leftsum, rightsum);
}


int maxPathSum(TreeNode* root) {
    int maxPath=INT_MIN;
    findMaxPath(root, maxPath);
    return maxPath;
}

int main() {
    FAST_IO;
    TreeNode* root=new TreeNode(-10);
    root->left= new TreeNode(9);
    root->right =  new TreeNode(20);
    root->right->left= new TreeNode(15);
    root->right->right = new TreeNode(7);
    cout<<maxPathSum(root);
    
    
    return 0;
}
//by ad73prem