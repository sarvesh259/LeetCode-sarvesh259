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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode *x=head, *y=head, *t=head;

        while(k>1){
            x = x->next;
            t = t->next;
            k--;
        }

        while(t->next){
            y=y->next;
            t=t->next;
        }

        int temp = x->val;
        x->val = y->val;
        y->val = temp;

        return head;
    }
};