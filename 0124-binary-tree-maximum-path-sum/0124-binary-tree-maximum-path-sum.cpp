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
    int findMaxSum(TreeNode* root,int &cur)
    {
        if(!root) return 0;
        int left=max(findMaxSum(root->left,cur),0);
        int right=max(findMaxSum(root->right,cur),0);
        cur=max(cur,left+right+root->val);
        return max(right+root->val,left+root->val);
    }
    int maxPathSum(TreeNode* root) {
        int mx=-1e9;
        findMaxSum(root,mx);
        return mx; 
    }
};