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

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr){} 
    TreeNode(int x) : val(x), left(nullptr), right(nullptr){}  
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right){}
};

bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    int n= matrix.size();
    if(!n)return false;
    int m= matrix[0].size();

    // now we need to perform binary search from 0 to m*n-1

    int s=0;
    int e=m*n-1;
    while(s<=e){
        int mid= s+(e-s)/2;

        int row= mid/m;
        int col= mid%m;

        int element = matrix[row][col];
        if(element == target)return true;
        else if(element <target){
            s=mid+1;
        }else {
            e=mid-1;
        }
    }
    return false;
    
}

int minSubArrayLen(int target, vector<int> &nums)
{
    int l=0;
    int r=0;
    int sum=0;
    int ans= INT_MAX;
    int n= nums.size();
    for(int r=0;r<n;r++){
        sum+=nums[r];

        while(sum>=target){
            ans= min(ans, r-l+1);
            sum-= nums[l];
            l++;
        }
    }

    return ans == INT_MAX ? 0: ans;
}

int getIndex(char ch){
    if(ch>='a' && ch<='z'){
        // cout<<"testt";
        return ch-'a';
    }
    if(ch>='A' && ch<='Z'){
        // cout<<"test";
        return ch-'A'+26;
    }
    return -1;
}

int longestPalindrome(string s)
{
    // mkaing the hash table
    vector<int> hash(52, 0);
    // transform(s.begin(), s.end(), s.begin(), ::tolower);
    for (char c : s)
    {
        hash[getIndex(c)]++;
    }
    int ans = 0;
    int mxOdd = -1;
    vector<int> odd;
    bool flag= false;
    for (auto freq : hash)
    {
        if (freq % 2 == 0)
        {
            ans += freq;
        }
        else
        {
            flag = true;
            ans+=freq-1;
        }
    }
    if(flag){
        ans++;
    }
    // if (mxOdd != -1)
    // {
    //     ans += mxOdd;
    // }
    return ans;
}

vector<int> findDisappearedNumbers(vector<int> &nums){
    int n= nums.size();
    vector<int> hash(n+1,0);
    // hash table is now ready
    for(int i: nums){
        hash[i]++;
    }
    vector<int> ans;
    for(int i=1;i<hash.size();i++){
        if(hash[i]==0){
            ans.push_back(i);
        }
    }
    return ans;
}

int findShortestSubArray(vector<int> &nums)
{
    unordered_map<int,int> freq;
    unordered_map<int,int> firstAppearance;
    unordered_map<int,int> lastAppearance;

    for(int i=0;i<nums.size();i++){
        int element = nums[i];
        freq[element]++;

        if(!firstAppearance.count(element)){
            firstAppearance[element]= i;
        }
        lastAppearance[element] = i;
    }
    int maxFreq=-1;
    for(auto it: freq){
        if(it.second> maxFreq){
            maxFreq= it.second;
        }
    }

    // for(auto it: freq){
    //     cout<<it.first<<" : "<<it.second<<endl;
    // }
    // cout<<"first appearances : "<<endl;
    // for (auto it : firstAppearance)
    // {
    //     cout << it.first << " : " << it.second << endl;
    // }
    // cout<<"last appearances : "<<endl;
    // for (auto it : lastAppearance)
    // {
    //     cout << it.first << " : " << it.second << endl;
    // }
    int ans=INT_MAX;
    for(int i=0;i<nums.size();i++){
        if(freq[nums[i]]== maxFreq){
            ans= min(ans, lastAppearance[nums[i]]- firstAppearance[nums[i]]+1);
        }
    }
    return ans;
}

string shortestCompletingWord(string licensePlate, vector<string> &words)
{
    transform(licensePlate.begin(), licensePlate.end(), licensePlate.begin(), ::tolower);

    cout<<licensePlate<<endl;
    vector<int> hash(26,0);
    for(char ch: licensePlate){
        if(ch>='a' && ch<='z'){
            hash[ch - 'a']++;
        }
        
    }
    cout<<"hello"<<endl;
    vector<string> possibleAns;
    for(int i=0;i<words.size();i++){
        vector<int> hashTemp(26,0);
        for(char ch: words[i]){
            hashTemp[ch-'a']++;
        }
        cout << "hello" << endl;

        bool flag= true;
        for(int i=0;i<26;i++){
            if(hash[i]>hashTemp[i]){
                flag= false;
                break;
            }
        }
        if(flag){
            possibleAns.push_back(words[i]);
        }
    }

    int shortestSize=INT_MAX;
    string ans;
    for(int i=0;i<possibleAns.size();i++){
        if(possibleAns[i].size()<shortestSize){
            shortestSize=possibleAns[i].size();
            ans= possibleAns[i];
        }
    }
    return ans;
}

// LEVEL ORDER TRAVERSAL OF A BINARY TREE

vector<vector<int>> levelOrder(TreeNode* root){
    vector<vector<int>> ans;
    if(root == nullptr){
        return ans;
    }

    queue<TreeNode*> q;
    q.push(root);

    while(!q.empty()){
        vector<int> level;
        int size= q.size();

        for(int i=0;i<size;i++){
            TreeNode* curr = q.front();
            q.pop();
            level.push_back(curr->val);

            if(curr->left != nullptr){
                q.push(curr->left);
            }
            if(curr->right != nullptr){
                q.push(curr->right);
            }
        }
        ans.push_back(level);
    }
    return ans;
}

