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
    int f(TreeNode* root,long targetSum)
    {
        if(!root) return 0;
        long ans=0;
        if(targetSum==root->val)
            ans++;
        ans+=f(root->left,targetSum-root->val);
        ans+=f(root->right,targetSum-root->val);
        return ans;
    }
    int pathSum(TreeNode* root, int targetSum) {
        if(!root)
            return 0;
        int ans=0;
        ans+=pathSum(root->left,targetSum);
        // ans+=pathSum(root->left,targetSum-(root->val));
        ans+=pathSum(root->right,targetSum);
        // ans+=pathSum(root->right,targetSum-(root->val));
        ans+=f(root,targetSum);
        return ans;
    }
};