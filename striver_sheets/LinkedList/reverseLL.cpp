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
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* reverseList(ListNode* head) {
    ListNode* rev=new ListNode(head->val);
    while(head->next!=nullptr){
        ListNode* copy= new ListNode(head->next->val);
        copy->next=rev;
        rev=copy;
        head=head->next;
    }
    //printing of reverse:
    ListNode* pr=rev;
    while(pr!=nullptr){
        cout<<pr->val<<" -> ";
        pr=pr->next;
    }
    return rev;
}

ListNode* reverselist(ListNode* head){
    ListNode* prev= nullptr;
    ListNode* curr= head;

    while(curr!=nullptr){
        ListNode* nextnode = curr->next;//saving this before only 
        
    }
}

int main() {
    FAST_IO;
    ListNode *head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));
    reverseList(head);
    return 0;
}
//by ad73prem