int maxLevelSum(TreeNode* root){
    vector<vector<int>> levels= levelOrder(root);
    int maxSum= INT_MIN;
    // fingding the maximum sum
    for(auto it: levels){
        int sum=0;
        for(auto itr: it){
            sum+=itr;
        }
        maxSum= max(maxSum, sum);
    }

    int cnt=0;
    for (auto it : levels)
    {
        cnt++;
        int sum = 0;
        for (auto itr : it)
        {
            sum += itr;
        }
        if(sum== maxSum){
            return cnt;
        }
    }
    return 0;
}

// traversing through the bianry tree: post order traversal. 

void postOrderSum(TreeNode* root, long long &totalSum){
    if(root== nullptr)return;

    postOrderSum(root->left, totalSum);
    postOrderSum(root->right, totalSum);
    totalSum+=root->val;
}

long long maxSum(TreeNode* root, long long sum, long long totalSum, long long &ans){
    if(root == nullptr)return 0;
    long long leftSum= maxSum(root->left, sum, totalSum, ans);
    long long rightSum= maxSum(root->right, sum, totalSum, ans);
    sum=root->val + leftSum + rightSum;
    long long sum2= totalSum-sum;
    ans= max(ans, (sum*sum2));
    return sum;
}

int maxProduct(TreeNode *root)
{
    long long totalSum=0;
    postOrderSum(root, totalSum);
    long long sum=0;
    long long ans= LLONG_MIN;
    maxSum(root, sum, totalSum, ans);
    return (int)(ans%MOD);
}

int func(int k, vector<int>& dp){
    //base case
    if(k<=1)return 1;
    if(dp[k]!=-1)return dp[k];
    int ways=0;
    for(int i=1;i<=k;i++){
        ways+= func(i-1, dp)* func(k-i, dp);
    }
    return dp[k]= ways;
}

int numTrees(int n){
    vector<int> dp(n+1, -1);
    return func(n, dp);
}

TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
{
    // first thing to do is to map the inorder using a simple ahshmap
    map<int,int> inMap;
    for(int i=0;i<inorder.size();i++){
        inMap[inorder[i]]=i;
    }

    TreeNode *root = buildTree(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1, inMap);
    return root;
}

TreeNode* buildTree(vector<int> & preorder, int preStart, int preEnd, vector<int>& inorder, int inStart, int inEnd, map<int,int> inMap){
    if(preStart> preEnd || inStart > inEnd) return NULL;

    TreeNode* root = new TreeNode(preorder[preStart]);

    int inroot = inMap[root->val];

    int numsLeft = inroot- inStart;

    root->left= buildTree(preorder, preStart+1, preStart+ numsLeft , inorder, inStart, inroot-1, inMap);

    root->right= buildTree(preorder, preStart+ numsLeft+ 1, preEnd, inorder, inroot+1, inEnd, inMap);

    return root;
}

int findTime(int x1, int x2, int y1, int y2){
    int dx= abs(x1-x2);
    int dy= abs(y1-y2);

    return min(dx,dy) + abs(dx-dy);
}

int minTimeToVisitAllPoints(vector<vector<int>> &points)
{
    int n= points.size();
    int time=0;
    for(int i=0;i<n-1;i++){
        int x1= points[i][0];
        int y1= points[i][1];
        int x2= points[i+1][0];
        int y2= points[i+1][1];

        time+=findTime(x1, x2, y1, y2);
    }
    return time;
}


vector<double> findAreas(int x, int l, double line){
    int y= x+l;
    double areaAbove=0.0, areaBelow=0.0;
    if(line>y){ // this is the case wehre the line lies completely above the square
        areaBelow= l*l;
    }else if(line<x){
        areaAbove= l*l;
    }else{
        double h1= y-line;
        double h2= line-x;

        areaAbove= h1*l;
        areaBelow= h2*l;
    }

    return {areaAbove, areaBelow};
}

double separateSquares(vector<vector<int>> &squares)
{
    // the very first step will be to find the two bounds low and high

    double low=-INF;
    double high=INF;
    for(auto it: squares){
        low = min((double)it[0], low);
        high = max(double(it[0]+it[1]), high);
    }
}

int main()
{
    FAST_IO;
    // vector<vector<int>> nums={
    //     {1,3,5,7},
    //     {10,11,16,20},
    //     {23,30,34,60}
    // };

    // vector<int> vec = {2, 3, 1, 2, 4, 3};
    // cout<<minSubArrayLen(7, vec);

    // cout<<getIndex('A');
    // string s = "aaaAaaaa";
    // cout<<longestPalindrome(s);
        // cout << searchMatrix(nums, 4);

    // vint nums = {1, 2, 2, 3, 1, 4, 2};
    // cout<<findShortestSubArray(nums);

    // string licensePlate = "aBc 12c";
    // vector<string> words = {"step", "steps", "stripe", "stepple"};
    // cout<<shortestCompletingWord(licensePlate, words);

    // TreeNode* root= new TreeNode(1, nullptr, new TreeNode(2, new TreeNode(3), new TreeNode(4, new TreeNode(5), new TreeNode(6))));


    // vector<vector<int>> ans= levelOrder(root);
    // for(auto it: ans){
    //     vprint(it);
    // }
    // cout<<maxProduct(root);
    // cout<<maxLevelSum(root);

    cout<<numTrees(3);
    return 0;
}
//by ad73prem