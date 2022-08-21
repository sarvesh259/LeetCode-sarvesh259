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
    int f(TreeNode* root,int* lvl)
    {
        if(root==NULL)
            return 0;
        int a=f(root->left,lvl);
        int b=f(root->right,lvl);
        if(a+b>*lvl)
            *lvl=a+b;
        return 1+max(a,b);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL)
            return 0;
        int lvl=0;
        int t= f(root,&lvl);
        return lvl;
    }
};