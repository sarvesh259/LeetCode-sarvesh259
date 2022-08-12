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
    int f(TreeNode* root,int lvl)
    {
        if(root->right==NULL&&root->left==NULL)
        {
            return lvl;
        }
        int a=1e9,b=1e9;
        if(root->left)
        {
            a=f(root->left,lvl+1);
        }
        if(root->right)
        {
            b=f(root->right,lvl+1);
        }
        return min(a,b);
    }
    int minDepth(TreeNode* root) {
        if(root==NULL)
            return 0;
        return f(root,1);
    }
};