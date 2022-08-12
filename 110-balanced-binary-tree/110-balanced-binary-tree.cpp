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
    bool ans;
    int f(TreeNode* root)
    {
        if(!root)   return 0;
        if(!ans)    return 0;
        int b=f(root->left);
        int a=f(root->right);
        if(abs(a-b)>1)
            ans=false;
        return 1+max(a,b);
    }
    bool isBalanced(TreeNode* root) {
        ans=true;
        int t=f(root);
        return ans;
    }
};