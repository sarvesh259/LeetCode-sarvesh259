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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(!head)
            return head;
        ListNode* ans=head;
        while(head->next)
        {
            ListNode* temp=head->next;
            head->next=new ListNode(__gcd(head->val,head->next->val));
            head->next->next=temp;
            head=temp;
        }
        return ans;
    }
};