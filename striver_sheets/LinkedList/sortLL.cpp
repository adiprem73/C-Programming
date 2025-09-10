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
    ListNode(int x) : val(x), next(NULL) {}
};


//our best bet would be to choose a sorting technique and then apply it to linked lists
ListNode *sortList(ListNode *head)
{
    //selection sorting :  choose an index, find the smallest number in the restof the array and then swap it witht he current index
    ListNode* temp=head;
    while(temp){
        ListNode* temp2= temp;
        ListNode* smallest =temp;
        while(temp2){
            if(smallest->val>temp2->val){
                smallest= temp2;
            }
            //here we would want to swpa the two listnodes
            
            
            temp2=temp2->next;
        }
        int x = smallest->val;
        smallest->val = temp->val;
        temp->val = x;
        temp=temp->next;
    }
    return head;

}

int main()
{
    FAST_IO;
    ListNode *head = new ListNode(4);
    head->next = new ListNode(2);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(3);
    // head->next->next->next->next = new ListNode(34);
    ListNode *ans = sortList(head);
    while(head){
        cout<<head->val<<"-->";
        head=head->next;
    }
}
//by ad73prem