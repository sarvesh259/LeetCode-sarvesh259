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
    TreeNode* makeBST(vector<int> &inorder,int i,int j)
    {
        if(i>j)
            return NULL;
        int mid=i+((j-i)>>1);
        TreeNode* node= new TreeNode(inorder[mid]);
        node->left=makeBST(inorder,i,mid-1);
        node->right=makeBST(inorder,mid+1,j);
        return node;
    }
    
    void inordera(TreeNode* root, vector<int> &inorder)
    {
        if(!root)
            return;
        inordera(root->left,inorder);
        inorder.push_back(root->val);
        inordera(root->right,inorder);
        
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> inorder;
        inordera(root,inorder);
        return makeBST(inorder,0,inorder.size()-1);
    }
};