/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* findmid(ListNode* head)
{
    ListNode* s=head;
        ListNode* f=head;
    while(f)
    {
        s=s->next;
        f=f->next;
        if(f)
            f=f->next;
    }
    return s;
}
ListNode* rev(ListNode* head)
{
    ListNode*prev=NULL,*curr=head,*temp=NULL;
    while(curr!=NULL){
        temp=curr->next;
        curr->next=prev;
        prev=curr;
        curr=temp;
    }
    return prev;
}
    bool isPalindrome(ListNode* head) {
        ListNode* begin=head;
        ListNode* mid=findmid(head);
        ListNode* revi=rev(mid);
        while(head!=NULL&&revi!=NULL)
        {
            if(head->val!=revi->val)
                return false;
            head=head->next;
            revi=revi->next;
        }
        return true;
    }
};