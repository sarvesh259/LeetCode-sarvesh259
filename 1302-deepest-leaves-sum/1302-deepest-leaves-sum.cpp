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
    void f(TreeNode* root,map<int,int>& a,int lvl)
    {     
        a[lvl]+=root->val;
        if(root->left!=NULL)
        {
            f(root->left,a,lvl+1);
        }
        if(root->right!=NULL)
        {
            f(root->right,a,lvl+1);
        }
        return;
    }
    int deepestLeavesSum(TreeNode* root) {
        map<int,int> a;
        f(root,a,0);
        return a[a.size()-1];
    }
};