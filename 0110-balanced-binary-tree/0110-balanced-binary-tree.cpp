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
    bool flag=true;
    int ans(TreeNode* root)
    {
        if(!root || !flag) return 0;
        int left=ans(root->left);
        int right=ans(root->right);
        if(abs(left-right)>1){
            flag=false;
            return 0;
        }
        return 1+max(left,right);
    }
    bool isBalanced(TreeNode* root) {
        int temp=ans(root);
        return flag;
    }
};