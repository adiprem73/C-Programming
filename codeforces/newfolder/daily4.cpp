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

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr){}  
    ListNode(int x) : val(x), next(nullptr){}  
    ListNode(int x, ListNode *next) : val(x), next(next){}
                                                                                                                                      
};

ListNode* modifiedList(vector<int>& nums, ListNode* head) {

    unordered_set<int> st(nums.begin(), nums.end());
    while (st.count(head->val))
    {
        ListNode* temp2= head;
        head=head->next;
        temp2->next=nullptr;
    }
    ListNode *temp = head;
    
    while(temp->next){
        int value= temp->next->val;
        if(st.count(value)){
            ListNode* temp3= temp->next; // this is the node that is to be deleted
            temp->next= temp->next->next; // skipped over the to be deleted node
            delete temp3;
        }else{
            temp=temp->next;
        }   
    }
    cout << "hello" << endl;
    return head;
}

void printList(ListNode* head) {
    ListNode* cur = head;
    while (cur) {
        cout << cur->val;
        if (cur->next) cout << " ";
        cur = cur->next;
    }
    cout << '\n';
}

int main() {
    FAST_IO;
    vint nums= {1};
    ListNode* head= new ListNode(1);
    head->next= new ListNode(2);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(2);
    head->next->next->next->next = new ListNode(1);
    head->next->next->next->next->next = new ListNode(2);
    printList(head);
    
    ListNode* result = modifiedList(nums, head);
    // cout << "hello" << endl;
    printList(result);
    return 0;
}
//by ad73prem