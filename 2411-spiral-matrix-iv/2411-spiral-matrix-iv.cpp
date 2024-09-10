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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> ans(m,vector<int>(n,-1));
        int left=0,right=n-1,up=0,down=m-1;
        while(head!=NULL)
        {
            for(int i=left;i<=right&&head!=NULL;i++)
            {
                ans[up][i]=head->val;
                head=head->next;
            }
            up++;
            for(int i=up;i<=down&&head!=NULL;i++)
            {
                ans[i][right]=head->val;
                head=head->next;
            }
            right--;
            for(int i=right;i>=left&&head!=NULL;i--)
            {
                ans[down][i]=head->val;
                head=head->next;
            }
            down--;
            for(int i=down;i>=up&&head!=NULL;i--)
            {
                ans[i][left]=head->val;
                head=head->next;
            }
            left++;
        }
        return ans;
    }
};