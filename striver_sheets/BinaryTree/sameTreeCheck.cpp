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

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(): val(0), left(nullptr), right(nullptr){}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right){}
};

bool isSameTree(TreeNode* p, TreeNode* q){
    if(p==NULL && q==NULL)return true; //both null
    if(p==NULL && q!=NULL)return false; //only one null
    if(p!=NULL && q==NULL)return false;

    if(p->val!=q->val)return false;//comparing values

    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}

int main() {
    FAST_IO;
    TreeNode* p=new TreeNode(1);
    p->left= new TreeNode(2);
    p->right= new TreeNode(3);
    TreeNode* q=new TreeNode(1);
    q->left= new TreeNode(2);
    q->right= new TreeNode(13);
    cout<<isSameTree(p,q);
    return 0;
}
//by ad73prem