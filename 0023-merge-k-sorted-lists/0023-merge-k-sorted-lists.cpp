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
    bool mycompon(ListNode* a,ListNode* b)
    {
        if(!a)
            return false;
        if(!b)
            return true;
        return a->val > b->val;
    }
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* ans=new ListNode();
        ListNode* sol=ans;
        priority_queue<ListNode*, vector<ListNode*>,decltype(&mycompon)> pq(mycompon);
        for(int i=0;i<lists.size();i++)
        {
            if(lists[i])
                pq.push(lists[i]);
            if(lists[i]&&lists[i]->next)
                lists[i]=lists[i]->next;
        }
        while(!pq.empty())
        {
            auto it=pq.top();
            pq.pop();
            ans->next=new ListNode(it->val);
            ans=ans->next;
            if(it->next)
            {
                pq.push({it->next});
            }
        }
        return sol->next;
    }
};