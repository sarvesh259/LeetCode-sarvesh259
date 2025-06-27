/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        queue<TreeNode*> q;
        if(root) q.push(root);
        while(!q.empty())
        {
            TreeNode* right=nullptr;
            int sz=q.size();
            for(int i=0;i<sz;i++)
            {
                TreeNode* temp= q.front();
                q.pop();
                if(temp!=NULL)
                {
                    right=temp;
                    if(temp->left)
                    q.push(temp->left);
                    if(temp->right)
                    q.push(temp->right);
                }
            }
            if(right)
            ans.push_back(right->val);
        }  
        return ans;
    }
};